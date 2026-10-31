[Back to the main project README](../README.md)

# Items that need to be completed

**Last updated: October 30, 2026 at 11:22 PM MDT (America/Denver)**

<!-- Refresh this timestamp whenever this page changes; use America/Denver local time. -->

1. Most SAT menus are complete. I’m still working on some deeper SAT menus and investigating how they operate. I’d welcome input from anyone familiar with them.
2. Final test of the menu system.
3. Complete the final assembly instructions, wiring diagrams, and an updated parts list.
4. Test the manufactured boards and run an extended reliability test.
5. Document how builders can source components from independent suppliers, order PCBs from a manufacturer, print the STL parts, and program their own Teensy. I share the project files and build guidance; I’d prefer to keep this a DIY project rather than sell parts, kits, or completed panels. That said, a few people have already asked for help, so if you’re stuck and need a hand, feel free to reach out—I’d be happy to discuss what might be possible.
6. Design and print a USB cable strain-relief support to protect the Teensy's Micro-B connector from cable pulls.
7. Add [C-130J support](C-130J-Support.md) using the existing ARC-210 hardware: verify the existing DCS-BIOS controls and frequency export; follow the [Helios-based LCD export plan](C-130J-Support.md#helios-findings-and-lcd-export-plan), starting by verifying indicator 44 in the installed module, capturing live indications, parsing them once per export cycle, adding named string outputs for the LCD/menu fields, and clearing fields that disappear between pages; check RT SELECT behavior; and complete firmware and menu changes, debug-app support, testing, and documentation. Document any unavailable display data.
8. **Assembly pictures:** When the manufactured PCBs arrive and I start building, take pictures throughout assembly for the Build Guide, including component placement, soldering, wiring, and mounting. Include clear photos of both sides of the Button Matrix PCB, showing the switches on the front and the diodes and pin connectors on the back, with the silkscreen markings visible. Add those photos to the Button Matrix PCB README too.
9. **Smaller PCB orders:** Investigate a way for builders to order one complete radio’s PCB set instead of the usual five copies of each design. Compare single-copy suppliers or order options with a combined manufacturing panel, checking minimum quantities, separation and mounting clearances, design fees, shipping, and the total delivered cost. Publish a verified ordering route if one is practical.
