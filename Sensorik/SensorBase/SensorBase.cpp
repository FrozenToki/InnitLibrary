#include "SensorBase.h"

SensorBase::SensorBase(String n, ApplicationInnit* a) : value(0.0f), name(n), app(a){}

float SensorBase::readSensor() {
	this->update();
	return this->rawData();
}

String& SensorBase::getNameRef() {
	return name;
}

String SensorBase::getName() const {
	return name;
}