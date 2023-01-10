// main process function
#include "process.h"

void process(int16_t &servoH_pos, int16_t &servoV_pos, int16_t lightE, int16_t lightW, int16_t lightS, int16_t lightN) 
{
    // process
    if (lightE - lightW > 130 && servoH_pos < 180) 
    {
        if (servoV_pos < 90) servoH_pos --;
        else servoH_pos ++;
    }
    if (lightW - lightE > 130 && servoH_pos > 0) 
    {
        if (servoV_pos < 90) servoH_pos ++;
        else servoH_pos --;
    }
    if (lightS - lightN > 130 && servoV_pos < 180) 
    {
        servoV_pos ++;
    }
    if (lightN - lightS > 130 && servoV_pos > 0) 
    {
        servoV_pos --;
    }
}
