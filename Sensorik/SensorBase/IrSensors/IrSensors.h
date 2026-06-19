#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"
#include "math/Vector/Vector.h"

class IrSensor : public SensorBase {
private:
	int pin;
	float angle;
	float avrgAngle;
	float calculatedValue;
	Vector vec;
public:
	IrSensor(int p, String n, float a, ApplicationInnit* b);
	void update() override;
	float rawData() override;
	float getCalculatedValue();
	void setCalculatedValue(float v);
	void resetValue();

	void setVector(const Vector& v);
	Vector getVector();

	float getAngle();

	void setAvrgAngle(float v);
	float getAvrgAngle();
};  