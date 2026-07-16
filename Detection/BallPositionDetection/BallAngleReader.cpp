#include "BallAngleReader.h"
#include "app/ApplicationInnit.h"

BallAngleReader::BallAngleReader(ApplicationInnit* a) : app(a) {}

void BallAngleReader::initializeBallAngleReader(size_t irSensorCount) {
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
void BallAngleReader::setValues() {
	for (size_t i = 0; i < irSensCount; i++) {
		valueList.at(i)  = irSensList[i]->getCalculatedValue();
	}
}

/**
 * Finde den Sensor mit dem höchsten Wert
 * und jeweils 2 links und rechts davon
 */
void BallAngleReader::setHighestSensor(int numberOfHighestSensor) {

	hightestSensors.clear();
	
	IrSensor* hightestSensor = irSensList[0];
	int highestSensorIndex=0;
	for (size_t i = 1; i < irSensCount; i++) {
		if (hightestSensor->getCalculatedValue() <= irSensList[i]->getCalculatedValue()) {
			hightestSensor = irSensList[i];
	    highestSensorIndex = i;
		}
	}

	float highestValue = hightestSensor->getCalculatedValue();

	hightestSensors.push_back(hightestSensor);

	
	
	for (int i = 0; i < (numberOfHighestSensor -1) / 2; i++) {
		int index = highestSensorIndex + (1 + i);
		if (index >= (int)irSensCount) {
			index -= irSensCount;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}
	
	for (int i = 0; i < (numberOfHighestSensor -1) / 2; i++) {
		int index = highestSensorIndex - (1 + i);
		if (index < 0) {
			index += irSensCount;
		}
		hightestSensors.push_back(app->getSensorManager().getIrSensorByIndex(index));	
	}

	float thresholdValue = highestValue * 0.25;

	for (size_t i = 0; i < hightestSensors.size(); i++) {
		if (hightestSensors[i]->getCalculatedValue() < thresholdValue) {
			hightestSensors[i]->setWeightedValue(0.0f);
		}
		else {
			hightestSensors[i]->setWeightedValue(hightestSensors[i]->getCalculatedValue() * hightestSensors[i]->getCalculatedValue());
		}
	}


	//for (size_t i = 0; i < 5; i++) {
	//	highSensValAvrg[i]->newValue(hightestSensors[i]->getCalculatedValue());
	//	hightestSensors[i]->setCalculatedValue(highSensValAvrg[i]->getAverage());
	
	////	highSensAngleAvrg[i]->newValue(hightestSensors[i]->getAngle());
	////	hightestSensors[i]->setAvrgAngle(highSensAngleAvrg[i]->getAverage());
	//}
	
	
}

std::vector<IrSensor*> BallAngleReader::getHighestSensors() {
	return hightestSensors;
}

void BallAngleReader::setHighestSensVec() {
	for (size_t i = 0; i < hightestSensors.size(); i++) {
		hightestSensors[i]->setVector(app->getGeometry().angleToVector(hightestSensors[i]->getAngle(), 
																	hightestSensors[i]->getWeightedValue()));
	}
}

void BallAngleReader::addHighestSensVec() {
	std::vector<Vector> vectors;
	vectors.reserve(hightestSensors.size());
	for (auto sensor : hightestSensors) {
		vectors.push_back(sensor->getVector());
	} 	

	ballVector = app->getGeometry().addVectors(vectors);
	
	emaBallVector.setX(0.1 * ballVector.getX() + (1-0.1) * emaBallVector.getX());
	emaBallVector.setY(0.1 * ballVector.getY() + (1-0.1) * emaBallVector.getY());
}

Vector BallAngleReader::getBallVector(){
	return ballVector;
}

Vector BallAngleReader::getEmaBallVector() {
	return emaBallVector;
}

std::vector<float> BallAngleReader::getValues() {
	return valueList;
}