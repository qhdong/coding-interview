#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcmp;

void replace_blank(char *str, int len) {
    if (str == nullptr || len <= 0) return;

    int blank = 0;
    char *p1 = str;

    int origin_len = 0;
    while (*p1 != '\0') {
        if (*p1 == ' ') ++blank;
        ++p1;
        ++origin_len;
    }
    if (origin_len + 2*blank > len) return;

    char *p2 = p1 + 2*blank;
    while (p1 != p2) {
        if (*p1 == ' ') {
            *p2-- = '0';
            *p2-- = '2';
            *p2-- = '%';
            --p1;
        } else {
            *p2-- = *p1--;
        }
    }
}

void test(const char *test_name, char *str, int len, const char *expected) {
    if (test_name != nullptr) {
        cout << test_name << " begins: ";
    }
    replace_blank(str, len);
    if (expected == nullptr && str == nullptr) {
        cout << " passed." << endl;
    } else if (expected == nullptr && str != nullptr) {
        cout << " faild." << endl;
    } else if (strcmp(str, expected) == 0) {
        cout << " passed." << endl;
    } else {
        cout << " failed." << endl;
    }
}

void test1() {
    const int len = 100;
    char str[len] = "hello world";
    test("Test1", str, len, "hello%20world");
}

void test2() {
    const int len = 100;
    char str[len] = " helloworld";
    test("Test2", str, len, "%20helloworld");
}

void test3() {
    const int len = 100;
    char str[len] = " hello world ";
    test("Test3", str, len, "%20hello%20world%20");
}

void test4() {
    test("Test4", nullptr, 0, nullptr);
}

void test5() {
    const int len = 100;
    char str[len] = "     ";
    test("Test5", str, len, "%20%20%20%20%20");
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
