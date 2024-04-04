#include "Fiat.h"

Fiat::Fiat() {
	fuelCapacity = 34;
	fuelCons = 1000;
	avgSpeed[Sunny] = 50;
	avgSpeed[Rain] = 30;
	avgSpeed[Snow] = 20;
	name = "Fiat";
}
void Fiat::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		time = 2e18;
	else
		time = dist / avgSpeed[type];
}
const char* Fiat::getName() {
	return this->name;
}