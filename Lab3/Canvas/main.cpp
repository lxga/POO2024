#include "Canvas.h"

using namespace std;

int main() {
	Canvas c(20, 20);
	std::cout << "Cerc:\n";
	c.DrawCircle(10, 10, 4, '#');
	c.Print();
	c.Clear();

	std::cout << "Cerc plin:\n";
	c.FillCircle(10, 10, 5, '#');
	c.Print();
	c.Clear();

	std::cout << "Dreptunghi:\n";
	c.DrawRect(10, 10, 15,15, '#');
	c.Print();
	c.Clear();

	std::cout << "Dreptunghi Plin:\n";
	c.FillRect(2, 2, 17,17, '#');
	c.Print();
	c.Clear();

	std::cout << "Punct:\n";
	c.SetPoint(10, 10, '#');
	c.Print();
	c.Clear();

	std::cout << "Linie:\n";
	c.DrawLine(2, 3, 13, 12, '#');
	
	c.Print();
	return 0;
}