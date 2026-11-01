#include <Arduino.h>
#include <ILI9488_t3.h>

#include "ARC210Font.h"


// ==================================================
// TFT OBJECT
//
// The actual TFT object is created in Display.cpp.
// This lets the font routines use that same display.
// ==================================================
extern ILI9488_t3 tft;


// ==================================================
// ARC-210 5x7 OCR / AVIONICS STYLE FONT
//
// Each glyph contains 7 rows.
// The lower 5 bits of each byte form the pixels.
// ==================================================


// ==================================================
// SPACE
// ==================================================
static const uint8_t GLYPH_SPACE[7] =
{
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};


// ==================================================
// LETTERS A-Z
// ==================================================
static const uint8_t GLYPH_A[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b11111,
    0b10001,
    0b10001,
    0b10001
};

static const uint8_t GLYPH_B[7] =
{
    0b11110,
    0b10001,
    0b10001,
    0b11110,
    0b10001,
    0b10001,
    0b11110
};

static const uint8_t GLYPH_C[7] =
{
    0b01111,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b01111
};

static const uint8_t GLYPH_D[7] =
{
    0b11110,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b11110
};

static const uint8_t GLYPH_E[7] =
{
    0b11111,
    0b10000,
    0b10000,
    0b11110,
    0b10000,
    0b10000,
    0b11111
};

static const uint8_t GLYPH_F[7] =
{
    0b11111,
    0b10000,
    0b10000,
    0b11110,
    0b10000,
    0b10000,
    0b10000
};

static const uint8_t GLYPH_G[7] =
{
    0b01111,
    0b10000,
    0b10000,
    0b10111,
    0b10001,
    0b10001,
    0b01111
};

static const uint8_t GLYPH_H[7] =
{
    0b10001,
    0b10001,
    0b10001,
    0b11111,
    0b10001,
    0b10001,
    0b10001
};

static const uint8_t GLYPH_I[7] =
{
    0b11111,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b11111
};

static const uint8_t GLYPH_J[7] =
{
    0b00111,
    0b00010,
    0b00010,
    0b00010,
    0b10010,
    0b10010,
    0b01100
};

static const uint8_t GLYPH_K[7] =
{
    0b10001,
    0b10010,
    0b10100,
    0b11000,
    0b10100,
    0b10010,
    0b10001
};

static const uint8_t GLYPH_L[7] =
{
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b11111
};

static const uint8_t GLYPH_M[7] =
{
    0b10001,
    0b11011,
    0b10101,
    0b10101,
    0b10001,
    0b10001,
    0b10001
};

static const uint8_t GLYPH_N[7] =
{
    0b10001,
    0b11001,
    0b10101,
    0b10011,
    0b10001,
    0b10001,
    0b10001
};

static const uint8_t GLYPH_O[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};

static const uint8_t GLYPH_P[7] =
{
    0b11110,
    0b10001,
    0b10001,
    0b11110,
    0b10000,
    0b10000,
    0b10000
};

static const uint8_t GLYPH_Q[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10101,
    0b10010,
    0b01101
};

static const uint8_t GLYPH_R[7] =
{
    0b11110,
    0b10001,
    0b10001,
    0b11110,
    0b10100,
    0b10010,
    0b10001
};

static const uint8_t GLYPH_S[7] =
{
    0b01111,
    0b10000,
    0b10000,
    0b01110,
    0b00001,
    0b00001,
    0b11110
};

static const uint8_t GLYPH_T[7] =
{
    0b11111,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100
};

static const uint8_t GLYPH_U[7] =
{
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};

static const uint8_t GLYPH_V[7] =
{
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01010,
    0b00100
};

static const uint8_t GLYPH_W[7] =
{
    0b10001,
    0b10001,
    0b10001,
    0b10101,
    0b10101,
    0b10101,
    0b01010
};

static const uint8_t GLYPH_X[7] =
{
    0b10001,
    0b10001,
    0b01010,
    0b00100,
    0b01010,
    0b10001,
    0b10001
};

static const uint8_t GLYPH_Y[7] =
{
    0b10001,
    0b10001,
    0b01010,
    0b00100,
    0b00100,
    0b00100,
    0b00100
};

static const uint8_t GLYPH_Z[7] =
{
    0b11111,
    0b00001,
    0b00010,
    0b00100,
    0b01000,
    0b10000,
    0b11111
};


// ==================================================
// NUMBERS 0-9
// ==================================================

static const uint8_t GLYPH_0[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};

static const uint8_t GLYPH_1[7] =
{
    0b00100,
    0b01100,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b01110
};

static const uint8_t GLYPH_2[7] =
{
    0b01110,
    0b10001,
    0b00001,
    0b00010,
    0b00100,
    0b01000,
    0b11111
};

static const uint8_t GLYPH_3[7] =
{
    0b11110,
    0b00001,
    0b00001,
    0b01110,
    0b00001,
    0b00001,
    0b11110
};

static const uint8_t GLYPH_4[7] =
{
    0b00010,
    0b00110,
    0b01010,
    0b10010,
    0b11111,
    0b00010,
    0b00010
};

