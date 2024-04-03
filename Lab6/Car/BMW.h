#include "Car.h"
class BMW : public Car {
public:
	BMW();
	~BMW();
	float timeToFinish(float dist,Weather type);
};