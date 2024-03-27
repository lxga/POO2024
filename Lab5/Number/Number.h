class Number
{
	char* nr;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& a);
	Number(Number&& a);
	Number& operator=(Number&& a);
	~Number();

	friend Number& operator+(const Number& a, const Number& b);
	friend Number& operator-(const Number& a, const Number& b);

	void operator<(const Number& b);
	void operator>(const Number& b);
	void operator>=(const Number& b);
	void operator<=(const Number& b);
	void operator==(const Number& b);


	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};