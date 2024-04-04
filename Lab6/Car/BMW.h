#include "Car.h"
class BMW : public Car {
public:
	BMW();
	void timeToFinish(float dist, Weather type) override;
	const char* getName() override;
};