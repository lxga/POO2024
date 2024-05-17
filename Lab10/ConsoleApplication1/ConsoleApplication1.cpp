#include <iostream>
#include "Array.h"
int main() {
    Array<int> v(100);
    v += 1;
    v += 2;
    v += 3;
    v += 4;
    v += 5;
    v.Sort();
    for (int i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    v.Sort([](const int& a, const int& b) -> int {if (a > b) return -1; else return a < b; });
    for (int i : v) {
        std::cout << i << ' ';
    }
    return 0;
}