#include "Geometry.h"

Geometry::Geometry(ApplicationInnit *a) : app(a) {}

float Geometry::normalizeAngle(float angle) {
	while (angle < 0) angle += 360;
	while (angle >= 360) angle -= 360;


	if (angle > 180)
		angle -= 360;

	return angle;
}

std::tuple<float, float> Geometry::vectorToAngle(Vector v){
	float strength;
	strength = std::sqrt(v.getX() * v.getX() + v.getY() * v.getY());
	 
	float angle;
	angle = std::atan2(v.getY(), v.getX());
	//if(angle < 0) {
	//	angle += 360.0f;
	//}
	return std::make_tuple(angle, strength);
} 

/**
 * Vektor(x/y) aus Angle und Strength
 */
Vector Geometry::angleToVector(float angle, float strength) {
	float x = cos(angleToRad(angle)) * strength;
	float y = sin(angleToRad(angle)) * strength;
	return Vector(x,y);
}

float Geometry::radToAngle(float rad) {
	float angle = rad * 180 / PI;
	return angle;
}

float Geometry::angleToRad(float angle) {
	float rad = (angle / 360) * 2 * PI;
	return rad;
}

float Geometry::getMean(std::vector<float> ar) {
	float allArrayValues = 0.0f;
	for (size_t i = 0; i < ar.size(); i++) {
		allArrayValues += ar[i];
	}
	float mean = allArrayValues / ar.size();
	return mean;
}

Vector Geometry::addVectors(const std::vector<Vector>& vectors) {
	if (vectors.empty()) {
		return Vector(0.0f, 0.0f);
	}

	float x = 0.0f;
	float y = 0.0f;
	for (size_t i = 0; i < vectors.size(); i++) {
		x += vectors[i].getX();
		y += vectors[i].getY();
	}

	x /= vectors.size();
	y /= vectors.size();

	return Vector(x, y);
}

