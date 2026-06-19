#pragma once
#include <Arduino.h>
#include "InnitConfig/Config.h"

// forward declaration
class ApplicationInnit; 

class ErrorMessages {
private:
	ApplicationInnit* app;

	String errorMessages[InnitConfig::MAX_ERROR_MESSAGES];
public:
	ErrorMessages(ApplicationInnit* a);

	void newError(String e, String file);
	void addNewErrorToList(String e);

	String getError(int index);
};
