#ifndef TFT_H
#define TFT_H
#include <Arduino.h>
#include <TFT_22_ILI9225.h>
#include "rtc.h"


//int16_t hr = 0, min = 0, sec = 0, day = 0, mth = 0, yr = 0, dow = 0;

//char days_of_week[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void tft_init(TFT_22_ILI9225 &tft);
void tft_print(TFT_22_ILI9225 &tft, int8_t percent, int16_t hr, int16_t min, int16_t sec, int16_t day, int16_t mth, int16_t yr, int16_t dow);
#endif