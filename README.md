# Solar Tracking System using Arduino Uno R3 with Platformio
## This is my Embedded System Design Project (CE224 in UIT).
Because this course encourage people to use as most protocol as they can, so it has some uneccessary files (libraries & sources).
## System components
Sensors files (sensors.h & sensors.cpp) are used to read photoresistors. \
Servos files (servos.h & servos.cpp) are used to controll servos. \
Process files (process.h & process.cpp) are used to combine function of sensors & servos files to operate system.
## Other components 
RTC files (rtc.h & rtc.cpp) are used to communicate with DS3231 for RTC applications. \
TFT files (tft.h & tft.cpp) are used to show on TFT ILI9225 for applications need show information. \
Battery files (battery.h & battery.cpp) are used to detect battery for battery applications.