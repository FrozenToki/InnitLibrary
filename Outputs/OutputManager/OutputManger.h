#pragma once
#include "Arduino.h"
#include "Outputs/OutputBase/Led/Led.h"
#include "Outputs/OutputBase/Motor/Motor.h"
#include "Outputs/OutputList/OutputList.h"
#include "Outputs/OutputBase/Ssd1306/Ssd1306.h"


// forward declaration
class ApplicationInnit;

// Used to create all the outputs.
class OutputManager {
private:
	ApplicationInnit* app;
public:
	OutputManager(ApplicationInnit* a);

	// Creates an instance of the led class and add's that to the outputlist.
	Led* createLed(int p, String n);
	// Searches all sensors for the given name and returns it, 
	// as an instance of the led class. 
	Led* getLedByName(String n);

	Motor* createMotor(int pInA, int pInB, int pPwm, int pAmp, String n, bool turnDirection = true); 
	Motor* getMotorByName(String n);

	Ssd1306* createSsd1306(String n);
	Ssd1306* getSsd1306ByName(String n);
};
