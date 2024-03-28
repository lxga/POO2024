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

Number operator+(const Number& a, const Number& b) {
	Number res = a;
	
	return res;
}



void Number::Print(){
	std::cout<<this->nr;
}

int Number::GetDigitsCount(){
	int len=0;
	while(this->nr[len])
		len++;
	return len+1;
}

int Number::GetBase(){
	return this->base;
}

void Number::SwitchBase(int newBase){
	int len=GetDigitsCount();
	char *temp=new char[4*len];

	//Reverse
	for(int i=0;i<len/2;i++){
		std::swap(this->nr[i],this->nr[len-i-1]);
	}

	int pos=0;
	for(int i=0;i<len;i++){
		
	}
}
