#ifndef TFT_H
#define TFT_H
#include <Arduino.h>
#include <TFT_22_ILI9225.h>
#include "rtc.h"

void tft_init(TFT_22_ILI9225 &tft);
void tft_print(TFT_22_ILI9225 &tft, int8_t percent, int16_t hr, int16_t min, int16_t sec, int16_t day, int16_t mth, int16_t yr, int16_t dow);
#endif
