#pragma once
#include <Arduino.h>
#include <vector>
#include "Sensorik/SensorBase/SensorBase.h"

class ApplicationInnit;

class ButtonCross : public SensorBase {
private:
	int press = -1;
	std::vector<float> setValues;
	float lastTime = 0;
	float waitTime = 20;

	int pin;

	int tolerance = 15;	
public: 	
	ButtonCross(String n, int p, float v1, float v2, float v3, float v4, float v5, ApplicationInnit* a);
	void update() override;
	float rawData() override;
	bool pressed(int i);
	int getPressedBtn();
};