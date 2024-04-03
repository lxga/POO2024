#include "BMW.h"

BMW::BMW() {
	fuelCapacity = 50;
	fuelCons = 20;
	avgSpeed[Sunny] = 100;
	avgSpeed[Rain] = 50;
	avgSpeed[Snow] = 30;
}
float BMW::timeToFinish(float dist, Weather type) {
	if (fuelCapacity / fuelCons * 100 < dist)
		return -1;
	return dist / avgSpeed[type];
}