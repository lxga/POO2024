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
    va_list vl;
    va_start(vl, count);
    int ans = 0;
    for (int i = 0; i < count; i++) {
        ans += va_arg(vl, int);
    }
    va_end(vl);
    return ans;
}

char* Math::Add(const char* a, const char* b) {
    if (a == nullptr || b == nullptr)
        return nullptr;

    int la = strlen(a), lb = strlen(b), k = std::max(la, lb);
    char* ans = new char[k + 2];
    int t = 0;
    ans[0] = '\7';
    ans[k + 1] = '\0';
    la--;
    lb--;
    while (la >= 0 && lb >= 0) {
        ans[k] = a[la] + b[lb] - 2 * '0' + t;
        t = ans[k] / 10;
        ans[k] %= 10;
        ans[k] += '0';
        la--;
        lb--;
        k--;
    }
    while (la >= 0) {
        ans[k] = a[la] - '0' + t;
        t = ans[k] / 10;
        ans[k] %= 10;
        ans[k] += '0';
        la--;
        k--;
    }
    while (lb >= 0) {
        ans[k] = b[lb] - '0' + t;
        t = ans[k] / 10;
        ans[k] %= 10;
        ans[k] += '0';
        t = 0;
        lb--;
        k--;
    }
    if (t != 0)
        ans[0] = '1';
    if (ans[0] == '\7') {
        while (ans[k]) {
            ans[k] = ans[k + 1];
            k++;
        }
    }
    return ans;
}
