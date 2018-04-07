#include "SoilMoisture.h"

SoilMoisture::SoilMoisture(uint8_t pin) {
	_pin = pin;
}

int SoilMoisture::readSoil(int soilPower)
{
    digitalWrite(soilPower, HIGH);//turn sensor "On"
    delay(10);//wait 10 milliseconds 
    float soilVal = analogRead(_pin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn sensor "Off"
    return soilVal;//send current moisture value
}
									
									// needWater (Low limit)
int SoilMoisture::action(int soilVal, int needWater, int Green, int Yellow, int Red)	
{
	bool greaterThan = false;
	bool lessThan = false;
	bool warning = false;

	if(soilVal >= needWater + 20){
		greaterThan = true;
		lessThan = false;
		warning = false;
	}
	if( soilVal < needWater){
		greaterThan = false;
		lessThan = true;
		warning = false;
	}
	if( (soilVal <= needWater + 20) && (soilVal > needWater) ){
		greaterThan = false;
		lessThan = false;
		warning = true;
	}
	switch(greaterThan){
		case(true)  : digitalWrite(Green, HIGH); //Set Green light HIGH
		case(false) : digitalWrite(Green, LOW); //Set Green light LOW
	}
	switch(lessThan){
		case(true)  : digitalWrite(Red, HIGH); //Set Red light HIGH
		case(false) : digitalWrite(Red, LOW); //Set Red light Low
	}
	switch(warning){
		case(true) : digitalWrite(Yellow, HIGH); //Set Yellow light HIGH
		case(false): digitalWrite(Yellow, LOW); // Set Yellow light LOW
	}
	
}


