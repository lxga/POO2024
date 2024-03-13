#include "Canvas.h"

using namespace std;

int main() {
	Canvas c(20, 20);
	c.DrawCircle(10, 10, 4, '#');
	c.Print();
	c.Clear();

	c.FillCircle(10, 10, 4, '#');
	c.Print();
	c.Clear();

	c.DrawRect(10, 10, 15,15, '#');
	c.Print();
	c.Clear();

	c.FillRect(10, 10, 20,20, '#');
	c.Print();
	c.Clear();

	c.SetPoint(10, 10, '#');
	c.Print();
	c.Clear();

	c.DrawLine(0, 0, 13, 12, '#');
	
	c.Print();
	return 0;
}