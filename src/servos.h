#ifndef SERVOS_H
#define SERVOS_H
#include <Arduino.h>
#include <Servo.h>

void servo_setup(Servo &servoH, const int8_t servoH_pin, const int16_t servoH_pos, Servo &servoV, int8_t servoV_pin, int16_t servoV_pos);
void servo_control(Servo &servoH, Servo &servoV, int16_t servoH_pos, int16_t servoV_pos);

#endif