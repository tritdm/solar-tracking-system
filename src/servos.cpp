#include "servos.h"

void servo_setup(Servo &servoH, const int8_t servoH_pin, int16_t servoH_pos, Servo &servoV, const int8_t servoV_pin, int16_t servoV_pos) {
  servoH.attach(servoH_pin);
  servoV.attach(servoV_pin);
  servoH.write(servoH_pos);
  servoV.write(servoV_pos);
}

void servo_control(Servo &servoH, Servo &servoV, int16_t servoH_pos, int16_t servoV_pos) {
  servoH.write(servoH_pos);
  delay(15);
  servoV.write(servoV_pos);
  delay(15);
}