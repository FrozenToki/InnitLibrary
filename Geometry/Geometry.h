#pragma once
#include <Arduino.h>

class ApplicationInnit; 

class Geometry {
private:
	ApplicationInnit* app;
public: 
	Geometry(ApplicationInnit* a);
	float normalizeAngle(float angle);
};