#pragma once
#include "Weather.h"

class Car {
protected:
	float fuelCapacity, fuelCons;
	float avgSpeed[3];
	float time;
	const char* name;
public:	
	virtual void timeToFinish(float dist, Weather type) = 0;
	float getTime() {
		return this->time;
	}
	virtual const char* getName() = 0;
};

