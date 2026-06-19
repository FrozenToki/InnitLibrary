#pragma once
#include <Arduino.h>
#include "Math/Vector/Vector.h"
#include <vector>
#include <tuple>

class ApplicationInnit; 

class Geometry {
private:
	ApplicationInnit* app;
public: 
	Geometry(ApplicationInnit* a);
	float normalizeAngle(float angle);

	std::tuple<float, float> vectorToAngle(Vector v);

	Vector angleToVector(float angle, float strength);
	float radToAngle(float rad);
	float angleToRad(float angle);
	float getMean(std::vector<float> ar);
	Vector addVectors(const std::vector<Vector>& vectors);
};