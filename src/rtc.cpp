#include "rtc.h"

void rtc_init(uRTCLib &rtc, int16_t hr, int16_t min, int16_t sec, int16_t day, int16_t mth, int16_t yr, int16_t dow) 
{
    URTCLIB_WIRE.begin();                                     /* set up RTC */
    rtc.set(sec, min, hr, dow, day, mth, yr);                 /* set up time (second, minute, hour, dayOfWeek, dayOfMonth, month, year)*/
}

void rtc_read(uRTCLib &rtc, int16_t &hr, int16_t &min, int16_t &sec, int16_t &day, int16_t &mth, int16_t &yr, int16_t &dow) 
{
    rtc.refresh();
    yr = rtc.year();
    mth = rtc.month();
    day = rtc.day();
    dow = rtc.dayOfWeek() - 1;
    hr = rtc.hour();
    min = rtc.minute();
    sec = rtc.second();
}


