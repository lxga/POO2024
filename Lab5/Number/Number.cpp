#include "Number.h"

Number::Number(const char* value, int base) {
	if (base < 2 || base>16) return;
	int len = 0;
	while (value[len] != '\0')
		len++;
	this->nr = new char[len + 1];
	this->base = base;
	while (len) {
		this->nr[len] = value[len];
		len--;
	}
}

Number::~Number() {
	delete[] this->nr;
	this->nr = nullptr;
}

Number::Number(const Number& a) {
	int len = 0;
	while (a.nr[len] != '\0')
		len++;
	this->nr = new char[len + 1];
	while (len) {
		this->nr[len] = a.nr[len];
		len--;
	}
	this->base = a.base;
}
Number::Number(Number&& a) {
	char* temp = a.nr;
	a.nr = nullptr;
	this->nr = temp;
	this->base = a.base;
}

Number& Number::operator=(Number&& a) {
	int len = 0;
	while (a.nr[len] != '\0')
		len++;
	this->nr = new char[len + 1];
	while (len) {
		this->nr[len] = a.nr[len];
		len--;
	}
	this->base = a.base;
	return *this;
}

Number& operator+(const Number& a, const Number& b) {
	Number res = a;
	if (res.base > b.base) {
		b.SwitchBase(res.base);
	}
	else
		res.SwitchBase(b.base);

}