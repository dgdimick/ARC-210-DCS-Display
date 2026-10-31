[Back to the main project README](../README.md)

# Related radio projects

**Last updated: October 30, 2026 at 9:48 PM MDT (America/Denver)**

Alongside the A-10C II ARC-210, I’m planning these radio projects for my DCS cockpit:

- **[ARC-164 UHF radio panel](https://github.com/dgdimick/ARC-164-DCS-Display):** I’ll use a dedicated Teensy 4.1 to operate the panel through DCS-BIOS. I plan to put all five frequency encoders and the preset-channel encoder on one PCB, assuming there is enough room behind the faceplate.
- **[ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display):** I’ll also give this panel its own Teensy 4.1 and USB connection to DCS-BIOS, so it can be built and operated independently of the ARC-164.

- **[C-130J ARC-210 support](C-130J-Support.md):** I plan to reuse my existing ARC-210 faceplate, controls, display, PCBs, and printed parts. I’m keeping this work in the main ARC-210 repository, focusing on C-130J firmware, DCS-BIOS mappings, and the menu system; C-130J compatibility still needs testing.

The ARC-164 and ARC-186 have their own repositories. C-130J support is tracked here in the [main work list](Remaining-Work.md). All three are still under development.

**The same ARC-210 hardware should work with both the A-10C II and C-130J**, using the appropriate aircraft-specific firmware and DCS-BIOS mappings. C-130J operation still needs to be implemented and tested.

## Possible future aircraft support

[View possible future aircraft support](Possible-Future-Aircraft-Support.md) for physical-panel candidates, investigation priorities, and separate DCS-BIOS mapping requirements.

## Why I keep using Teensy 4.1s

[Read why I keep using Teensy 4.1s](Why-I-Keep-Using-Teensy-4.1s.md) for the consistency, processing speed, available pins, and cost comparison behind the controller choice.
