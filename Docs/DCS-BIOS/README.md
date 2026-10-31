# Downloadable DCS-BIOS files

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

## ARC-210 patched A-10C.lua

Based on [DCS-Skunkworks DCS-BIOS v0.11.8](https://github.com/DCS-Skunkworks/dcs-bios/releases/tag/v0.11.8), extracted from its official release package. [Original source](https://github.com/DCS-Skunkworks/dcs-bios/blob/v0.11.8/Scripts/DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua).

Modified October 30, 2026 for Denis Dimick’s ARC-210 project. Changes are a modification notice at the top and two existing getter return lines: `ARC210_VERIFY_WOD_ACTIVE_CHANNEL` and `ARC210_SELECTED_RT`. Definitions, lengths, and ordering are unchanged. The packaged reference confirms addresses 0x1338 (2 characters) and 0x1320 (3 characters). A reverse replacement check confirms every other byte after the modification notice matches the release module. [Exact changes](A-10C-ARC210.patch).

This file is distributed under the upstream GNU GPL version 3; see [LICENSE-DCS-BIOS.txt](LICENSE-DCS-BIOS.txt). Upstream authorship and notices are retained. The license for this Lua module is separate from the ARC-210 documentation and firmware licenses.

SHA-256 of original module: `837534437749eb7e6f8fd94346ae941f2cb369866ae0f3fd5a226cc382ffcf18`

SHA-256 of patched module: `5ea0a6919c6eea8ba3054cb94abc48a72a0c0760350d7c07183cdfbf819e65ee`

Checks verify the two changes and the release’s reference addresses, not operation in DCS. This packaged v0.11.8 replacement has not been tested in a live DCS session. Use it with v0.11.8; for other versions, apply the two edits to that version’s own module instead. Back up your installed file before replacing it. Follow the [setup guide](../DCS-BIOS.md).

## Export.lua

For a setup that only needs DCS-BIOS, [DCS-BIOS-only/Export.lua](DCS-BIOS-only/Export.lua) contains only the loader line. Follow the [DCS-BIOS setup guide](../DCS-BIOS.md#3-tell-dcs-to-load-dcs-bios) for installation and instructions on preserving existing integrations.

My [Export.lua](Export.lua) is the loader example for WWT, DCS-BIOS, and SRS. It does not patch the aircraft module. The [DCS-BIOS setup guide](../DCS-BIOS.md#my-exportlua-example) explains each line and which ones your setup needs.
