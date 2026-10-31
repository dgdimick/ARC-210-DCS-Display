# ARC-210 firmware source

**Last updated: October 31, 2026 at 12:49 AM MDT (America/Denver)**

I’ve included my Master_Program source and ARC210_Display library snapshot here so the startup information and radio display code can be built together. The current build is **v0.1.1 Preview**, for **A-10C2 only**. C-130J and automatic aircraft switching are still in development.

## Sharing code and improvements

My main firmware code is shared under the [MIT License](../../../Docs/LICENSE-MIT.txt), and I’m happy to provide it to anyone who asks. If you adapt it or add improvements, I’d love to work with you and bring useful changes back into this project so other builders—and my other panel projects—can benefit too.

Please share your changes through a pull request or get in touch in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Contributing changes back is welcome, but it isn’t an extra condition of the MIT License. Third-party code keeps its own license.

## Version and startup labels

Edit `dependencies/ARC210_Display/src/FirmwareInfo.h` when preparing a release. It defines the version, preview status, and aircraft list used by `showInfoScreen()` in `Display.cpp`. Keep the HEX filename and release notes aligned with these values. Only list aircraft implemented in that build.

The version and aircraft appear during the existing radio-switch information screen. Aircraft-power restoration follows the existing boot path, which can skip that information screen. Initial USB connection still waits for powered-radio data.

## Build

I compiled this preview with Arduino CLI, Teensy platform **1.62.0**, DCS-BIOS **0.3.13**, and the platform’s ILI9488_t3 **1.0**, SPI, and Servo libraries. Install the Teensy platform using [PJRC’s instructions](https://www.pjrc.com/teensy/td_download.html), and install the DCS-BIOS Arduino library. From this folder, run:

```powershell
arduino-cli compile --fqbn teensy:avr:teensy41 --libraries dependencies --output-dir build .
```

The compiler produces `Master_Program.ino.hex`. For publication, label it `ARC210_A-10C2_v0.1.1_Preview.hex`, matching `FirmwareInfo.h`. This source is a preview: compilation succeeded, but I still need to check the new build on my physical panel and in DCS. Full physical-control integration remains incomplete.
