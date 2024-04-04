#pragma once
#include "Car.h"

class Seat : public Car{
public:
	Seat();
	void timeToFinish(float dist, Weather type) override;
	const char* getName() override;
};