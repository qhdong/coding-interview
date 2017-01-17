#include <iostream>

using std::cout;
using std::endl;

long fib(unsigned x) {
    if (x == 0) return 0;
    if (x == 1) return 1;

    long a = 0, b = 1;
    for (unsigned i = 2; i <= x; ++i) {
        b = a + b;
        a = b - a;
    }

    return b;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << fib(i) << " ";
    }

    cout << endl;

    return 0;
}
