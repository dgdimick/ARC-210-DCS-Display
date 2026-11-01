#include "MenuHQ.h"
#include "MenuState.h"
#include <Display.h>

// Confirmed A-page loop: 1A, 2A, 3A, 4A, 5A, 6A, then 2A.
bool menuHQHandleUpper()
{
    return currentMenuPage >= ARC210_MENU_HQ && currentMenuPage <= ARC210_MENU_HQ_MORE_18;
}

bool menuHQHandleMiddle()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_HQ: currentMenuPage=ARC210_MENU_OPER_DATE_LOAD; showOperDateLoadScreen(); return true;
        case ARC210_MENU_HQ_MORE_1: currentMenuPage=ARC210_MENU_VERIFY_WOD_MWOD; showVerifyWodMwodScreen(); return true;
        case ARC210_MENU_HQ_MORE_2: currentMenuPage=ARC210_MENU_HQ_WOD_LOAD; showHQWodLoadScreen(); return true;
        case ARC210_MENU_HQ_MORE_3: currentMenuPage=ARC210_MENU_HQ_WOD_ERASE; showHQWodEraseScreen(); return true;
        case ARC210_MENU_HQ_MORE_4: currentMenuPage=ARC210_MENU_HQ_FMT_LOAD; showHQFmtLoadScreen(); return true;
        case ARC210_MENU_HQ_MORE_5: currentMenuPage=ARC210_MENU_HQ_OPER_DATE_6B; showOperDateLoadScreen(); return true;
        case ARC210_MENU_HQ_WOD_LOAD:
            // DCS increments the WOD number on MLSK. The live 0x1338 export
            // redraws it; do not add a local increment that could count twice.
            return true;
        // Other B-page MLSK actions remain deferred.
        default: return menuHQHandleUpper();
    }
}

bool menuHQHandleLower()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_HQ: currentMenuPage=ARC210_MENU_HQ_MORE_1; showHQMore1Screen(); return true;
        case ARC210_MENU_HQ_MORE_1: currentMenuPage=ARC210_MENU_HQ_MORE_2; showHQMore2Screen(); return true;
        case ARC210_MENU_HQ_MORE_2: currentMenuPage=ARC210_MENU_HQ_MORE_3; showHQMore3Screen(); return true;
        case ARC210_MENU_HQ_MORE_3: currentMenuPage=ARC210_MENU_HQ_MORE_4; showHQMore4Screen(); return true;
        case ARC210_MENU_HQ_MORE_4: currentMenuPage=ARC210_MENU_HQ_MORE_5; showHQMore5Screen(); return true;
        case ARC210_MENU_HQ_MORE_5: currentMenuPage=ARC210_MENU_HQ_MORE_1; showHQMore1Screen(); return true;
        // OPER. DATE is a label. Erase YES result is not yet documented.
        default: return menuHQHandleUpper();
    }
}
