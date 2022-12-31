#include "sensors.h"
#include "rtc.h"
#include "process.h"
#include "servos.h"
#include "tft.h"
#include "battery.h"

#define TFT_RST 6
#define TFT_RS  5
#define TFT_CS  7  // SS
#define TFT_SDI 4  // MOSI
#define TFT_CLK 3  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

// define TFT brightness
#define TFT_BRIGHTNESS 200 

// hardware SPI (faster - on Uno: 13-SCK, 12-MISO, 11-MOSI)
//TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);
// software SPI (slower)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS);

uRTCLib rtc(0x68);

Servo servoH, servoV;

const int8_t  servoH_pin = 10, servoV_pin = 11, 
              // servo control pins    
              p_resE = A0,    p_resW = A1, 
              p_resS = A2,    p_resN = A3;
              // photoresistor value read pins
    
float vout, vcc;
int8_t percent = 50;
    // voltage and percentage of battery

int16_t servoH_pos = 90, servoV_pos = 90,
    // servo position
    lightE, lightW, lightS, lightN,
    // photoresistor value
    hr, min, sec, day, mth, yr, dow,
    bav;
    // battery analog value

void value_tester();

void process_input() {
  rtc_read(rtc, hr, min, sec, day, mth, yr, dow);
  sensor_read(lightE, lightW, lightS, lightN, p_resE, p_resW, p_resS, p_resN);
}

void application() {
  process(servoH_pos, servoV_pos, lightE, lightW, lightS, lightN);
  //battery_calculator(bav, vout, vcc, percent);
}

void process_output() {
  if (sec == 0) tft_print(tft, percent, hr, min, sec, day, mth, yr, dow);
  servo_control(servoH, servoV, servoH_pos, servoV_pos);
}

void setup() {
  Serial.begin(9600);
  
  rtc_init(rtc, 10, 55, 0, 24, 12, 22, 7);
  servo_setup(servoH, servoH_pin, servoH_pos, servoV, servoV_pin, servoV_pos);
  tft_init(tft);
  
  rtc_read(rtc, hr, min, sec, day, mth, yr, dow);
  tft_print(tft, percent, hr, min, sec, day, mth, yr, dow);
}

void loop() {
  process_input();
  application();
  process_output();
  //value_tester();
}

// print value to test function
void value_tester() {
  // print light intensity values
  Serial.print("dong: ");
  Serial.println(lightE); 
  Serial.print("tay: ");
  Serial.println(lightW); 
  Serial.print("nam: ");
  Serial.println(lightS); 
  Serial.print("bac: ");
  Serial.println(lightN);
  // print servo positions 
  Serial.print("goc doc: ");
  Serial.println(servoV_pos);
  Serial.print("goc ngang: ");
  Serial.println(servoH_pos);
  // print time
  Serial.print("Current Date & Time: ");
  Serial.print(yr);
  Serial.print('/');
  Serial.print(mth);
  Serial.print('/');
  Serial.print(day);
  Serial.print(" (");
  //Serial.print(days_of_week[dow]);
  Serial.print(") ");
  Serial.print(hr);
  Serial.print(':');
  Serial.print(min);
  Serial.print(':');
  Serial.println(sec);
  // print temperature
  Serial.print("Temperature: ");
  Serial.print(rtc.temp()  / 100);
  Serial.print("\xC2\xB0");   //shows degrees character
  Serial.println("C");
}

