param(
    [string]$DevkitProRoot,
    [string]$ExlaunchSource,
    [int]$Jobs = 8,
    [switch]$UseDocker,
    [string]$DockerImage = "devkitpro/devkita64@sha256:1fc388c3a0d34bd2045a6dadcb1020e069d5f876a187fd705de14b4440c00282"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest
$RepoRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$ProgramId = "010028600EBDA000"
$PinnedExlaunchCommit = "f698816d6e198afb0029ad5c07d55e7017a620fe"
$Version = (Get-Content -Raw -LiteralPath (Join-Path $RepoRoot "VERSION")).Trim()
$ArtifactRoot = Join-Path $RepoRoot "artifacts"
$WorkRoot = Join-Path $ArtifactRoot "build-work\exlaunch"
$OutputRoot = Join-Path $ArtifactRoot "build"
$LogPath = Join-Path $OutputRoot "build.log"
$ReleaseAsFlags = "-g0 -march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIC -fvisibility=hidden"

function Invoke-Checked { param([string]$FilePath, [string[]]$Arguments)
    $previousPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = "Continue"
        & $FilePath @Arguments 2>&1 | Tee-Object -FilePath $LogPath -Append
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    if ($exitCode -ne 0) { throw "Command failed: $FilePath $($Arguments -join ' ')" }
}
function Get-SourceFingerprint {
    $records = foreach ($file in @(Get-ChildItem -LiteralPath $RepoRoot -Recurse -File | Sort-Object FullName)) {
        $relative = $file.FullName.Substring($RepoRoot.Length).TrimStart('\', '/').Replace('\', '/')
        if ($relative.StartsWith("artifacts/", [StringComparison]::OrdinalIgnoreCase) -or $relative.StartsWith("vendor/exlaunch/", [StringComparison]::OrdinalIgnoreCase) -or $relative.StartsWith(".git/", [StringComparison]::OrdinalIgnoreCase)) { continue }
        "$relative $((Get-FileHash -Algorithm SHA256 -LiteralPath $file.FullName).Hash)"
    }
    $sha = [Security.Cryptography.SHA256]::Create()
    try { return ([BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes(($records -join "`n"))))).Replace("-", "") } finally { $sha.Dispose() }
}

if ($Jobs -lt 1 -or $Jobs -gt 64) { throw "Jobs must be between 1 and 64." }
if ([string]::IsNullOrWhiteSpace($ExlaunchSource)) { $ExlaunchSource = Join-Path $RepoRoot "vendor\exlaunch" }
$ExlaunchSource = (Resolve-Path -LiteralPath $ExlaunchSource).Path
$sourceCommit = (& git -C $ExlaunchSource rev-parse HEAD).Trim()
if ($LASTEXITCODE -ne 0 -or $sourceCommit -ne $PinnedExlaunchCommit) { throw "vendor/exlaunch must be checked out at $PinnedExlaunchCommit; found '$sourceCommit'." }

New-Item -ItemType Directory -Force -Path $OutputRoot | Out-Null
if (Test-Path -LiteralPath $WorkRoot) { Remove-Item -LiteralPath $WorkRoot -Recurse -Force }
New-Item -ItemType Directory -Force -Path $OutputRoot | Out-Null
"Bowser's Fury Co-op public build" | Set-Content -LiteralPath $LogPath -Encoding UTF8
Invoke-Checked "git" @("-c", "init.defaultBranch=main", "clone", "--quiet", "--no-hardlinks", $ExlaunchSource, $WorkRoot)
Invoke-Checked "git" @("-C", $WorkRoot, "checkout", "--quiet", $PinnedExlaunchCommit)

$OverlayRoot = Join-Path $RepoRoot "patch_src\exlaunch"
foreach ($required in @("config.mk", "config.json", "source\program\main.cpp", "source\program\setting.hpp")) {
    if (-not (Test-Path -LiteralPath (Join-Path $OverlayRoot $required) -PathType Leaf)) { throw "Public release overlay is incomplete: $required" }
}
foreach ($file in @(Get-ChildItem -LiteralPath $OverlayRoot -Recurse -File)) {
    $relative = $file.FullName.Substring($OverlayRoot.Length).TrimStart('\', '/')
    $destination = Join-Path $WorkRoot $relative
    New-Item -ItemType Directory -Force -Path (Split-Path -Parent $destination) | Out-Null
    Copy-Item -LiteralPath $file.FullName -Destination $destination -Force
}

if ($UseDocker) {
    if (-not (Get-Command docker -ErrorAction SilentlyContinue)) { throw "Docker is required for -UseDocker." }
    Invoke-Checked "docker" @("run", "--rm", "--mount", "type=bind,source=$RepoRoot,target=/workspace", "--workdir", "/workspace/artifacts/build-work/exlaunch", $DockerImage, "bash", "-lc", "make clean && make -j$Jobs ASFLAGS='$ReleaseAsFlags'")
    $toolchain = $DockerImage
} else {
    if ([string]::IsNullOrWhiteSpace($DevkitProRoot)) { $DevkitProRoot = if (Test-Path "C:\devkitPro") { "C:\devkitPro" } elseif ($env:DEVKITPRO) { $env:DEVKITPRO } else { throw "Specify -DevkitProRoot or set DEVKITPRO." } }
    $compiler = Join-Path $DevkitProRoot "devkitA64\bin\aarch64-none-elf-g++.exe"
    if (-not (Test-Path -LiteralPath $compiler -PathType Leaf)) { throw "devkitA64 compiler not found below $DevkitProRoot." }
    $nativeRoot = "/$($DevkitProRoot.Substring(0,1).ToLowerInvariant())/$($DevkitProRoot.Substring(2).Replace('\','/').TrimStart('/'))"
    $oldDevkit = $env:DEVKITPRO; $env:DEVKITPRO = $nativeRoot
    try { Invoke-Checked "make" @("-C", $WorkRoot, "clean"); Invoke-Checked "make" @("-C", $WorkRoot, "-j$Jobs", "ASFLAGS=$ReleaseAsFlags") } finally { $env:DEVKITPRO = $oldDevkit }
    $toolchain = ((& $compiler --version | Select-Object -First 1) -join "").Trim()
}

$builtSubsdk = Join-Path $WorkRoot "deploy\subsdk9"
$builtNpdm = Join-Path $WorkRoot "deploy\main.npdm"
$builtElf = Join-Path $WorkRoot "exlaunch.elf"
foreach ($path in @($builtSubsdk, $builtNpdm, $builtElf)) { if (-not (Test-Path -LiteralPath $path -PathType Leaf)) { throw "Expected build output is missing: $path" } }
Copy-Item $builtSubsdk (Join-Path $OutputRoot "subsdk9") -Force
Copy-Item $builtNpdm (Join-Path $OutputRoot "main.npdm") -Force
Copy-Item $builtElf (Join-Path $OutputRoot "exlaunch.elf") -Force
$outputs = foreach ($name in @("subsdk9", "main.npdm", "exlaunch.elf")) { $path = Join-Path $OutputRoot $name; $item = Get-Item $path; [ordered]@{ path = "artifacts/build/$name"; bytes = $item.Length; sha256 = (Get-FileHash -Algorithm SHA256 $path).Hash } }
$report = [ordered]@{ schema_version = 1; status = "PASS"; version = $Version; program_id = $ProgramId; exlaunch_commit = $PinnedExlaunchCommit; source_fingerprint_sha256 = Get-SourceFingerprint; build_mode = $(if ($UseDocker) { "docker" } else { "local" }); toolchain = $toolchain; clean_build = $true; outputs = @($outputs) }
$report | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $OutputRoot "build-report.json") -Encoding UTF8
Write-Host "Bowser's Fury Co-op public build: PASS"
