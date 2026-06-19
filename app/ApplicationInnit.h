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
#include "Math/Geometry/Geometry.h"
#include "Sensorik/IrSensorReader/IrSensorReader.h"
#include "MenuManager/MenuManager.h"
#include "Sensorik/Calibration/Calibration.h"
#include "Serial/ValuePool/SerialValuePool.h"
#include "MovingAverage/MovingAverage.h"
#include "Detection/BallPositionDetection/BallPositionReader.h"

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

	IrSensorReader irSensorReader;

	MenuManager menuManager;

	Calibration calibration;

	BallPositionReader ballPositionReader;
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

	IrSensorReader& getIrSensorReader();

	MenuManager& getMenuManager();

	Calibration& getCalibration();

	BallPositionReader& getBallPositionReader();

	void softwareReset();

	ApplicationInnit();

};
	
