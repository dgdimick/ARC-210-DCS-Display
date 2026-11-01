#include <Arduino.h>

#include "MenuNavigation.h"
#include "MenuState.h"
#include "MenuHQ.h"
#include "MenuComsec.h"
#include "MenuRadioSettings.h"
#include "DcsCallbacks.h"

#include <Display.h>

static unsigned long comsecLoadStarted = 0;
static constexpr unsigned long comsecConfirmationDurationMs = 1500UL;

bool isArc210MenuActive()
{
    return menuActive;
}

void resetArc210Menu()
{
    resetArc210MenuState();
}

static void exitMenuToRadio()
{
    resetArc210Menu();
    updateRadioDisplay();
}

void updateArc210Menu()
{
    if (menuActive && currentMenuPage == ARC210_MENU_COMSEC_LOAD &&
        millis() - comsecLoadStarted >= comsecConfirmationDurationMs)
        exitMenuToRadio();
}

static void showMainMenu()
{
    menuActive = true;
    currentMenuPage = ARC210_MENU_MAIN;
    showMenuScreen();
}

void onArc210MenuPress()
{
    if (menuActive)
    {
        // A0 is the single screen listing HQ / COMSEC / RADIO SETTINGS.
        // MENU is a dead key on A1 and every other page below A0.
        if (currentMenuPage == ARC210_MENU_MAIN)
            exitMenuToRadio();
        return;
    }
    showMainMenu();
}

void onArc210XmtRcvPress()
{
    if (!menuActive) return;
    menuRadioShowXmtRcvTest();
}

void onArc210UpperLskPress()
{
    if (!menuActive) return;

    if (currentMenuPage == ARC210_MENU_MAIN)
    {
        currentMenuPage = ARC210_MENU_HQ;
        showHQMenusScreen();
        return;
    }

    Arc210MenuPage before = currentMenuPage;
    if (menuComsecHandleUpper())
    {
        if (before == ARC210_MENU_COMSEC) exitMenuToRadio();
        else if (before != ARC210_MENU_COMSEC_LOAD)
        {
            currentMenuPage = ARC210_MENU_COMSEC_LOAD;
            comsecLoadStarted = millis();
            // DIGITAL/ANALOG DATA uses DAMA; every other COMSEC page uses LOS.
            showComsecLoadScreen(before == ARC210_MENU_COMSEC_LOS_MORE_4);
        }
        return;
    }
    before = currentMenuPage;
    if (menuRadioHandleUpper())
    {
        if (before == ARC210_MENU_RADIO_SWITCH_TEST ||
            (before >= ARC210_MENU_RADIO_SETTINGS && before <= ARC210_MENU_RADIO_MORE_6))
            exitMenuToRadio();
        return;
    }
    if (menuHQHandleUpper())
    {
        exitMenuToRadio();
        return;
    }
}

void onArc210MiddleLskPress()
{
    if (!menuActive) return;

    if (currentMenuPage == ARC210_MENU_MAIN)
    {
        damaSatcomComsecSelected = false;
        menuComsecShowMain();
        return;
    }

    if (menuRadioHandleMiddle()) return;
    if (menuComsecHandleMiddle()) return;
    if (menuHQHandleMiddle()) return;
}

void onArc210LowerLskPress()
{
    if (!menuActive) return;

    if (currentMenuPage == ARC210_MENU_MAIN)
    {
        currentMenuPage = ARC210_MENU_RADIO_SETTINGS;
        showRadioSettingsScreen();
        return;
    }

    if (menuRadioHandleLower()) return;
    if (menuComsecHandleLower()) return;
    if (menuHQHandleLower()) return;
}
