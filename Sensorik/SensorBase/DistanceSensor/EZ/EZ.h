#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/DistanceSensor/DistanceSensor.h"

class EZ : public DistanceSensor {
	private: 
		int pin;
	public:
		EZ(int p, String n, ApplicationInnit* a);
		void update() override;
		float rawData() override;
		
};