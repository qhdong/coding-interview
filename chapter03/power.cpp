#include <iostream>

using std::cout;
using std::endl;

double power_with_unsigned_exponent(double base, unsigned int exponent);
bool equal(double num1, double num2);

bool g_InvalidInput = false;
double power(double base, double exponent) {
    g_InvalidInput = false;

    // 0的负数次方无效
    if (equal(base, 0.0) && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }

    double result = power_with_unsigned_exponent(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }

    return result;
}

double power_with_unsigned_exponent(double base, unsigned int exponent) {
    if (exponent == 0) return 1.0;
    if (exponent == 1) return base;
    double result = power_with_unsigned_exponent(base, exponent >> 1);
    result *= result;
    if (exponent & 1) {
        result *= base;
    }

    return result;
}

// 检测两个double是否相等，如果在一定小的误差内则认为相等
bool equal(double num1, double num2) {
    double e = 1e-8;
    return (num1 - num2) > -e && (num1 - num2) < e;
}

int main() {
    cout << "power(2, 3) = " << power(2, 3) << endl;
    cout << "power(2, -3) = " << power(2, -3) << endl;
    cout << "power(0, 3) = " << power(0, 3) << endl;
    cout << "power(2, 0) = " << power(2, 0) << endl;
    cout << "power(2, 1) = " << power(2, 1) << endl;
    cout << "power(2, 20) = " << power(2, 20) << endl;
    cout << "power(0, -1) = " << power(0, -1) << endl;
    cout << g_InvalidInput << endl;

    return 0;
}
