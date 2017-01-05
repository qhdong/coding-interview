#include <iostream>

using std::cout;
using std::endl;

int main() {
    char str1[] = "hello";
    char str2[] = "hello";

    const char *str3 = "hello";
    const char *str4 = "hello";

    if (str1 == str2) {
        cout << "str1 == str2" << endl;
    } else {
        cout << "str1 != str2" << endl;
    }

    if (str3 == str4) {
        cout << "str3 == str4" << endl;
    } else {
        cout << "str3 != str4" << endl;
    }

    return 0;
}
