#pragma once
#include <Arduino.h>

class ApplicationInnit;

// Used to create all
class SensorBase {
protected:
	int pin;
	float value;
	String name;
	String type;
	ApplicationInnit* app;
	
private:
	static int sensorCount;
	
public:
	SensorBase(int p,String n, ApplicationInnit* a);

  static String BUTTON;
	static String BNO055;


	int getPin() const;
	String getName() const;
	String getType() const;

	int& getPinRef();
	String& getNameRef();


	virtual void update() = 0;
	virtual float rawData() = 0;
	
	// Updates the sensor and returns its raw data.
	float readSensor();

	SensorBase();
};





