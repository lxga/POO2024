#pragma once
#include "Car.h"
class Volvo : public Car {
public:
	Volvo();
	void timeToFinish(float dist, Weather type) override;
	const char* getName() override;
};