#include "MenuState.h"

Arc210MenuPage currentMenuPage = ARC210_MENU_NONE;
bool menuActive = false;
bool damaSatcomComsecSelected = false;
uint8_t losDataModeIndex = 0; // KY-58 VOICE is the first selection.
bool radioPresetHalfDuplex = true;
bool radioDama41To50 = true;
bool radioBeepDisabled = false;
bool radioEnterDisabled = false;

void resetArc210MenuState()
{
    menuActive = false;
    currentMenuPage = ARC210_MENU_NONE;
    damaSatcomComsecSelected = false;
    // Keep the last KY/KG selection when leaving and reopening menus.
    radioPresetHalfDuplex = true;
    radioDama41To50 = true;
    radioBeepDisabled = false;
    radioEnterDisabled = false;
}

const char* currentLosDataModeLabel()
{
    switch (losDataModeIndex)
    {
        case 1: return "KY-58 DATA";
        case 2: return "KG-84 DATA";
        default: return "KY-58 VOICE";
    }
}
