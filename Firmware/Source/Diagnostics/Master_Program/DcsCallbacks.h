#ifndef DCS_CALLBACKS_H
#define DCS_CALLBACKS_H

#include <Arduino.h>

void updateRadioDisplay();

void onArc210FrequencyChange(char* newValue);
void onArc210PreviousFrequencyChange(char* newValue);
void onArc210OperDateChange(char* newValue);
void onArc210SelectedRtChange(char* newValue);
void onArc210ActiveChannelChange(char* newValue);
void onArc210ModulationTextChange(char* newValue);
void onArc210ComsecSubmodeChange(char* newValue);
void onArc210XmitRecvChange(char* newValue);

void onKy58EncryptionChange(unsigned int newValue);
void onArc210KyLabelChange(char* newValue);

void onArc210SecSwChange(unsigned int newValue);
void onArc210MasterChange(unsigned int newValue);

// ARC-210 MENU / FSK BUTTON CALLBACKS
void onArc210MenuButtonChange(unsigned int newValue);
void onArc210XmtRcvButtonChange(unsigned int newValue);
void onArc210UpperLskChange(unsigned int newValue);
void onArc210MiddleLskChange(unsigned int newValue);
void onArc210LowerLskChange(unsigned int newValue);
void onHQChannelKnobChange(unsigned int value);
void onHQFreq100MChange(unsigned int value);
void onHQFreq10MChange(unsigned int value);
void onHQFreq1MChange(unsigned int value);
void onHQFreq100KChange(unsigned int value);
void onHQFreq25KChange(unsigned int value);

#endif
