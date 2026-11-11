[Back to the main project README](../README.md)

# Items that need to be completed

**Last updated: November 10, 2026 at 7:33 PM MST (America/Denver)**

<!-- Refresh this timestamp whenever this page changes; use America/Denver local time. -->

I’m finishing the A-10C II ARC-210 first, then the ARC-164 and ARC-186, before returning to additional aircraft support. [My development priorities](Related-Radio-Projects.md) may change based on feedback and interest.

1. Most SAT menus are complete. I’m still working on some deeper SAT menus and investigating how they operate. I’d welcome input from anyone familiar with them.
2. Final test of the menu system.
3. Complete the final assembly instructions, wiring diagrams, and an updated parts list.
4. Test the manufactured boards and run an extended reliability test.
5. Complete the DIY sourcing and build guidance, including buying components, ordering PCBs, printing parts, and programming the Teensy. Keep availability and shipping arrangements on the [ARC-210 parts offers page](ARC-210-Parts-Offers.md) up to date so builders can compare my complete sets with manufacturer minimum orders. Keep the files available for builders who prefer to order their own boards.
6. Design and print a USB cable strain-relief support to protect the Teensy's Micro-B connector from cable pulls.
7. Add [C-130J support](C-130J-Support.md) using the existing ARC-210 hardware and one shared code base: implement automatic aircraft selection so users can switch between supported aircraft without reflashing the Teensy, and test that switching behavior; verify the existing DCS-BIOS controls and frequency export; follow the [Helios-based LCD export plan](C-130J-Support.md#helios-findings-and-lcd-export-plan), starting by verifying indicator 44 in the installed module, capturing live indications, parsing them once per export cycle, adding named string outputs for the LCD/menu fields, and clearing fields that disappear between pages; check RT SELECT behavior; and complete firmware and menu changes, testing, and documentation. Document any unavailable display data.
8. **Assembly pictures:** When the manufactured PCBs arrive and I start building, take pictures throughout assembly for the Build Guide, including component placement, soldering, wiring, and mounting. Include clear photos of both sides of the Button Matrix PCB, showing the switches on the front and the diodes and pin connectors on the back, with the silkscreen markings visible. Add those photos to the Button Matrix PCB README too.
9. **On-screen test versions:** Add visible **V1.0** labels to the earlier button/encoder test and the standalone encoder test. Their current V1.0 filenames do not change the existing screen labels. I need to recover their matching source or recreate the tests, rebuild and check them on the panel, then update the HEX downloads and instructions so the on-screen version matches the filename.
10. **USB-C adapter testing:** I confirmed DCSBridge panel control and Teensy programming on my ARC-210. I still need to check live DCS operation and reliable reconnection after unplugging the adapter.
