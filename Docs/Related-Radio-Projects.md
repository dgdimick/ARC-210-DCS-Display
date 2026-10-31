[Back to the main project README](../README.md)

# Related radio projects

**Last updated: October 31, 2026 at 12:10 AM MDT (America/Denver)**

Alongside the A-10C II ARC-210, I’m planning these radio projects for my DCS cockpit:

- **[ARC-164 UHF radio panel](https://github.com/dgdimick/ARC-164-DCS-Display):** I’ll use a dedicated Teensy 4.1 to operate the panel through DCS-BIOS. I plan to put all five frequency encoders and the preset-channel encoder on one PCB, assuming there is enough room behind the faceplate.
- **[ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display):** I’ll also give this panel its own Teensy 4.1 and USB connection to DCS-BIOS, so it can be built and operated independently of the ARC-164.

- **[C-130J ARC-210 support](C-130J-Support.md):** I plan to reuse my existing ARC-210 faceplate, controls, display, PCBs, and printed parts. I’m keeping this work in the main ARC-210 repository, adding C-130J mappings and menu behavior to the shared ARC-210 code base; implementation and compatibility testing are still in progress.

The ARC-164 and ARC-186 have their own repositories. C-130J support is tracked here in the [main work list](Remaining-Work.md). All three are still under development.

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.**

## Possible future aircraft support

[View possible future aircraft support](Possible-Future-Aircraft-Support.md) for physical-panel candidates, investigation priorities, and separate DCS-BIOS mapping requirements.

## Why I keep using Teensy 4.1s

[Read why I keep using Teensy 4.1s](Why-I-Keep-Using-Teensy-4.1s.md) for the consistency, processing speed, available pins, and cost comparison behind the controller choice.
