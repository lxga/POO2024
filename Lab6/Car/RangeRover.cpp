#include "RangeRover.h"

RangeRover::RangeRover() {
	fuelCapacity = 80;
	fuelCons = 30;
	avgSpeed[Sunny] = 90;
	avgSpeed[Rain] = 40;
	avgSpeed[Snow] = 30;
	name = "RangeRover";
}
void RangeRover::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		time = 2e18;
	else
		time = dist / avgSpeed[type];
}
const char* RangeRover::getName() {
	return this->name;
}