#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"


class DistanceSensor : public SensorBase {
	public:
		DistanceSensor(String n, ApplicationInnit* a);
};