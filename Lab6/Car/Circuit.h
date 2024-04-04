#pragma once
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"
#include <iostream>
#include <iomanip>

class Circuit {
	int length;
	Weather weather;
	Car** cars;
	int nrCars, capacity;
public:
	Circuit() : cars(new Car* [1]), nrCars(0), capacity(1), length(0), weather(Sunny) {}
	~Circuit();
	void setLength(int);
	void setWeather(Weather);
	void addCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};