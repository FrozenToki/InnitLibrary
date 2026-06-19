#pragma once
#include "Arduino.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include "InnitConfig/Config.h"

// forward declaration
class ApplicationInnit;

class IrSensorReader {
private:
	int lastReadingTime;
	ApplicationInnit* app;
 	IrSensor* irSensList[InnitConfig::COUNT_IR_SENSOR];
public:
	IrSensorReader(ApplicationInnit* a);
	void readAll(int ticks, bool time = false, long unsigned int timeInMicSec = 0);
	void setAll();
	void getAllValues(float array[]);
	float frequencyInMilSec(int timeInMicSec, float sensHits);
};