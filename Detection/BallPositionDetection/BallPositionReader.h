#pragma once
#include "Arduino.h"
#include "Math/Vector/Vector.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include "MovingAverage/MovingAverage.h"
#include "InnitConfig/Config.h"
#include <vector>


// forward declaration
class ApplicationInnit;

class BallPositionReader {
private: 

	std::vector<IrSensor*> irSensList;
	std::vector<float> valueList;
	std::vector<IrSensor*> hightestSensors;
	ApplicationInnit* app;

	Vector ballVector;

	std::vector<MovingAverage*> highSensAngleAvrg;
	std::vector<MovingAverage*> highSensValAvrg;

	size_t irSensCount;

public: 
	BallPositionReader(ApplicationInnit* a);
	void initializeBallPositionReader(size_t irSensorCount);
	
	void setValues();
	
	std::vector<float> getValues();
	
	void setHighestSensor();
	
	std::vector<IrSensor*> getHighestSensors();
	
	void setHighestSensVec();
	void addHighestSensVec();

	Vector getBallVector();
};