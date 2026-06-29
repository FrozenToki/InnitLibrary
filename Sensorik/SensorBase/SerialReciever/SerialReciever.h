#pragma once 
#include <Arduino.h>
#include "Sensorik/SensorBase/SensorBase.h"

#if defined(ARDUINO_ARCH_IMXRT)
    typedef HardwareSerialIMXRT BoardSerialType;
#else
    typedef HardwareSerial BoardSerialType;
#endif

const byte numChars = 128;

class SerialReciever : public SensorBase {
private:
	
	char receivedChars[numChars];
	char tempChars[numChars];        
	
	float strengthFromRing = 0.0;
	float angleFromRing = 0.0;

	bool newData = false;
	bool newDataSinceLastRead = false;
	
	uint8_t valueCount;
	float* values; 

	BoardSerialType* serialType;

public:
	SerialReciever(BoardSerialType* s ,String n, uint8_t valueCount, ApplicationInnit* a);
	void update() override;
	void recvWithStartEndMarkers();
	void parseData();
	void showParsedData();

	bool isNewDataAvailable();

	float rawData() override;

	float getValue(uint8_t i);
};