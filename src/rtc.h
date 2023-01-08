#ifndef RTC_H
#define RTC_H
#include <Arduino.h>
#include <uRTCLib.h>

void rtc_init(uRTCLib &rtc, int16_t hr, int16_t min, int16_t sec, int16_t day, int16_t mth, int16_t yr, int16_t dow);
void rtc_read(uRTCLib &rtc, int16_t &hr, int16_t &min, int16_t &sec, int16_t &day, int16_t &mth, int16_t &yr, int16_t &dow);
#endif
