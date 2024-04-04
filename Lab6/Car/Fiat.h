#pragma once
#include "Car.h"

class Fiat : public Car{
public:
	Fiat();
	void timeToFinish(float dist, Weather type) override;
	const char* getName() override;
};