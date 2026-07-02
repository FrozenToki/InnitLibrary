#pragma once
#include <Arduino.h>
#include <vector>
#include "Sensorik/SensorBase/SensorBase.h"  

#define SLOW_BAUDRATE 9600
#define NORMAL_BAUDRATE 115200
#define FAST_BAUDRATE 500000
#define VERY_FAST_BAUDRATE 2000000

// forward declaration
class ApplicationInnit; 

class SerialComm {
private:
	ApplicationInnit* app;

	char sendBuffer[512];    
	String sendString;  																							

	int sendingProgress = 0;

	Stream& serial;

	unsigned long lastSendTimeRepeating = 0;
	unsigned long repeatingSendInterval; 

	unsigned long lastSendTimeOneTime = 0;
	unsigned long oneTimeSendInterval; 

	bool serialCommSending = false;

public:
	SerialComm(ApplicationInnit* a, Stream& ser = Serial, unsigned long RepeatingSendInterval = 100, unsigned long OneTimeSendInterval = 500);
	void sendRepeatingData(); 
	void sendOneTimeData(); 
	

	void sendOtherValues();
	void sendOtherValuesNames();


	void sendValueAsChar(String text, char* charrr,size_t bufferSize,bool newLine = true);

	void enableSerialComm();
	void disableSerialComm();
	
	void sendingLoop();

	void startSerialConnection(bool fastBaudRate, bool waitForConnection);
};