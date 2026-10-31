#ifndef ARC210_FONT_H
#define ARC210_FONT_H

#include <Arduino.h>

void drawOCRText(
    int16_t x,
    int16_t y,
    const char* text,
    uint8_t scale,
    uint16_t color
);

int16_t getOCRTextWidth(
    const char* text,
    uint8_t scale
);

#endif