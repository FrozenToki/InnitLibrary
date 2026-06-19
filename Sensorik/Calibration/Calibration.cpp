#include "Calibration.h"
#include "app/ApplicationInnit.h"

Calibration::Calibration(ApplicationInnit *a) : app(a), buttonC(nullptr), irL(nullptr), irR(nullptr), ring(nullptr) {}

void Calibration::setButtonCross(ButtonCross* button) {
	buttonC = button;
}

void Calibration::setIrSensors(IrSensor* left, IrSensor* right) {
	irL = left;
	irR = right;
}

void Calibration::setIrRing(IrRing* ringPtr) {
	ring = ringPtr;
}

void Calibration::calibrateIrSensors() {
	if (!buttonC || !irL || !irR) {
		return;
	}

	// display->print("Press ", "loll", "Calibrate");

	buttonC->update();
	if (buttonC->pressed(2)) {
		while (buttonC->pressed(2)) {
			buttonC->update();
		}
		
		int t = millis();
		int count = 0;
		float v1 = 0;
		float v2 = 0;
		while (millis() - t < 15000) {
			app->getIrSensorReader().readAll(30000, false, 0);
			app->getIrSensorReader().setAll();

			v1 += irL->getCalculatedValue();
			v2 += irR->getCalculatedValue();
			count++;
			// display->print(v1 / count, v2 / count, millis() - t);
		}
		float irThreshold = ((v1 / count) + (v2 / count)) / 2;
		
		irThreshold = irThreshold + 2000;
		// app->getStates().setBallInHolderThreshould(irThreshold);
		// display->print("New Threshold:", String(irThreshold), "_____");

		delay(5000);
	}

	
}

void Calibration::calibrateIrRing() {
	if (!buttonC || !ring) {
		return;
	}

	// display->print("put aw", "centimeters", "away");
	buttonC->update();
	if (buttonC->pressed(2)) {
		while (buttonC->pressed(2)) {
			buttonC->update();
		}
		
		int t = millis();
		int count = 0;
		float v1 = 0;
		app->getDrivingControl().drive(0,0,0.3);
		while (millis() - t < 15000) {
			ring->update();

			float ringStrenght = ring->getStrength() * 8;
 
			float distanceRaw = ((1/sqrt(ringStrenght)) * 2000);
			v1 += (distanceRaw -  65)*2;

			count++;
			// display->print(v1 / count, 0, millis() - t);
		}
		app->getDrivingControl().turnOff();
		float irThreshold = v1 / count;
		
		irThreshold = irThreshold;
		// app->getStates().setBallInHolderThreshould(irThreshold);
		// display->print("New Thre:", String(irThreshold), "_____");

		delay(5000);
	}

	
}

