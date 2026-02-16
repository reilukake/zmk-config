# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ZMK firmware configuration for a **Sofle Choc split keyboard** with:
- 2x nice!nano v2 controllers (nRF52840, Bluetooth)
- 2x nice!view displays (128x32 SPI OLED)
- 2x EC11 rotary encoders
- ZMK Studio enabled on the left half for live keymap editing via USB

## Build System

Firmware is built via **GitHub Actions** — there is no local build. The workflow is:
1. Edit `config/sofle.keymap` or `config/sofle.conf`
2. Commit and push to `main`
3. GitHub Actions runs ZMK's `build-user-config.yml` reusable workflow
4. Download `.uf2` artifacts from the Actions tab
5. Flash by copying `.uf2` to the keyboard in bootloader mode (double-tap reset)

**Build matrix** (`build.yaml`) produces 3 firmware files:
- `sofle_left` — includes `nice_view_adapter nice_view` shields + ZMK Studio (`studio-rpc-usb-uart` snippet, `-DCONFIG_ZMK_STUDIO=y`)
- `sofle_right` — includes `nice_view_adapter nice_view` shields only
- `settings_reset` — utility firmware for clearing stored settings

The build uses **West** with ZMK v0.3 (`config/west.yml`). The `.zmk/` directory is the West workspace (gitignored, not needed for CI builds).

## Key Files

- `config/sofle.keymap` — Keymap with 4 layers: BASE (0), LOWER (1), RAISE (2), ADJUST (3). ADJUST activates via conditional layer when LOWER+RAISE are held simultaneously.
- `config/sofle.conf` — Kconfig settings: display, encoders, Bluetooth TX power. RGB underglow is available but disabled.
- `config/simple_bongo_status.c` — Custom OLED status widget (exists but is **not integrated** into the build; would need a custom shield definition in `boards/shields/` with CMakeLists.txt and Kconfig).
- `build.yaml` — GitHub Actions build matrix defining board/shield/snippet combinations.
- `scripts/dev-helper.sh` — Convenience script for editing, pushing, and backing up config.

## Keymap Conventions

- The keymap uses ZMK devicetree syntax (not a C keymap)
- Layer references use `#define` constants: `BASE 0`, `LOWER 1`, `RAISE 2`, `ADJUST 3`
- Sensor bindings (encoders) are defined per-layer
- Shield stacking is used: multiple shields are combined in `build.yaml` (e.g., `sofle_left nice_view_adapter nice_view`)
- Bluetooth controls and RGB settings live on RAISE and ADJUST layers

## ZMK References

- ZMK keycodes: https://zmk.dev/docs/keymaps/list-of-keycodes
- ZMK behaviors: https://zmk.dev/docs/keymaps/behaviors
- ZMK Studio: https://zmk.studio (connect left half via USB)
