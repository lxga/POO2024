#include "Math.h"

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return a + b;
}

int Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return a * b;
}

int Math::Mul(double a, double b, double c) {
    return a * b * c;
}

int Math::Add(int count, ...) {
    //TODO
}

char* Math::Add(const char* a, const char* b) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }

    char* res = new char[strlen(a) + strlen(b) + 1];
    strcpy(res, a);
    strcat(res, b);
    return res;
}
