#include "IrSensors.h"

IrSensor::IrSensor(int p, String n, float a, ApplicationInnit* b) : SensorBase(n, b), angle(a), pin(p) {
	pinMode(p, INPUT_PULLUP);
}

float IrSensor::getAngle() {
	return angle;
}

void IrSensor::setAvrgAngle(float v) {
	avrgAngle = v;
}

float IrSensor::getAvrgAngle() {
	return avrgAngle;
}


void IrSensor::update() {
	if (digitalRead(pin) == LOW) {
		value++;
	}
}

float IrSensor::rawData() {
	return value;
}

void IrSensor::resetValue() {
	value = 0.0f;
}

float IrSensor::getCalculatedValue(){
	return calculatedValue;
}

void IrSensor::setCalculatedValue(float v) {
	calculatedValue = v;
}

Vector IrSensor::getVector() {
	return vec;
}

void IrSensor::setVector(const Vector& v) {
	vec = v;
}