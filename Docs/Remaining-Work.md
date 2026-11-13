[Back to the main project README](../README.md)

# Items that need to be completed

**Last updated: November 13, 2026 at 2:15 AM MST (America/Denver)**

<!-- Refresh this timestamp whenever this page changes; use America/Denver local time. -->

I’m finishing the A-10C II ARC-210 first, then the ARC-164 and ARC-186, before returning to additional aircraft support. [My development priorities](Related-Radio-Projects.md) may change based on feedback and interest.

1. Most SAT menus are complete. I’m still working on some deeper SAT menus and investigating how they operate. I’d welcome input from anyone familiar with them.
2. Final test of the menu system.
3. Complete the final assembly instructions, wiring diagrams, and an updated parts list.
4. Test the manufactured boards and run an extended reliability test.
5. **Finish the DIY build guidance.** PCB ordering instructions and manufacturing files are published. Once the full panel is assembled, confirm hardware quantities, standoff and socket heights, and cable lengths. Finish the illustrated print and installation notes and link both published USB cradles where the parts and build guides still say the support is pending. Confirm which HEX to use for normal operation and verify the Teensy programming instructions on the finished panel.
6. **Assembly pictures:** When the manufactured PCBs arrive and I start building, take pictures throughout assembly for the Build Guide, including component placement, soldering, wiring, and mounting. Include clear photos of both sides of the Button Matrix PCB, showing the switches on the front and the diodes and pin connectors on the back, with the silkscreen markings visible. Add those photos to the Button Matrix PCB README too.
7. **USB-C adapter testing:** I confirmed DCSBridge panel control and successfully programmed the Teensy through the USB-C adapter. I still need to check live DCS operation and reliable reconnection after unplugging the adapter.
8. **Optional Windows USB display name utility:** Rename and restore passed on COM5. On the flight sim PC, use the utility with the assigned COM port and verify Teensy Loader and live DCS-BIOS with both labels. [Utility and instructions](../Tools/README.md).
