param([string]$Version, [string]$BuildRoot, [string]$OutputRoot)
$ErrorActionPreference = "Stop"; Set-StrictMode -Version Latest
$RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$ProgramId = "010028600EBDA000"; $ExpectedExlaunchCommit = "f698816d6e198afb0029ad5c07d55e7017a620fe"
if ([string]::IsNullOrWhiteSpace($Version)) { $Version = (Get-Content -Raw (Join-Path $RepoRoot "VERSION")).Trim() }
if ([string]::IsNullOrWhiteSpace($BuildRoot)) { $BuildRoot = Join-Path $RepoRoot "artifacts\build" }
if ([string]::IsNullOrWhiteSpace($OutputRoot)) { $OutputRoot = Join-Path $RepoRoot "artifacts\package" }
$report = Get-Content -Raw (Join-Path $BuildRoot "build-report.json") | ConvertFrom-Json
if ($report.status -ne "PASS" -or $report.version -ne $Version -or $report.program_id -ne $ProgramId -or $report.exlaunch_commit -ne $ExpectedExlaunchCommit) { throw "Build report does not match this release." }
$packageName = "BowsersFuryCoopMod-$Version"; $stage = Join-Path $OutputRoot $packageName
if (Test-Path $stage) { Remove-Item $stage -Recurse -Force }; New-Item -ItemType Directory -Force -Path (Join-Path $stage "payload\contents\$ProgramId\exefs") | Out-Null; New-Item -ItemType Directory -Force -Path (Join-Path $stage "payload\contents\$ProgramId\romfs\BowsersFuryCoopMod") | Out-Null
Copy-Item (Join-Path $BuildRoot "subsdk9") (Join-Path $stage "payload\contents\$ProgramId\exefs\subsdk9")
Copy-Item (Join-Path $BuildRoot "main.npdm") (Join-Path $stage "payload\contents\$ProgramId\exefs\main.npdm")
Copy-Item (Join-Path $RepoRoot "romfs\BowsersFuryCoopMod\settings.ini") (Join-Path $stage "payload\contents\$ProgramId\romfs\BowsersFuryCoopMod\settings.ini")
Copy-Item (Join-Path $RepoRoot "scripts\install.ps1") (Join-Path $stage "install.ps1")
$relative = { param([string]$p) $p.Substring($stage.Length).TrimStart('\','/').Replace('\','/') }
$payload = @(Get-ChildItem (Join-Path $stage "payload") -Recurse -File | Sort-Object FullName | ForEach-Object { [ordered]@{ path = & $relative $_.FullName; bytes = $_.Length; sha256 = (Get-FileHash -Algorithm SHA256 $_.FullName).Hash } })
$packageManifest = [ordered]@{ schema_version = 1; name = "Bowser's Fury Co-op"; version = $Version; program_id = $ProgramId; exlaunch_commit = $ExpectedExlaunchCommit; primary_target = "Ryujinx"; atmosphere_support = "experimental"; files = $payload }
$packageManifest | ConvertTo-Json -Depth 8 | Set-Content (Join-Path $stage "PACKAGE_MANIFEST.json") -Encoding UTF8
$checksums = @(Get-ChildItem $stage -Recurse -File | Where-Object Name -ne "CHECKSUMS.txt" | Sort-Object FullName | ForEach-Object { "$( (Get-FileHash -Algorithm SHA256 $_.FullName).Hash ) *$( & $relative $_.FullName )" })
$checksums -join "`n" | Set-Content (Join-Path $stage "CHECKSUMS.txt") -Encoding UTF8
$zip = Join-Path $OutputRoot "$packageName.zip"; if (Test-Path $zip) { Remove-Item $zip -Force }
Compress-Archive -Path $stage -DestinationPath $zip -CompressionLevel Optimal
$hash = (Get-FileHash -Algorithm SHA256 $zip).Hash; "$hash *$([IO.Path]::GetFileName($zip))" | Set-Content "$zip.sha256" -Encoding ASCII
[ordered]@{ schema_version = 1; status = "PASS"; version = $Version; program_id = $ProgramId; zip = [ordered]@{ path = $zip; bytes = (Get-Item $zip).Length; sha256 = $hash }; payload_files = $payload } | ConvertTo-Json -Depth 8 | Set-Content (Join-Path $OutputRoot "package-report.json") -Encoding UTF8
Write-Host "Bowser's Fury Co-op public package: PASS"
