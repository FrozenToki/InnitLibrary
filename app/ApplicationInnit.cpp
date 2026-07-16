#include "ApplicationInnit.h"

ApplicationInnit::ApplicationInnit() : sensorManager(this), sensorList(this), 
	outputManager(this), outputList(this), drivingControl(this),
	rotationControl(this), serialComm(this), geometry(this), 
	irSensorReader(this), menuManager(this), calibration(this), 
	ballAngleReader(this), ballDistanceReader(this) {} 

SensorList& ApplicationInnit::getSensorList() {
	return sensorList;
}

SensorManager& ApplicationInnit::getSensorManager() {
	return sensorManager;
}

OutputList& ApplicationInnit::getOutputList() {
	return outputList;
}

OutputManager& ApplicationInnit::getOutputManager() {
	return outputManager;
}

InnitConfig& ApplicationInnit::getConfig() {
	return config;
}

DrivingControl& ApplicationInnit::getDrivingControl() {
	return drivingControl;
}

RotationControl& ApplicationInnit::getRotationControl() {
	return rotationControl;
}

SerialValuePool &ApplicationInnit::getSerialValuePool() {
	return serialValuePool;
}

SerialComm &ApplicationInnit::getSerialComm()
{
	return serialComm;
}

Geometry& ApplicationInnit::getGeometry() {
	return geometry;
	
}

IrSensorReader& ApplicationInnit::getIrSensorReader() {
	return irSensorReader;
}

MenuManager& ApplicationInnit::getMenuManager() {
	return menuManager;
}

Calibration& ApplicationInnit::getCalibration() {
	return calibration;
}

BallAngleReader &ApplicationInnit::getBallAngleReader() {
 return ballAngleReader;
}

BallDistanceReader &ApplicationInnit::getBallDistanceReader() {
	return ballDistanceReader;
}
