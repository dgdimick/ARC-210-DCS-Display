[Back to the main project README](../README.md)

# Related radio projects

**Last updated: November 12, 2026 at 3:11 AM MST (America/Denver)**

I’ll **finish the ARC-164 PCBs**, then **take a break from design work and go back to testing the ARC-210**. **The ARC-186 and Version 2 plans can wait.** I haven’t set a date to return to those designs or additional aircraft support. I’m focusing any future aircraft extensions on aircraft with a matching physical radio panel. **Priorities may change based on feedback and interest; these are not fixed release dates.**

Alongside the A-10C II ARC-210, I’m planning these radio projects for my DCS cockpit:

- **[ARC-164 UHF radio panel](https://github.com/dgdimick/ARC-164-DCS-Display):** I’ll use a dedicated Teensy 4.1 to operate the panel through DCS-BIOS. I plan to put all five frequency encoders and the preset-channel encoder on one PCB, assuming there is enough room behind the faceplate.
- **[ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display):** I’m keeping my **existing panel with its smaller holes**, rather than buying a replacement with larger holes. I’m considering a **multilevel rotary-switch setup**, with switches and PCBs mounted at different depths. **Shaft/bushing fit, shaft reach, knob fit and clearances still need checking before I finalize the layout.** This is a tentative mounting plan. The panel will have its own USB connection to DCS-BIOS so it can be built and operated independently of the ARC-164; see its README for the current controller plan.

- **[C-130J ARC-210 support](C-130J-Support.md):** I plan to reuse my existing ARC-210 faceplate, controls, display, PCBs, and printed parts. I’m keeping this work in the main ARC-210 repository, planning C-130J mappings and menu behavior for the shared ARC-210 code base; implementation and compatibility testing are later work.

The ARC-164 and ARC-186 have their own repositories. C-130J support is tracked here in the [main work list](Remaining-Work.md). All three are still under development.

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.**

## Bare PCB offer for the ARC-210

See my [ARC-210 PCB and printed-parts offers](ARC-210-Parts-Offers.md) for current prices, what’s included, materials, availability, shipping, VAT, and import charges. My bare PCB offer covers the ARC-210. I’ll offer printing help for the ARC-164 and ARC-186 once their printed parts are finalized. **My PCB offer contains bare boards only, not electronic components or a complete panel kit.** Buy the Teensy, display, controls, faceplate, wiring, and other components separately. I’m happy to provide a free printed set whether you get your PCBs from me or elsewhere. Just cover shipping.

## Other SIMPIT panels

Once I’ve finished the radio panels, I plan to build other panels for my SIMPIT, including the **SAS and emergency trim panels**. I’ll share those projects as they develop. These are future plans, and my priorities may change based on user feedback and interest.

## Possible future aircraft support

[View possible future aircraft support](Possible-Future-Aircraft-Support.md) for physical-panel candidates, investigation priorities, and separate DCS-BIOS mapping requirements.

## A central directory for SIMPIT builders

I’d love to see a central GitHub directory linking to projects from SIMPIT builders like me—a place to find panels, code, PCB designs, printable parts, and build guides for SIMPITs of every size. It could link back to each builder’s own repository so the files, updates, and credit stay with the original project. This is an idea I’d like to see happen, rather than a project I’ve committed to building myself.

[Read more about the directory idea](Future-Thoughts.md#a-central-directory-for-simpit-builders). If you know of one or would like to discuss it, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).

## Why I keep using Teensy 4.1s

[Read why I keep using Teensy 4.1s](Why-I-Keep-Using-Teensy-4.1s.md) for the consistency, processing speed, available pins, and cost comparison behind the controller choice.
