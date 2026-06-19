#pragma once
#include <Arduino.h>
#include "Sensorik/SensorBase/ButtonCross/ButtonCross.h"
#include "Outputs/OutputBase/Ssd1306/Ssd1306.h"
#include "Sensorik/SensorBase/Button/Button.h"
#include <vector>

class ApplicationInnit;

class MenuManager {
private: 
	ApplicationInnit* app;
	
	ButtonCross* buttonCross;

	Ssd1306* display;

	// Button* greenButton;

	std::vector<void(*)()> modes;
	std::vector<String> modeNames;

	int lastMode = 0;
	unsigned mode = 0;

	int inMode = false;
public: 
	MenuManager(ApplicationInnit* a);
	void addControll(Ssd1306* dis, ButtonCross* buttC);
	void addMenuItem(String n, void (*mode)());
	void loop();
};