# Bowser's Fury Co-op

Bowser's Fury Co-op adds a second playable Luigi actor to **Super Mario 3D World + Bowser's Fury version 1.1.0**. It is a local two-player mod for Ryujinx and Atmosphere; it is not an online multiplayer mod.

## Support status

- **Game:** title ID `010028600EBDA000`, version 1.1.0 only.
- **Ryujinx:** primary target for the alpha release.
- **Atmosphere:** experimental; use the generated package and a matching game dump.

## What the mod adds

- A Luigi P2 actor with shared-screen camera support.
- Co-op recovery and respawn handling.
- Player-aware camera, capture, tree/grab, and stage-transition fixes.
- Crash and non-Mario figure fixes used by the co-op path.
- A LayeredFS settings file for camera and recovery tuning.

## Requirements

- A legally obtained copy of Super Mario 3D World + Bowser's Fury version 1.1.0.
- Ryujinx or a mod-capable Atmosphere setup.
- Two controllers configured as separate input devices.
- The `BowsersFuryCoopMod-v0.1.0-alpha.1.zip` package.

## Install on Ryujinx

1. Download the ZIP and its SHA-256 sidecar from the release.
2. Extract the ZIP and run `install.ps1` from the extracted package directory:

   ```powershell
   Unblock-File .\install.ps1
   .\install.ps1
   ```

3. Configure two controllers, launch Bowser's Fury, and reproduce the co-op scenario documented in the release notes.

The installer verifies package checksums and backs up replaced files under the title directory. For manual installation, copy `payload/contents` into the Ryujinx `mods` directory while preserving the title ID.

## Configuration

The installed settings file is:

```text
contents/010028600EBDA000/romfs/BowsersFuryCoopMod/settings.ini
```

Close the emulator before editing it. Scene initialization reloads the settings. `coop.enabled` controls whether the co-op path is armed; camera and bubble values control the shared camera and recovery behavior.

## Troubleshooting

### Luigi does not appear

- Confirm the game is version 1.1.0 and the title ID is correct.
- Confirm `subsdk9`, `main.npdm`, and `settings.ini` came from the same package.
- Disable other executable and gameplay mods.
- Reload the scene after changing settings.

### A scene crashes

- Reinstall the complete release package so all files share one release version.
- Temporarily set `coop.enabled=0` to isolate the co-op path.
- Include the exact scene, player positions, and emulator log in a bug report. Remove personal paths before posting logs.

## How it works

The mod is an ExLaunch `subsdk9` module built against the pinned ExLaunch revision in this repository. It hooks narrow native operations in the 1.1.0 executable, reuses the game's player and camera objects, and applies compatibility fixes only where the single-player assumptions conflict with Luigi's second actor.

## Building from source

Clone with the pinned ExLaunch submodule and run:

```powershell
git clone --recurse-submodules https://github.com/Gudui/BowsersFuryLocalCoop.git
Set-Location BowsersFuryCoopMod
.\scripts\build.ps1 -UseDocker
.\scripts\package.ps1
.\scripts\verify.ps1
```

Local builds can use `.\scripts\build.ps1 -DevkitProRoot PATH_TO_DEVKITPRO`.

## Contributing and credits

Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening an issue or pull request. Do not submit game files, executable dumps, keys, private logs, or personal paths. Credits and dependency notices are in [CREDITS.md](CREDITS.md) and [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

This is an unofficial fan project and is not affiliated with or endorsed by Nintendo.
