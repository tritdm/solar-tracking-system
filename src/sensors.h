#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

void sensor_read(int16_t &lightE, int16_t &lightW, int16_t &lightS, int16_t &lightN, 
                const int8_t p_resE, const int8_t p_resW, const int8_t p_resS, const int8_t p_resN);
#endif