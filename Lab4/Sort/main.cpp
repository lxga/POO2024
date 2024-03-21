#include <iostream>
#include "Sort.h"
using namespace std;

int main() {
	Sort* s = new Sort(10, 1, 100);
	s->QuickSort();
	s->Print();
	delete s;

	int* v = new int[3] {3, 2, 1};
	s = new Sort(v, 3);
	s->InsertSort(true);
	s->Print();
	delete s;

	s = new Sort(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	s->BubbleSort();
	s->Print();
	delete s;

	s = new Sort("2,4,5,6,8,10");
	s->InsertSort();
	s->Print();
	delete s;

	s = new Sort();
	s->QuickSort(true);
	s->Print();
	return 0;
}