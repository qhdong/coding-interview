#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * 输入excel中列的英文字母表达方法，输出对应的10进制数字
 * 假设输入为大写英文
 */
unsigned interpret(string str) {
    unsigned res = 0;
    for (auto c : str) {
        res = res * 26 + c - 'A' + 1; 
    }
    return res;
}

void test(const char *test_name, string str, unsigned expected) {
    if (test_name != nullptr) {
        cout << test_name << " begins: ";
    }
    unsigned res = interpret(str);
    if (expected == res) {
        cout << " passed." << endl;
    } else {
        cout << " failed." << endl;
    }
}

void testcase_1() {
    test("Test1", "A", 1);
    test("Test2", "B", 2);
    test("Test3", "Z", 26);
    test("Test4", "AA", 27);
}


int main() {
    testcase_1();
    return 0;
}
