#ifndef MENU_NAVIGATION_H
#define MENU_NAVIGATION_H

#include <Arduino.h>

bool isArc210MenuActive();
void resetArc210Menu();
void updateArc210Menu();

void onArc210MenuPress();
void onArc210UpperLskPress();
void onArc210MiddleLskPress();
void onArc210LowerLskPress();
void onArc210XmtRcvPress();

#endif
