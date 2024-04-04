#include "BMW.h"

BMW::BMW() {
	fuelCapacity = 50;
	fuelCons = 20;
	avgSpeed[Sunny] = 100;
	avgSpeed[Rain] = 50;
	avgSpeed[Snow] = 30;
	name = "BMW";
}
void BMW::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		time = 2e18;
	else
		time = dist / avgSpeed[type];
}
const char* BMW::getName() {
	return this->name;
}