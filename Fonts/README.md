# Current ARC-210 display font

**Last updated: November 13, 2026 at 9:41 PM MST (America/Denver)**

I copied `SwanseaFontSimple.cpp` and `SwanseaFontSimple.h` from the working ARC210_Display library for the current menu-preview firmware. These replace the older FreeSans headers previously stored here.

The renderer uses the Swansea28 bitmap glyph table with fractional scaling:

| Display element | Scale |
| --- | --- |
| Menu labels, EXIT, MORE, RT1 and PREV | 1.25× |
| Large frequency and channel/segment numbers | 3× |
| CT / CT-TD key number | 2× |
| Extra-long menu labels | 1× when needed to fit |

These are rendering scales, not point sizes. The files depend on Arduino and ILI9488_t3 and use the display library's global `tft` object; they are not standalone desktop font files or Adafruit GFX font headers.

The precompiled HEX already includes the fonts. These source files are only needed if you’re building or changing the firmware.

## Estimated build cost

If you’re thinking about building one, the [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. I’ve included the files and build notes to help you put it together.

## Questions and community builds

If you have questions, ideas, or photos of your build, I’d love to hear from you. [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)
