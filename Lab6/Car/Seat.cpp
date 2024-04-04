#include "Seat.h"

Seat::Seat() {
	fuelCapacity = 40;
	fuelCons = 10;
	avgSpeed[Sunny] = 80;
	avgSpeed[Rain] = 43;
	avgSpeed[Snow] = 30;
	name = "Seat";
}
void Seat::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		time = 2e18;
	else
		time = dist / avgSpeed[type];
}
const char* Seat::getName() {
	return this->name;
}