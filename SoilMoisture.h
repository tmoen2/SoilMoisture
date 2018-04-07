
#ifndef SoilMoisture_H
#define SoilMoisture_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class SoilMoisture {
 private:
  uint8_t _pin;

 public:
	SoilMoisture(uint8_t pin);
  	int readSoil(int soilPower);
	int action(int soilVal, int needWater, int Green, int Yellow, int Red);
};
#endif
