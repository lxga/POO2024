#pragma once
#include "Weather.h"

class Car {
protected:
	float fuelCapacity, fuelCons;
	float avgSpeed[3];
public:	
	virtual float timeToFinish(int dist, Weather type) = 0;
};

