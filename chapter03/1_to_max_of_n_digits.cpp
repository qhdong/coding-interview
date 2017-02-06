#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

bool increment(string &number);
void print_number(const string &number);
void print_n_digits(int n);
void print_n_digits_recursively(string &number, int length, int pos);

void print_1_to_max_of_n_digits(int n) {
    if (n <= 0) {
        return;
    }

    string number(n, '0');
    int count = 0;
    while (increment(number)) {
        print_number(number);

        ++count;
        if (count % 10 == 0) {
            count = 0;
            cout << endl;
        } else {
            cout << "\t";
        }
    }

    cout << endl;
}

bool increment(string &number) {
    int carry = 0;
    bool overflow = false;
    int length = number.size();
    for (auto pos = length - 1; pos >= 0; --pos) {
        int sum = number[pos] - '0' + carry;
        if (pos == length - 1) {
            ++sum;
        }

        if (sum >= 10) {
            if (pos == 0) {
                overflow = true;
            } else {
                sum -= 10;
                carry = 1;
                number[pos] = sum + '0';
            }
        } else {
            number[pos] = sum + '0';
            break;
        }
    }

    return !overflow;
}

void print_number(const string &number) {
    auto pos = number.find_first_not_of('0');
    if (pos == string::npos) {
        cout << 0;
        return;
    }
    cout << number.substr(pos);
}

void print_n_digits(int n) {
    string number(n, '0');
    print_n_digits_recursively(number, n, 0);
}

void print_n_digits_recursively(string &number, int length, int pos) {
    if (pos == length) {
        print_number(number);
        cout << endl;
        return;
    }
    for (int i = 0; i < 10; ++i) {
        number[pos] = i + '0';
        print_n_digits_recursively(number, length, pos+1);
    }
}

int main(int argc, char **argv) {
    int n = 2;
    if (argc == 2) {
        n = std::atoi(argv[1]);
    }
    // print_1_to_max_of_n_digits(n);
    print_n_digits(n);

    return 0;
}