static const uint8_t GLYPH_5[7] =
{
    0b11111,
    0b10000,
    0b10000,
    0b11110,
    0b00001,
    0b00001,
    0b11110
};

static const uint8_t GLYPH_6[7] =
{
    0b01110,
    0b10000,
    0b10000,
    0b11110,
    0b10001,
    0b10001,
    0b01110
};

static const uint8_t GLYPH_7[7] =
{
    0b11111,
    0b00001,
    0b00010,
    0b00100,
    0b01000,
    0b01000,
    0b01000
};

static const uint8_t GLYPH_8[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b01110,
    0b10001,
    0b10001,
    0b01110
};

static const uint8_t GLYPH_9[7] =
{
    0b01110,
    0b10001,
    0b10001,
    0b01111,
    0b00001,
    0b00001,
    0b01110
};


// ==================================================
// PUNCTUATION
// ==================================================
static const uint8_t GLYPH_PERIOD[7] =
{
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00110,
    0b00110
};

static const uint8_t GLYPH_COLON[7] =
{
    0b00000,
    0b00110,
    0b00110,
    0b00000,
    0b00110,
    0b00110,
    0b00000
};

static const uint8_t GLYPH_DASH[7] =
{
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b00000,
    0b00000,
    0b00000
};


// ==================================================
// GET GLYPH FOR CHARACTER
// ==================================================
static const uint8_t* getGlyph(char c)
{
    switch (c)
    {
        case 'A': return GLYPH_A;
        case 'B': return GLYPH_B;
        case 'C': return GLYPH_C;
        case 'D': return GLYPH_D;
        case 'E': return GLYPH_E;
        case 'F': return GLYPH_F;
        case 'G': return GLYPH_G;
        case 'H': return GLYPH_H;
        case 'I': return GLYPH_I;
        case 'J': return GLYPH_J;
        case 'K': return GLYPH_K;
        case 'L': return GLYPH_L;
        case 'M': return GLYPH_M;
        case 'N': return GLYPH_N;
        case 'O': return GLYPH_O;
        case 'P': return GLYPH_P;
        case 'Q': return GLYPH_Q;
        case 'R': return GLYPH_R;
        case 'S': return GLYPH_S;
        case 'T': return GLYPH_T;
        case 'U': return GLYPH_U;
        case 'V': return GLYPH_V;
        case 'W': return GLYPH_W;
        case 'X': return GLYPH_X;
        case 'Y': return GLYPH_Y;
        case 'Z': return GLYPH_Z;

        case '0': return GLYPH_0;
        case '1': return GLYPH_1;
        case '2': return GLYPH_2;
        case '3': return GLYPH_3;
        case '4': return GLYPH_4;
        case '5': return GLYPH_5;
        case '6': return GLYPH_6;
        case '7': return GLYPH_7;
        case '8': return GLYPH_8;
        case '9': return GLYPH_9;

        case '.': return GLYPH_PERIOD;
        case ':': return GLYPH_COLON;
        case '-': return GLYPH_DASH;

        default:  return GLYPH_SPACE;
    }
}


// ==================================================
// DRAW ONE CHARACTER
// ==================================================
static void drawOCRChar(
    int16_t x,
    int16_t y,
    char c,
    uint8_t scale,
    uint16_t color)
{
    const uint8_t* glyph = getGlyph(c);

    // Overall character cell spacing
    uint8_t cellX = scale;
    uint8_t cellY = scale;

    // Actual stroke thickness
    uint8_t strokeX = scale;
    uint8_t strokeY = scale;

    // Make strokes thinner without shrinking layout
    if (scale >= 3)
    {
        strokeX = scale - 1;
        strokeY = scale - 1;
    }

    for (uint8_t row = 0; row < 7; row++)
    {
        for (uint8_t col = 0; col < 5; col++)
        {
            if (glyph[row] & (1 << (4 - col)))
            {
                tft.fillRect(
                    x + (col * cellX),
                    y + (row * cellY),
                    strokeX,
                    strokeY,
                    color
                );
            }
        }
    }
}

// ==================================================
// DRAW STRING
// ==================================================
void drawOCRText(
    int16_t x,
    int16_t y,
    const char* text,
    uint8_t scale,
    uint16_t color)
{
    if (text == nullptr || scale == 0)
    {
        return;
    }

    // 5 pixels for the glyph plus one pixel spacing.
	uint8_t widthScale = scale;

		if (scale > 1)
	{
		widthScale = scale - 1;
	}

	const int16_t advance = 6 * widthScale;
    
	while (*text)
    {
        drawOCRChar(
            x,
            y,
            *text,
            scale,
            color
        );

        x += advance;

        text++;
    }
}


// ==================================================
// GET STRING WIDTH
// ==================================================
int16_t getOCRTextWidth(
    const char* text,
    uint8_t scale)
{
    if (text == nullptr || scale == 0)
    {
        return 0;
    }

    size_t length = strlen(text);

    if (length == 0)
    {
        return 0;
    }

    // Each character advances 6 pixels, but the final
    // character does not really need the trailing gap.
	uint8_t widthScale = scale;

	if (scale > 1)
	{
		widthScale = scale - 1;
	}

	return ((length * 6) - 1) * widthScale;}