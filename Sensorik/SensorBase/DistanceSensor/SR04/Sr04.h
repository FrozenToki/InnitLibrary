#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/DistanceSensor/DistanceSensor.h"



class Sr04 : public DistanceSensor {
	private: 
		int pinTrig;
		int pinEcho;
	public:
		Sr04(int pinT, int pinE, String n, ApplicationInnit* a);
		void update() override;
		float rawData() override;
		
};