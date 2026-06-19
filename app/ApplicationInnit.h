#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"
#include "Sensorik/SensorManager/SensorManager.h"
#include "Sensorik/SensorList/SensorList.h"
#include "Outputs/OutputManager/OutputManger.h"
#include "Outputs/OutputList/OutputList.h"
#include "InnitConfig/Config.h"
#include "Driving/drivingControl/DrivingControl.h"
#include "Serial/SerialComm.h"
#include "Driving/rotationControl/RotationControl.h"
#include "Geometry/Geometry.h"
#include "loops/loops.h"
#include "Sensorik/IrSensorReader/IrSensorReader.h"
#include "MenuManager/MenuManager.h"
#include "Sensorik/Calibration/Calibration.h"
#include "Serial/ValuePool/SerialValuePool.h"

// Used to get acces to all the parts of the library from anywhere in the programm.
// It has instances of all the different main parts of the library.
class ApplicationInnit {
private:
	SensorManager sensorManager;
	SensorList sensorList;

	OutputManager outputManager;
	OutputList outputList;

	InnitConfig config;

	DrivingControl drivingControl;
	RotationControl rotationControl;

	SerialValuePool serialValuePool;
	SerialComm serialComm;

	Geometry geometry;

	Loops loops;

	IrSensorReader irSensorReader;

	MenuManager menuManager;

	Calibration calibration;
public:
	SensorList& getSensorList();
	SensorManager& getSensorManager();
	
	OutputList& getOutputList();
	OutputManager& getOutputManager();

	InnitConfig& getConfig();

	DrivingControl& getDrivingControl();
	RotationControl& getRotationControl();

	SerialValuePool& getSerialValuePool();
	SerialComm& getSerialComm();

	Geometry& getGeometry();

	Loops& getLoops();

	IrSensorReader& getIrSensorReader();

	MenuManager& getMenuManager();

	Calibration& getCalibration();

	void softwareReset();

	ApplicationInnit();

};
	
