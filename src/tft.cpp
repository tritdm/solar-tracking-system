#include "tft.h"

void tft_init(TFT_22_ILI9225 &tft) 
{
    tft.begin();
    tft.setOrientation(1);                                                          /* right rotated landscape */
    tft.setFont(Terminal6x8);                                                       /* set font wide 6px and high 8px */
}

void tft_print(TFT_22_ILI9225 &tft, int8_t percent, int16_t hr, int16_t min, int16_t sec, int16_t day, int16_t mth, int16_t yr, int16_t dow) 
{
    char days_of_week[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    String time1 = String(hr) + ':' + String(min) + ':' + String(sec);
    String time2 = String(days_of_week[dow]) + ", " + String(day) + '/' + String(mth) + '/' + String(2000 + yr);
    String time3 = time1 + ' ' + time2;
    String pc = String(percent) + "%";

    tft.drawText(98, 150, "Time");
    tft.drawText(20, 140, time3);
    tft.drawText(68, 130, "Battery percent");
    tft.fillRectangle(60, 120, 160, 110, COLOR_WHITE);
    tft.fillRectangle(60, 120, 60 + percent, 110, COLOR_BLUE);
    tft.drawText(101, 100, pc);
}
