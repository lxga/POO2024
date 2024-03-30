#include "Number.h"

//constructor cu int ( baza 10)
Number::Number(int nr) {
	int aux = nr, len = 0;
	do {
		len++;
		aux /= 10;
	} while (aux);

	this->nr = new char[len + 1];
	this->base = 10;

	this->nr[len] = 0;
	while (nr) {
		this->nr[len - 1] = nr % 10 + '0';
		nr /= 10;
		len--;
	}
}
//constructor
Number::Number(const char* value, int base) {
	if (base < 2 || base>16) return;
	int len = 0;
	while (value[len] != '\0')
		len++;
	this->nr = new char[len + 1];
	this->base = base;
	while (len>-1) {
		this->nr[len] = value[len];
		len--;
	}
}

//copy constructor
Number::Number(const Number& a) {
	int len = a.GetDigitsCount();
	this->nr = new char[len + 1];
	this->base = a.base;
	while (len>-1) {
		this->nr[len] = a.nr[len];
		len--;
	}
	this->base = a.base;
}

//move constructor
Number::Number(Number&& a) {
	delete[] this->nr;
	char* temp = a.nr;
	a.nr = nullptr;
	this->nr = temp;
	this->base = a.base;
}

//move assigment
Number& Number::operator=(Number&& a) {
	delete[] this->nr;
	this->nr = a.nr;
	a.nr = nullptr;
	this->base = a.base;
	return *this;
}
//copy assigment
Number& Number::operator=(Number& a) {
	int len = a.GetDigitsCount();
	this->nr = new char[len + 1];
	while (len>-1) {
		this->nr[len] = a.nr[len];
		len--;
	}
	this->base = a.base;
	return *this;
}
// = string
Number& Number::operator=(const char* a) {
	delete[] this->nr;
	int len;
	for (len = 0; a[len]; len++) {}
	this->nr = new char[len + 1];
	while (len>-1) {
		this->nr[len] = a[len];
		len--;
	}
	return *this;
}

//Destructor
Number::~Number() {
	delete[] this->nr;
	this->nr = nullptr;
}


//OPERATORI ARITMETICI--------------------------------------------
void fixChar(char& c) {
	if (c <= 9)
		c += '0';
	else
		c = c - 10 + 'A';
}

char toInt(char c) {
	if (c >= 'A')
		return c + 10 - 'A';
	else
		return c - '0';
}

Number operator+(const Number& a, const Number& b) {
	Number na = a, nb = b;
	
	if (na.GetBase() < nb.GetBase()) {
		na.SwitchBase(nb.GetBase());
	}
	else if(nb.GetBase() < na.GetBase()) {
		nb.SwitchBase(na.GetBase());
	}
	
	int len1 = na.GetDigitsCount() - 1, len2 = nb.GetDigitsCount() - 1, base = na.GetBase(), pos = std::max(len1, len2) + 1, tr = 0;
	char* temp = new char[pos + 2];
	temp[pos+1] = 0;
	temp[0] = 0;
	while (len1 >= 0 && len2 >= 0) {
		int sumtemp= na.nr[len1] + nb.nr[len2] + tr;
		
		if (na.nr[len1] >= 'A')
			sumtemp -= 'A' - 10;
		else
			sumtemp -= '0';
		if (nb.nr[len2] >= 'A')
			sumtemp -= 'A' - 10;
		else
			sumtemp -= '0';

		tr = sumtemp / base;
		
		temp[pos] = sumtemp % base;
		fixChar(temp[pos]);


		pos--;
		len1--;
		len2--;
	}
	while (len1 >= 0) {
		temp[pos] = na.nr[len1] + tr;
		if (na.nr[len1] >= 'A')
			temp[pos] -= 'A' - 10;
		else
			temp[pos] -= '0';
		tr = temp[pos] / base;
		temp[pos] %= base;
		fixChar(temp[pos]);
		pos--;
		len1--;
	}
	while (len2 >= 0) {
		temp[pos] = nb.nr[len2] + tr;
		if (nb.nr[len2] >= 'A')
			temp[pos] -= 'A' - 10;
		else
			temp[pos] -= '0';
		tr = temp[pos] / base;
		temp[pos] %= base;
		fixChar(temp[pos]);
		pos--;
		len2--;
		tr = 0;
	}
	if (tr != 0) {
		temp[0] = tr;
		fixChar(temp[0]);
	}
	else {
		for (int i = 0; temp[i-1]; i++) {
			temp[i] = temp[i + 1];
		}
	}

	na = temp;
	delete[] temp;
	return na;
}
Number& operator+=(Number& a, const Number& b) {
	a = a + b;
	return a;
}
Number operator-(const Number& a, const Number& b) {
	Number na = a, nb = b;

	if (na.GetBase() < nb.GetBase()) {
		na.SwitchBase(nb.GetBase());
	}
	else if (nb.GetBase() < na.GetBase()) {
		nb.SwitchBase(na.GetBase());
	}

	int len1 = na.GetDigitsCount() - 1, len2 = nb.GetDigitsCount() - 1, base = na.GetBase(), pos = std::max(len1, len2), tr = 0;
	char* temp = new char[pos + 2];
	temp[pos + 1] = 0;
	temp[0] = 0;
	while (len1 >= 0 && len2 >= 0) {
		temp[pos] = toInt(na.nr[len1]) - toInt(nb.nr[len2]) + tr;
		if (temp[pos] < 0)
			temp[pos] += base, tr = -1;
		else tr = 0;
		fixChar(temp[pos]);
		pos--;
		len1--;
		len2--;
	}
	while (len1 >= 0) {
		temp[pos] = toInt(na.nr[len1]) + tr;
		if (temp[pos] < 0)
			temp[pos] += base, tr = -1;
		else
			tr = 0;
		fixChar(temp[pos]);
		pos--;
		len1--;
	}
	while (len2 >= 0) {
		temp[pos] = toInt(nb.nr[len2]) + tr;
		if (temp[pos] < 0)
			temp[pos] += base, tr = -1;
		else
			tr = 0;
		fixChar(temp[pos]);
		pos--;
		len2--;
		tr = 0;
	}

	pos = 0;
	while (temp[pos] == '0') {
		for (int i = 0; temp[i - 1]; i++)
			temp[i] = temp[i + 1];
	}

	if (temp[0] == 0)
		temp[0] = '0';

	na = temp;
	delete[] temp;
	return na;
}

