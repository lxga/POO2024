#include <iostream>
#include "Math.h"
using namespace std;

int main() {

	cout << Math::Add(2, 3) << endl; // adaug doi intregi
	cout << Math::Add(2, 3, 4) << endl; // adaug trei intregi
	cout << Math::Add(2.5, 3.5) << endl; // adaug doua double
	cout << Math::Add(2.5, 3.3, 4.2) << endl; // adaug trei double

	cout << Math::Mul(2, 3) << endl; // inmultesc doi intregi
	cout << Math::Mul(2, 3, 4) << endl; // inmultesc trei intregi
	cout << Math::Mul(2.0, 3.3) << endl; // inmultesc doua double
	cout << Math::Mul(2.0, 3.3, 1.5) << endl; // inmultesc trei double

	cout << Math::Add(5, 1, 2, 3, 4, 5) << endl;//adaug un numar oarecare de intregi
	cout << Math::Add("987", "432");//adaug doua numere mari intregi
	return 0;
}