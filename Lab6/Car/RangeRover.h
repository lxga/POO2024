#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
	RangeRover();
	void timeToFinish(float dist, Weather type) override;
	const char* getName() override;
};