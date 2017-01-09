#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

unsigned pop_count(int x) {
    unsigned i = 1;
    unsigned count = 0;
    while (i) {
        if (x & i) {
            ++count;
        }
        i <<= 1;
    }

    return count;
}

unsigned pop_count_by_clearing(int x) {
    unsigned count = 0;
    while (x) {
        ++count;
        x &= (x - 1);
    }
    return count;
}

unsigned pop_count_by_table(int x) {
    unsigned pc[256] = {0};
    for (int i = 0; i < 256; ++i) {
        pc[i] = pc[i>>1] + (i & 1);
    }

    return pc[static_cast<unsigned char>(x >> 0*8)]
         + pc[static_cast<unsigned char>(x >> 1*8)]
         + pc[static_cast<unsigned char>(x >> 2*8)]
         + pc[static_cast<unsigned char>(x >> 3*8)];
}

void test(const string test_name, int x, unsigned expected) {
    if (!test_name.empty()) cout << test_name << " starts...";
    if (pop_count_by_table(x) == expected) {
        cout << "succeed." << endl;
    } else {
        cout << "failed." << endl;
    }
}

int main() {
    test("test1", 0xff, 8);
    test("test2", -1, 32);

    return 0;
}
