#include "EZ.h"

EZ::EZ(int p, String n, ApplicationInnit* a) : DistanceSensor(n, a), pin(p) {
	pinMode(pin, INPUT);
}

void EZ::update() {
	value = analogRead(pin) * 1.27;
}

float EZ::rawData() {
	return value;
}
