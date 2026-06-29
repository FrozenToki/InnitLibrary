#pragma once 
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"

const byte numChars = 32;

class SerialReciever : public SensorBase {
private:
	
	char receivedChars[numChars];
	char tempChars[numChars];        
	
	float strengthFromRing = 0.0;
	float angleFromRing = 0.0;

	bool newData = false;
	
	uint8_t valueCount;
	float* values; 

	HardwareSerialIMXRT* serialType;

public:
	SerialReciever(HardwareSerialIMXRT* s ,String n, uint8_t valueCount, ApplicationInnit* a);
	void update() override;
	void recvWithStartEndMarkers();
	void parseData();
	void showParsedData();

	float rawData() override;

	float getValue(uint8_t i);
};