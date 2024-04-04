#include "Volvo.h"

Volvo::Volvo() {
	fuelCapacity = 60;
	fuelCons = 25;
	avgSpeed[Sunny] = 90;
	avgSpeed[Rain] = 30;
	avgSpeed[Snow] = 20;
	name = "Volvo";
}
void Volvo::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		time = 2e18;
	else
		time = dist / avgSpeed[type];
}
const char* Volvo::getName() {
	return this->name;
}