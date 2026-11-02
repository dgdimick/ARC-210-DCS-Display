# ARC-210 DCS forum post

**Last updated: November 1, 2026 at 7:25 PM MST (America/Denver)**

> Historical forum-post draft. For current PCB releases, wiring, power, and firmware status, use the [main README](../README.md) and [parts documentation](../parts/README.md). The control-board manufacturing packages are now published; Main Board v1.1 fabrication files are also published; physical validation is pending.

I’m starting a **DCS-BIOS ARC-210 project**.

So far, I’ve completed the schematic and have the Teensy communicating with DCS-BIOS and successfully displaying the current ARC-210 frequency on the TFT.

My plan is to release everything needed for someone to build their own unit, including:

- PCB manufacturing files
- Schematics
- Knob STL files
- Any other required 3D-printable parts
- Firmware
- Test code and documentation

I also plan to release the firmware as a **HEX file**, so someone who isn’t a programmer should still be able to flash the Teensy without having to compile the source code.

Because this project will handle all **16 buttons**, the rotary encoders, rotary switches, TFT display, and the other ARC-210 controls, I’m using a **Teensy 4.1** as the controller.

My PCB offer is **bare boards only**, not a complete parts kit. Builders buy the Teensy, display, controls, faceplate, wiring, and other components separately.

The current JLCPCB-based parts estimate is **US$267.72–US$300.72** (about **US$268–US$301**), including the faceplate and the **US$58.20 PCB cart allowance** with displayed shipping and a US$15.00 coupon. Without that coupon, add US$15.00. Delivery for other components and any additional applicable duties, taxes, VAT, or carrier fees remain separate. See the [parts estimate](../parts/README.md#estimated-build-cost) and [both PCB purchasing options](ARC-210-Parts-Offers.md#both-pcb-purchasing-options). If you request them with my ARC-210 PCB set, I’ll include the complete 3D-printed parts set free of charge. Shipping and handling remain separate.

I’ve also set up a GitHub repository where I’ll post project updates and files as the build progresses. There is already some test firmware available, including a basic TFT test that displays “Hello World” so you can verify that the Teensy and SPI TFT display are wired and working correctly.

I’ve been working on this project on and off for roughly the last **18 months**. I’ve had to stop a few times because of the cost of parts and PCB development, but I’m now getting back into it and making good progress.

All of the code I’m writing for the project is my own. The project will be released under several licenses depending on the type of file:

- **PCB, schematics, and hardware design:** CERN Open Hardware Licence Version 2 – Permissive (CERN-OHL-P-2.0)
- **Teensy firmware/software:** MIT License
- **STL files and other 3D/visual assets:** Creative Commons Attribution 4.0 International (CC BY 4.0)

Here’s a short video showing the Teensy connecting to the ARC-210 through DCS-BIOS and receiving the current radio frequency:

https://drive.google.com/file/d/1iOCoj9Os1fUJ6zFHfCuTmOncaygpXLH4/view?usp=drive_link

GitHub repository:

https://github.com/dgdimick/ARC-210-DCS-Display
