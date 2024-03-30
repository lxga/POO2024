#include <iostream>


class Number
{
	char* nr;
	int base;
public:
	Number(int nr);
	Number(int len, int base);
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& a);//copy constructor
	Number(Number&& a);//move constructor
	Number& operator=(Number&& a);//move assigment operator
	Number& operator=(Number& a);//copy assigment operator
	Number& operator=(const char* a);
	~Number();

	friend Number operator+(const Number& a, const Number& b);
	friend Number& operator+=(Number& a, const Number& b);
	friend Number operator-(const Number& a, const Number& b);
	friend Number operator*(const Number& a, int b);
	
	
	Number operator/(int b);
	int operator%(int b);


	bool operator<(const Number& b);
	bool operator>(const Number& b);
	bool operator>=(const Number& b);
	bool operator<=(const Number& b);
	bool operator==(const Number& b);
	char& operator[](int index);
	void operator--();
	void operator--(int);

	void SwitchBase(int newBase);
	void Print() const;
	int GetDigitsCount() const; // returns the number of digits for the current number
	int GetBase() const; // returns the current base

};
