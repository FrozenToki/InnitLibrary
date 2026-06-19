#include "BallPositionReader.h"
#include "app/ApplicationInnit.h"

BallPositionReader::BallPositionReader(ApplicationInnit* a) : app(a) {}

void BallPositionReader::initializeBallPositionReader(size_t irSensorCount) {
	irSensCount = irSensorCount;
	irSensList.resize(irSensorCount);
	
	for (size_t i = 0; i < irSensCount; i++){
		irSensList[i] = app->getSensorManager().getIrSensorByIndex(i);
	}
	valueList.resize(irSensCount);
	highSensValAvrg.resize(5);
	highSensAngleAvrg.resize(5);

	for (size_t i = 0; i < 5; i++) {
		highSensAngleAvrg[i] = new MovingAverage(InnitConfig::COUNT_MOVING_AVERAGE);
		highSensValAvrg[i] = new MovingAverage(InnitConfig::COUNT_MOVING_AVERAGE);
	}	
}
/**
 * Werte aus SensorListe in die Werte Liste eintragen
 */
void BallPositionReader::setValues() {
	for (size_t i = 0; i < irSensCount; i++) {
		valueList.at(i)  = irSensList[i]->getCalculatedValue();
	}
}

/**
 * Finde den Sensor mit dem höchsten Wert
 * und jeweils 2 links und rechts davon
 */
void BallPositionReader::setHighestSensor() {

	hightestSensors.clear();
	
	IrSensor* hightestSensor = irSensList[0];
	int highestSensorIndex=0;
	for (size_t i = 1; i < irSensCount; i++) {
		if (hightestSensor->getCalculatedValue() <= irSensList[i]->getCalculatedValue()) {
			hightestSensor = irSensList[i];
	    highestSensorIndex = i;
		}
	}

	hightestSensors.push_back(hightestSensor);
	
	for (int i = 0; i < 2; i++) {
		int index = highestSensorIndex + (1 + i);
		if (index > 15 ) {
			index -= 16;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}
	
	for (int i = 0; i < 2; i++) {
		int index = highestSensorIndex - (1 + i);
		if (index < 0 ) {
			index += 16;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}


	//for (size_t i = 0; i < 5; i++) {
	//	highSensValAvrg[i]->newValue(hightestSensors[i]->getCalculatedValue());
	//	hightestSensors[i]->setCalculatedValue(highSensValAvrg[i]->getAverage());
	
	////	highSensAngleAvrg[i]->newValue(hightestSensors[i]->getAngle());
	////	hightestSensors[i]->setAvrgAngle(highSensAngleAvrg[i]->getAverage());
	//}
	
	
}

std::vector<IrSensor*> BallPositionReader::getHighestSensors() {
	return hightestSensors;
}

void BallPositionReader::setHighestSensVec() {
	for (size_t i = 0; i < hightestSensors.size(); i++) {
		hightestSensors[i]->setVector(app->getGeometry().angleToVector(hightestSensors[i]->getAngle(), 
																	hightestSensors[i]->getCalculatedValue()));
	}
}

void BallPositionReader::addHighestSensVec() {
	std::vector<Vector> vectors;
	vectors.reserve(hightestSensors.size());
	for (auto sensor : hightestSensors) {
		vectors.push_back(sensor->getVector());
	}
	ballVector = app->getGeometry().addVectors(vectors);
}

Vector BallPositionReader::getBallVector(){
	return ballVector;
}

std::vector<float> BallPositionReader::getValues() {
	return valueList;
}