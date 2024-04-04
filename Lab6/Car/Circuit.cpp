#include "Circuit.h"

Circuit::~Circuit() {
	for (int i = 0; i < nrCars; ++i) {
		delete cars[i];
	}
	delete[] cars;
}
void Circuit::setLength(int length) {
	this->length = length;
}

void Circuit::setWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::addCar(Car* car) {
	if (nrCars == capacity) {
		Car** newCars = new Car* [capacity * 2];
		for (int i = 0; i < nrCars; i++)
			newCars[i] = cars[i];
		delete[] cars;
		cars = newCars;
		capacity *= 2;
	}
	cars[nrCars] = car;
	nrCars++;
}


void swap(Car** cars, int i) {
	Car* temp = cars[i];
	cars[i] = cars[i + 1];
	cars[i + 1] = temp;
}
void Circuit::Race() {
	for (int i = 0; i < nrCars; i++) {
		cars[i]->timeToFinish(length, weather);
	}
	int last = nrCars;
	while (last!=-1) {
		last = -1;
		for (int i = 0; i < nrCars-1; i++) {
			if (cars[i]->getTime() > cars[i + 1]->getTime()) {
				swap(cars, i);
				last = i;
			}
		}
	}
}
void Circuit::ShowFinalRanks() {
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Final Ranks:\n";
	for (int i = 0; i < nrCars; i++) {
		if (cars[i]->getTime() > 2e9) break;
		std::cout << "Time: " << cars[i]->getTime() << " Name: " << cars[i]->getName() << '\n';
	}
	std::cout << '\n';
}
void Circuit::ShowWhoDidNotFinish() {
	std::cout << "Did not finish:\n";
	for (int i = nrCars-1; i >= 0; i--) {
		if (cars[i]->getTime() < 2e9) break;
		std::cout << cars[i]->getName() << '\n';
	}
	std::cout << '\n';
}