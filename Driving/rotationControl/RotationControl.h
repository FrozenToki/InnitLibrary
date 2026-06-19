#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/Bno055/Bno055.h"
#include "PDController.h"


class ApplicationInnit; 


class RotationControl {
	public: 
		float getRotation(double s = 0);
		double angleError(double setpoint, double input);
		RotationControl(ApplicationInnit* a);

	private:
		double setpoint, input, output;
		ApplicationInnit* app;
		Bno055* bno; 

		PDController* pd;

		double kP = 1.5;
		double kI = 0.0;
		double kD = 2.0;
	};

