#pragma once
#include <cstdarg>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Sort {
    int* v = nullptr;
    int nr_elements;
    void quicksortrec(bool ascendent, int l, int r);
    int partition(bool ascendent, int l, int r);
public:
    Sort(int nr_elements, int minn, int maxx);
    Sort(int* vector, int nr_elements);
    Sort(int count, ...);
    Sort(const char* s);
    Sort() : v(new int[6] {1,2,3,4,5,6}), nr_elements(6) {};

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

};