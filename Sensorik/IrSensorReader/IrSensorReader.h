#pragma once
#include "Arduino.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include <vector>


// forward declaration
class ApplicationInnit;

class IrSensorReader {
private:
	int lastReadingTime;
	ApplicationInnit* app;
 	std::vector<IrSensor*> irSensList;
	int irSensCount;
public:
	IrSensorReader(ApplicationInnit* a);
	void initializeIrSensorReader(int IrSensorCount);
	void readAll(int ticks, bool time = false, long unsigned int timeInMicSec = 0);
	void setAll();
	void getAllValues(float array[]);
	float frequencyInMilSec(int timeInMicSec, float sensHits);
};