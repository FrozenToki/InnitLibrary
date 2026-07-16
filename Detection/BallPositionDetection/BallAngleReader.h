#pragma once
#include "Arduino.h"
#include "Math/Vector/Vector.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include "MovingAverage/MovingAverage.h"
#include "InnitConfig/Config.h"
#include <vector>
#include <cmath>


// forward declaration
class ApplicationInnit;

class BallAngleReader {
private: 

	std::vector<IrSensor*> irSensList;
	std::vector<float> valueList;
	std::vector<IrSensor*> hightestSensors;
	ApplicationInnit* app;

	Vector ballVector;

	Vector emaBallVector;

	std::vector<MovingAverage*> highSensAngleAvrg;
	std::vector<MovingAverage*> highSensValAvrg;

	size_t irSensCount;

	bool emaInitialized = false;

public: 
	BallAngleReader(ApplicationInnit* a);
	void initializeBallAngleReader(size_t irSensorCount);
	
	void setValues();
	
	std::vector<float> getValues();
	
	void setHighestSensor(int numberOfHighestSensor);
	
	std::vector<IrSensor*> getHighestSensors();
	
	void setHighestSensVec();
	void addHighestSensVec();

	Vector getBallVector();
	Vector getEmaBallVector();
};