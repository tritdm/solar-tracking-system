#ifndef BATTERY_H
#define BATTERY_H
#include <Arduino.h>

void battery_calculator(int16_t &bav, float &vout, float &vcc, int8_t &percent);

#endif