# Current ARC-210 display font

The current menu-preview firmware uses `SwanseaFontSimple.cpp` and `SwanseaFontSimple.h`, copied from the working ARC210_Display library. These replace the older FreeSans headers previously stored here.

The renderer uses the Swansea28 bitmap glyph table with fractional scaling:

| Display element | Scale |
| --- | --- |
| Menu labels, EXIT, MORE, RT1 and PREV | 1.25× |
| Large frequency and channel/segment numbers | 3× |
| CT / CT-TD key number | 2× |
| Extra-long menu labels | 1× when needed to fit |

These are rendering scales, not point sizes. The files depend on Arduino and ILI9488_t3 and use the display library's global `tft` object; they are not standalone desktop font files or Adafruit GFX font headers.

Using the precompiled HEX? You’re all set—the fonts are already included. These source files are only needed if you’re building or changing the firmware.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
