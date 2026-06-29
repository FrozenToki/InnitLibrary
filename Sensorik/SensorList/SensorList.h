#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h" 
#include "InnitConfig/Config.h"

// forward declaration
class SensorBase;
class ApplicationInnit;

// Used to save all sensors and access them easily.
class SensorList {
private:
	ApplicationInnit* app;
	SensorBase* sensorList[InnitConfig::MAX_SENSORS];
	int sensorCount;
public:
	SensorList(ApplicationInnit* a);
	void addSensor(SensorBase* s);
	SensorBase* getSensorByName(const String& n);
	//SensorBase* getSensorByAngle(float angle);
	SensorBase* get(int index);
	int getSensorCount();

	void updateAllSensors();
};