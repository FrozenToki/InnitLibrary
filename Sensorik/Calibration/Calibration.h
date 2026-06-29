#pragma once
#include <Arduino.h>
#include "Sensorik/SensorManager/SensorManager.h"

class ApplicationInnit;


class Calibration {
private:
	ApplicationInnit* app;

	ButtonCross* buttonC;
	IrSensor* irL;
	IrSensor* irR;
	SerialReciever* ring;

public:
	Calibration(ApplicationInnit* a);

	void setButtonCross(ButtonCross* button);
	void setIrSensors(IrSensor* left, IrSensor* right);
	void setIrRing(SerialReciever* ringPtr);

	void calibrateIrSensors();
	void calibrateIrRing();
};