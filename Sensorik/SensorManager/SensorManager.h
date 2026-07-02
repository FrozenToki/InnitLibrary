#pragma once
#include "Arduino.h"
#include "Sensorik/SensorBase/Button/Button.h"
#include "Sensorik/SensorList/SensorList.h"
#include "Sensorik/SensorBase/Bno055/Bno055.h"
#include "Sensorik/SensorBase/DistanceSensor/DistanceSensor.h"
#include "Sensorik/SensorBase/DistanceSensor/EZ/EZ.h"
#include "Sensorik/SensorBase/DistanceSensor/SR04/Sr04.h"
#include "Sensorik/SensorBase/IrSensors/IrSensors.h"
#include "Sensorik/SensorBase/SerialReciever/SerialReciever.h"
#include "Sensorik/SensorBase/ButtonCross/ButtonCross.h"

#if defined(ARDUINO_ARCH_IMXRT)
    typedef HardwareSerialIMXRT BoardSerialType;
#else
    typedef HardwareSerial BoardSerialType;
#endif

// forward declaration
class ApplicationInnit; 

// Used to create all the sensors.
class SensorManager {
private:
	ApplicationInnit* app;

public:
	SensorManager(ApplicationInnit* a);

	// Creates an instance of the button class and add's that to the sensorlist.
	Button* createButton(int p, String n);
	// Searches all sensors for the given name and returns it, 
	// as an instance of the button class.
	Button* getButtonByName(String n);

	Bno055* createBno055(String n);
	Bno055* getBno055ByName(String n);

	Sr04* createSr04(int trig, int echo, String n);
	Sr04* getSr04ByName(String n);

	IrSensor* createIrSensor(int p, String n, float a);
	IrSensor* getIrSensorByName(String n);
	IrSensor* getIrSensorByIndex(int i);


	SerialReciever* createSerialReciever(BoardSerialType* serialConnection, String n, uint8_t valueCount, unsigned long Baudrate);
	SerialReciever* getSerialRecieverByName(String n);

	ButtonCross* createButtonCross(String n, int pin, float v1, float v2, float v3, float v4, float v5);
	ButtonCross* getButtonCrossByName(String n);

	EZ* createEZ(int p, String n);
	EZ* getEZByName(String n);
};

