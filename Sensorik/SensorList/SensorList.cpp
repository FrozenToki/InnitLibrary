#include "SensorList.h"
#include "app/ApplicationInnit.h"

SensorList::SensorList(ApplicationInnit* a) : app(a), sensorCount(0) {
    for (int i = 0; i < InnitConfig::MAX_SENSORS; i++) {
        sensorList[i] = nullptr;
    }
}

void SensorList::addSensor(SensorBase* s) {
	for (int i = 0; i < sensorCount; i++) {
		if (sensorList[i]->getName() == s->getName()) {
			Serial.println("Sensorname existiert schon!");
			return;
		}
	}

	if (sensorCount < InnitConfig::MAX_SENSORS) {
		sensorList[sensorCount++] = s;
	}
}

SensorBase* SensorList::getSensorByName(const String& n) {
	for (int i = 0; i < sensorCount; i++) {
		if (sensorList[i]->getName() == n) {
			return sensorList[i];
		}
	}
	return nullptr;
}

//SensorBase *SensorList::getSensorByAngle(float angle){
//	for (int i = 0; i < sensorCount; i++) {
//		if (sensorList[i]->getAngle() == angle) {
//			return sensorList[i];
//		}
//	}
//	return nullptr;
//}

SensorBase* SensorList::get(int index) {
	if (index < 0 || index >= sensorCount) {
		return nullptr;
	}
	return sensorList[index];
}

int SensorList::getSensorCount() {
	return sensorCount;
}

void SensorList::updateAllSensors() {
	for (int i = 0; i < sensorCount; i++) {
		sensorList[i]->update();
	}
}