#include "SensorBase.h"

SensorBase::SensorBase(int p, String n, ApplicationInnit* a) : pin(p), value(0.0f), name(n), app(a){}

String SensorBase::BUTTON = "Btn";
String SensorBase::BNO055 = "Gyro";

float SensorBase::readSensor() {
	this->update();
	return this->rawData();
}

int SensorBase::getPin() const {
	return pin;
}

int& SensorBase::getPinRef() {
	return pin;
}

String& SensorBase::getNameRef() {
	return name;
}

String SensorBase::getName() const {
	return name;
}

String SensorBase::getType() const {
	return type;
}
