[Back to the main project README](../README.md)

# Related radio projects

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

Alongside the ARC-210, I’m planning two more physical radio panels for my DCS cockpit:

- **[ARC-164 UHF radio panel](https://github.com/dgdimick/ARC-164-DCS-Display):** I’ll use a dedicated Teensy 4.1 to operate the panel through DCS-BIOS. I plan to put all five frequency encoders and the preset-channel encoder on one PCB, assuming there is enough room behind the faceplate.
- **[ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display):** I’ll also give this panel its own Teensy 4.1 and USB connection to DCS-BIOS, so it can be built and operated independently of the ARC-164.

I’m still developing both projects. Follow their repositories for hardware plans, firmware, build notes, and progress updates.

## Possible future aircraft support

[View possible future aircraft support](Possible-Future-Aircraft-Support.md) for physical-panel candidates, investigation priorities, and separate DCS-BIOS mapping requirements.

## Why I keep using Teensy 4.1s

[Read why I keep using Teensy 4.1s](Why-I-Keep-Using-Teensy-4.1s.md) for the consistency, processing speed, available pins, and cost comparison behind the controller choice.