Number Number::operator/(const Number& b) {
	Number na = *this, nb = b;
	

	if (na.base != nb.base)
		return Number(0, -1);

	Number cat("0", na.base);
	while (na >= nb) {
		na = na - nb;
		cat = cat + Number("1", na.base);
	}
	return cat;
}
Number Number::operator%(const Number& b) {
	Number na = *this, nb = b;
	/*if (na.GetBase() > nb.GetBase()) {
		nb.SwitchBase(na.GetBase());
	}
	else if (na.GetBase() < nb.GetBase()) {
		na.SwitchBase(nb.GetBase());
	}*/
	if (na.base != nb.base)
		return Number(0, -1);

	Number cat("0", na.base);
	while (na >= nb) {
		na = na - nb;
		cat = cat + Number("1", na.base);
	}
	return na;
}


Number operator*(const Number& a, int b) {
	Number na(a), ans("0", na.base);

	while (b) {
		if (b % 2)
			ans = ans + na;
		na = na + na;
		b /= 2;
	}

	return ans;
}


//OPERATORI RELATIONALI--------------------------------------------
bool Number::operator==(const Number& b) {
	Number nb = b;
	if (nb.base != this->base)
		nb.SwitchBase(this->GetBase());
	int i1 = this->GetDigitsCount(), i2 = nb.GetDigitsCount();
	if (i1 != i2)
		return 0;
	for (int i = 0; i < i1; i++) {
		if (this->nr[i] != nb.nr[i])
			return 0;
	}
	return 1;
}
bool Number::operator>(const Number& b) {
	Number nb = b;
	if (nb.base != this->base)
		nb.SwitchBase(this->GetBase());
	int i1 = this->GetDigitsCount(), i2 = nb.GetDigitsCount();
	if (i1 > i2)
		return 1;
	else if (i1 < i2)
		return 0;
	for (int i = 0; i < i1; i++) {
		if (this->nr[i] > nb.nr[i])
			return 1;
		else if (this->nr[i] < nb.nr[i])
			return 0;
	}
	return 0;
}
bool Number::operator<(const Number& b) {
	Number nb = b;
	if (nb.base != this->base)
		nb.SwitchBase(this->GetBase());
	int i1 = this->GetDigitsCount(), i2 = nb.GetDigitsCount();
	if (i1 < i2)
		return 1;
	else if (i1 > i2)
		return 0;
	for (int i = 0; i < i1; i++) {
		if (this->nr[i] < nb.nr[i])
			return 1;
		else if (this->nr[i] > nb.nr[i])
			return 0;
	}
	return 0;
}
bool Number::operator>=(const Number& b) {
	return *this == b || *this > b;
}
bool Number::operator<=(const Number& b) {
	return *this == b || *this < b;
}


//MISC--------------------------------------------
char& Number::operator[](int index) {
	return this->nr[index];
}
void Number::operator--() {
	for (int i = 1; this->nr[i-1]; i++) {
		this->nr[i - 1] = this->nr[i];
	}
}
void Number::operator--(int) {
	int len = GetDigitsCount();
	this->nr[len - 1] = 0;
}

void Number::Print() const{
	std::cout << this->nr << '\n';
}

int Number::GetDigitsCount() const{
	int len=0;
	while(this->nr[len])
		len++;
	return len;
}

int Number::GetBase() const{
	return this->base;
}


void Number::SwitchBase(int newBase){
	Number temp("0", 10), ans("0", newBase), pow("1", 10);
	
	int len = this->GetDigitsCount();
	for (int i = len - 1; i >= 0; i--) {
		int d = this->nr[i];
		if (d >= 'A')
			d = d - 'A' + 10;
		else
			d -= '0';
		temp = temp + pow * d;
		pow = pow * base;
	}

	Number zero("0", 10), nBase(newBase);
	int k = 0;
	while (temp>zero) {
		Number cat = temp / nBase;
		Number rest = temp % nBase;
		rest.base = newBase;
		if (rest.nr[1] > 0) {
			rest.nr[0] = ((rest.nr[0] - '0') * 10 + rest.nr[1] - '0');
			rest.nr[0] -= 10 - 'A';
			rest.nr[1] = 0;
		}

		
		for (int i = 0; i < k; i++) {
			rest = rest * newBase;
		}

		ans = ans + rest;
		temp = cat;
		k++;
	}

	*this = ans;
}
