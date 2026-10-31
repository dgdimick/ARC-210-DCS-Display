[Back to the main project README](../README.md)

# Items that need to be completed

**Last updated: October 31, 2026 at 1:52 AM MDT (America/Denver)**

<!-- Refresh this timestamp whenever this page changes; use America/Denver local time. -->

My current plan is to finish the **A-10C II (A-10C2) ARC-210 implementation**, then build and test the **ARC-164**, followed by the **ARC-186**. After those projects, I’ll return to additional aircraft support, starting with the **ARC-210 and C-130J**. Those aircraft extensions are later work, not the current implementation priority. I’m focusing on aircraft with a matching physical radio panel. **This order may change based on user feedback and interest.**

1. Most SAT menus are complete. I’m still working on some deeper SAT menus and investigating how they operate. I’d welcome input from anyone familiar with them.
2. Final test of the menu system.
3. Complete the final assembly instructions, wiring diagrams, and an updated parts list.
4. Test the manufactured boards and run an extended reliability test.
5. Complete the DIY sourcing and build guidance, including buying components, ordering PCBs, printing parts, and programming the Teensy. Keep availability and shipping arrangements on the [ARC-210 parts offers page](ARC-210-Parts-Offers.md) up to date so builders can compare my complete sets with manufacturer minimum orders. Keep the files available for builders who prefer to order their own boards.
6. Design and print a USB cable strain-relief support to protect the Teensy's Micro-B connector from cable pulls.
7. Add [C-130J support](C-130J-Support.md) using the existing ARC-210 hardware and one shared code base: implement automatic aircraft selection so users can switch between supported aircraft without reflashing the Teensy, and test that switching behavior; verify the existing DCS-BIOS controls and frequency export; follow the [Helios-based LCD export plan](C-130J-Support.md#helios-findings-and-lcd-export-plan), starting by verifying indicator 44 in the installed module, capturing live indications, parsing them once per export cycle, adding named string outputs for the LCD/menu fields, and clearing fields that disappear between pages; check RT SELECT behavior; and complete firmware and menu changes, debug-app support, testing, and documentation. Document any unavailable display data.
8. **Assembly pictures:** When the manufactured PCBs arrive and I start building, take pictures throughout assembly for the Build Guide, including component placement, soldering, wiring, and mounting. Include clear photos of both sides of the Button Matrix PCB, showing the switches on the front and the diodes and pin connectors on the back, with the silkscreen markings visible. Add those photos to the Button Matrix PCB README too.
9. **Smaller PCB orders:** Investigate a way for builders to order one complete radio’s PCB set instead of the usual five copies of each design. Compare single-copy suppliers or order options with a combined manufacturing panel, checking minimum quantities, separation and mounting clearances, design fees, shipping, and the total delivered cost. Publish a verified ordering route if one is practical.
10. **SQL switch replacement pending:** I need to find and test a replacement because the SQL On/Off switch I’m currently using does not have the correct arc of movement for the panel. When I find a suitable replacement, I’ll announce it in [Project Updates](Project-Updates.md), update the [parts list](../parts/README.md), and revise any affected mounting or wiring notes.
