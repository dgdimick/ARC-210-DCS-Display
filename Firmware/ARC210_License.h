/*
  =============================================================================
   ARC-210 Control Panel Firmware
   Copyright (C) 2025  Denis Dimick  <dgdimick@gmail.com>

   Project: ARC-210 Radio Control Interface for DCS A-10C II
   Repository: https://https://github.com/dgdimick/ARC-210-DCS-Display
   License: GNU General Public License v3.0 (GPL-3.0)

   This firmware includes portions of the DCS-BIOS library, which is licensed
   under the GNU General Public License v3.0. Therefore, the combined work is
   distributed under the same GPL-3.0 license.

   You are free to use, modify, and redistribute this program under the terms
   of the GPL-3.0, provided that you include this notice and the full license
   text available at: <https://www.gnu.org/licenses/gpl-3.0.html>

   ---------------------------------------------------------------------------
   Summary of your rights and obligations under GPL v3:
     • You may use this firmware for any purpose.
     • You may modify and share it, provided you keep it GPL v3.
     • You must make the complete corresponding source available if you
       distribute a compiled or modified version.
     • There is NO WARRANTY — this is provided “AS IS”.
   ---------------------------------------------------------------------------

   ARC-210 Firmware includes:
     - DCS-BIOS Integration Layer
     - Display routines for ILI9488 / UTFTGLUE / Adafruit_GFX
     - Rotary encoder and switch logic
     - RS-485 interface (optional future support)

   For support or documentation:
     Contact:  Denis Dimick
     Location: White Rock, NM, USA
     Email:     dgdimick@gmail.com
  =============================================================================
*/

#pragma once
#include <Arduino.h>

// -----------------------------------------------------------------------------
// Firmware Version Info
// -----------------------------------------------------------------------------
#define ARC210_FIRMWARE_VERSION "v1.0.0"
#define ARC210_BUILD_DATE __DATE__ " " __TIME__

// -----------------------------------------------------------------------------
// License and Build Metadata (embedded in firmware binary)
// -----------------------------------------------------------------------------
const char ARC210_LICENSE_NOTICE[] PROGMEM = R"====(
ARC-210 Control Panel Firmware
(c) 2025 Denis Dimick
Licensed under GNU GPL v3.0 — See: https://www.gnu.org/licenses/gpl-3.0.html
Includes DCS-BIOS components (GPL v3)
Firmware Version: )====" ARC210_FIRMWARE_VERSION R"====(
Build Date: )====" ARC210_BUILD_DATE R"====(
)====";

// -----------------------------------------------------------------------------
// Helper function: print version and license info to Serial
// -----------------------------------------------------------------------------
inline void ARC210_PrintLicenseInfo() {
  Serial.println(F("------------------------------------------------------"));
  Serial.println(F("ARC-210 Control Panel Firmware"));
  Serial.print  (F("Version: ")); Serial.println(F(ARC210_FIRMWARE_VERSION));
  Serial.print  (F("Build:   ")); Serial.println(F(ARC210_BUILD_DATE));
  Serial.println(F("(c) 2025 Denis Dimick — GPL v3.0"));
  Serial.println(F("https://www.gnu.org/licenses/gpl-3.0.html"));
  Serial.println(F("------------------------------------------------------"));
}
