#pragma once
#include <Arduino.h>

class ApplicationInnit;

// Used to create all
class SensorBase {
protected:
	float value;
	String name;
	ApplicationInnit* app;
	
private:
	static int sensorCount;
	
public:
	SensorBase(String n, ApplicationInnit* a);

	String getName() const;
	String& getNameRef();

	

	virtual void update() = 0;
	virtual float rawData() = 0;
	
	// Updates the sensor and returns its raw data.
	float readSensor();

	SensorBase();
};





