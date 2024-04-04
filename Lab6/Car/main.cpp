#include <iostream>
#include "Circuit.h"

int main()
{
	Circuit c;
	c.setLength(100);
	c.setWeather(Weather::Rain);
	c.addCar(new Volvo());
	c.addCar(new BMW());
	c.addCar(new Seat());
	c.addCar(new Fiat());
	c.addCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}