#ifndef PROCESS_H
#define PROCESS_H
#include <Arduino.h>
#include <Servo.h>

void process(int16_t &servoH_pos, int16_t &servoV_pos, int16_t lightE, int16_t lightW, int16_t lightS, int16_t lightN);
#endif