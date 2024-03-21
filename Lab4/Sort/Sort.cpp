#include "Sort.h"

Sort::Sort(int nr_elements, int minn, int maxx) {
	if (nr_elements >= 1e8)
		return;
	v = new int[nr_elements];
	this->nr_elements = nr_elements;
	srand(time(NULL));
	for (int i = 0; i < nr_elements; i++) {
		v[i] = minn + rand() % (maxx - minn + 1);
	}
}

Sort::Sort(int* vector, int nr_elements) {
	if (nr_elements >= 1e8)
		return;
	this->nr_elements = nr_elements;
	v = new int[nr_elements];
	for (int i = 0; i < nr_elements;i++) {
		v[i] = vector[i];
	}
}

Sort::Sort(int count, ...) {
	if (count >= 1e8)
		return;
	this->nr_elements = count;
	v = new int[count];
	va_list l;
	va_start(l, count);
	for (int i = 0; i < count; i++) {
		v[i] = va_arg(l,int);
	}
	va_end(l);
}

Sort::Sort(const char* s) {
	int k = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ',')
			k++;
	}
	this->nr_elements = k + 1;
	v = new int[k + 1];
	int nr = 0, c = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ',') {
			v[c++] = nr;
			nr = 0;
		}
		else
			nr += nr * 10 + s[i] - '0';
	}
	v[c] = nr;
}

void Sort::Print() {
	for (int i = 0; i < nr_elements; i++)
		std::cout << v[i] << ' ';
	std::cout << '\n';
}

int Sort::GetElementsCount() {
	return nr_elements;
}

int Sort::GetElementFromIndex(int index) {
	if (index >= nr_elements)
		return -INT_MIN;

	return v[index];
}

void Sort::InsertSort(bool ascendent) {
	for (int i = 0; i < nr_elements; i++) {
		int val = v[i], j = i - 1;
		while (j >= 0 && (ascendent && v[j] > val || !ascendent && v[j] < val)) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = val;
	}
}

void Sort::BubbleSort(bool ascendent) {
	int last = nr_elements - 1;
	while (last > 0) {
		int n = last;
		last = 0;
		for (int i = 0; i < n; i++) {
			if (ascendent && v[i] > v[i + 1] || !ascendent && v[i] < v[i + 1]) {
				std::swap(v[i], v[i + 1]);
				last = i;
			}
		}
	}
}

void Sort::QuickSort(bool ascendent) {
	quicksortrec(ascendent, 0, nr_elements - 1);
}
void Sort::quicksortrec(bool ascendent, int l, int r) {
	if (l < r) {
		int k = partition(ascendent, l, r);
		quicksortrec(ascendent, l, k - 1);
		quicksortrec(ascendent, k + 1, r);
	}
}

int Sort::partition(bool ascendent, int l, int r) {
	int x = v[r];
	int i = (l - 1);
	for (int j = l; j <= r; j++) {
		if (ascendent && v[j]<x || !ascendent && v[j]>x) {
			i++;
			std::swap(v[i], v[j]);
		}
	}
	std::swap(v[i + 1], v[r]);
	return i + 1;
}
