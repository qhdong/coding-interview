#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int min_in_order(const vector<int> &numbers, int begin, int end) {
    int ret = numbers[begin];
    for (auto i = begin + 1; i <= end; ++i) {
        if (ret > numbers[i]) {
            ret = numbers[i];
        }
    }

    return ret;
}

int min(const vector<int> &numbers) {
    if (numbers.empty()) return -1;
    vector<int>::size_type left = 0;
    vector<int>::size_type right = numbers.size() - 1;
    vector<int>::size_type mid = left;

    while (numbers[left] >= numbers[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }

        mid = (left + right) >> 1;
        if (numbers[left] == numbers[right] && numbers[left] == numbers[mid]) {
            return min_in_order(numbers, left, right);
        }

        if (numbers[mid] >= numbers[left]) {
            left = mid;
        } else if (numbers[mid] <= numbers[right]) {
            right = mid;
        }
    }

    return numbers[mid];
}

int main() {
    vector<int> arr = {3, 4, 5, 1, 1, 2};
    cout << min(arr) << endl;

    return 0;
}
