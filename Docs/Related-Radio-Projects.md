[Back to the main project README](../README.md)

# Related radio projects

Alongside the ARC-210, I’m planning two more physical radio panels for my DCS cockpit:

- **[ARC-164 UHF radio panel](https://github.com/dgdimick/ARC-164-DCS-Display):** A dedicated Teensy 4.1 will operate the panel through DCS-BIOS. The encoder PCB is planned to carry all five frequency encoders and the preset-channel encoder, assuming there is enough room behind the faceplate.
- **[ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display):** This panel will also use its own Teensy 4.1 and USB connection to DCS-BIOS, allowing it to be built and operated independently of the ARC-164.

Both projects are in development. Follow their repositories for hardware plans, firmware, build notes, and progress updates.

## Why I keep using Teensy 4.1s

I’m using a Teensy 4.1 in each radio to keep the controller hardware and programming workflow consistent across the ARC-210, ARC-164, and ARC-186 projects. Each panel gets its own controller and USB connection, so it can be built and operated independently. Pin assignments and firmware will still be specific to each radio.

The Teensy 4.1 offers 42 readily accessible I/O pins and a 600 MHz processor, leaving room for controls, display updates, and future additions. Classic Arduino Uno and Mega boards run at 16 MHz. See [why I chose the Teensy 4.1](Why-Teensy.md) for the detailed comparison; clock speed alone does not determine display refresh performance.

I considered a classic Arduino Nano for the ARC-186, but the genuine Nano was listed at **$25.70** versus **$29.60** for the Teensy 4.1 without Ethernet—a difference of only **$3.90**, before shipping and tax, at the October 30, 2026 price check. For that small difference, I prefer the Teensy’s faster processor, extra capacity, and consistency across the radio projects. Its **600 MHz** CPU provides more processing headroom for display updates and controls than the classic Nano’s **16 MHz** CPU. The [ARC-186 controller comparison](https://github.com/dgdimick/ARC-186-DCS-Display#controller-cost-comparison) lists the options and supplier links. Ethernet is not needed for the planned USB DCS-BIOS connections.
