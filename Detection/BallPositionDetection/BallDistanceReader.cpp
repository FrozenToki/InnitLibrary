#include "BallDistanceReader.h"
#include "app/ApplicationInnit.h"

BallDistanceReader::BallDistanceReader(ApplicationInnit* a) : app(a) {}

void BallDistanceReader::initializeBallDistReader(size_t irSensorCount) {
	irSensCount = irSensorCount;
	irSensList.resize(irSensorCount);
	
	for (size_t i = 0; i < irSensCount; i++){
		irSensList[i] = app->getSensorManager().getIrSensorByIndex(i);
	}

	
}

float BallDistanceReader::getAverageDistance() {
	return averageDistance;
}

float BallDistanceReader::getSmoothedAverageDistance() {
	return smoothedAverageDistance;
}

/**
 * Finde den Sensor mit dem höchsten Wert
 * und jeweils 2 links und rechts davon
 */
void BallDistanceReader::setHighestSensor(int numberOfHighestSensor) {

	hightestSensors.clear();
	
	IrSensor* hightestSensor = irSensList[0];
	int highestSensorIndex=0;
	for (size_t i = 1; i < irSensCount; i++) {
		if (hightestSensor->getSmoothedCalculatedValue() <= irSensList[i]->getSmoothedCalculatedValue()) {
			hightestSensor = irSensList[i];
	    highestSensorIndex = i;
		}
	}

	float highestValue = hightestSensor->getSmoothedCalculatedValue();

	hightestSensors.push_back(hightestSensor);

	
	
	for (int i = 0; i < (numberOfHighestSensor) / 2; i++) {
		int index = highestSensorIndex + (1 + i);
		if (index >= (int)irSensCount) {
			index -= irSensCount;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}
	
	for (int i = 0; i < (numberOfHighestSensor-2) / 2; i++) {
		int index = highestSensorIndex - (1 + i);
		if (index < 0) {
			index += irSensCount;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}

	float addedValues = 0;

	for (size_t i = 0; i < hightestSensors.size(); i++) {
		addedValues += hightestSensors[i]->getSmoothedCalculatedValue();
	}
	
	averageDistance = addedValues / hightestSensors.size();

	float delta = abs(averageDistance - smoothedAverageDistance);

	if (delta < 20) {
		smoothedAverageDistance = smoothedAverageDistance; 
	} else {
		smoothedAverageDistance = 0.8f * smoothedAverageDistance + 0.2f * averageDistance;  
	}
}

std::vector<IrSensor*> BallDistanceReader::getHighestSensors() {
	return hightestSensors;
}

