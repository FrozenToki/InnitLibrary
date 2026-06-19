#pragma once
#include <Arduino.h>

class ApplicationInnit;
class ButtonCross;
class IrSensor;
class IrRing;

class Calibration {
private:
	ApplicationInnit* app;

	ButtonCross* buttonC;
	IrSensor* irL;
	IrSensor* irR;
	IrRing* ring;

public:
	Calibration(ApplicationInnit* a);

	void setButtonCross(ButtonCross* button);
	void setIrSensors(IrSensor* left, IrSensor* right);
	void setIrRing(IrRing* ringPtr);

	void calibrateIrSensors();
	void calibrateIrRing();
};