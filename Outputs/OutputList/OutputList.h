#pragma once
#include <Arduino.h>
#include "Outputs/OutputBase/Outputs.h"
#include "InnitConfig/Config.h"

// forward declaration
class OutputBase;
class ApplicationInnit;

// Used to save all outputs (like motors, displays, leds etc.) and access them easily.
class OutputList {
private:
	ApplicationInnit* app;
	OutputBase* outputList[InnitConfig::MAX_OUTPUTS];
	int outputCount;
public:
	OutputList(ApplicationInnit* a);
	void addOutput(OutputBase* s);
	OutputBase* getOutputByName(const String& n);
	OutputBase* get(int index);
	int getOutputCount();
};