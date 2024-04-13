#include <iostream>

float operator"" _Kelvin(long double b) {
    return static_cast<float>(b) + 273.15;
}
float operator"" _Fahrenheit(long double b) {
    return (static_cast<float>(b) - 32) * 5 / 9;
}

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    std::cout << a << '\n' << b;
	return 0;
}
