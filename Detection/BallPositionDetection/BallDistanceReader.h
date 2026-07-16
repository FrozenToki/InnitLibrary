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

class BallDistanceReader {
private: 

	std::vector<IrSensor*> irSensList;
	std::vector<IrSensor*> hightestSensors;
	ApplicationInnit* app;

	float averageDistance;

	float smoothedAverageDistance;

	size_t irSensCount;
public: 
	BallDistanceReader(ApplicationInnit* a);
	void initializeBallDistReader(size_t irSensorCount);
	
	float getAverageDistance();
	float getSmoothedAverageDistance();
	
	void setHighestSensor(int numberOfHighestSensor);
	
	std::vector<IrSensor*> getHighestSensors();

};