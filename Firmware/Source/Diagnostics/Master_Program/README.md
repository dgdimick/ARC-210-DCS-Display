# ARC-210 v0.1.3 diagnostic source

**Last updated: November 1, 2026 at 12:23 AM MDT (America/Denver)**

This source builds `ARC210_A-10C2_v0.1.3_Diagnostic.hex`. It includes the GPIO 4 backlight initialization from v0.1.2, displays the information screen immediately without DCS-BIOS data, and prints received-byte counts, MASTER, radio/display power, and frequency over USB once a second.

I loaded this build on my panel and confirmed that the display appeared and received simulated data, including MASTER = TR and frequency 133.123, from the corrected bridge. Live DCS operation and full physical-control integration are still untested/incomplete. **This is a bench diagnostic, not the clean preview recommended for a normal DCS connection.**

Build for Teensy 4.1 with the same dependencies as the [clean preview source](../../Master_Program/README.md):

```powershell
arduino-cli compile --fqbn teensy:avr:teensy41 --libraries dependencies --output-dir build .
```

[HEX downloads and limitations](../../../Master%20Hex%20Files/README.md)
