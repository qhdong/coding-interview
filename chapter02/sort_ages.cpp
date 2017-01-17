#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/**
 * 对年龄排序，使用桶排序思路
 * 时间O(N), 空间O(N)
 */
void sort_ages(vector<int> &ages) {
    const vector<int>::size_type oldestAge = 99;
    vector<int> timesOfAge(oldestAge + 1, 0);
    for (auto age : ages) {
        timesOfAge[age]++;
    }
    vector<int>::size_type index = 0;
    for (decltype(timesOfAge.size()) i = 0; i < oldestAge; ++i) {
        while (timesOfAge[i]) {
            ages[index++] = i;
            --timesOfAge[i];
        }
    }
}

void print_vector(const vector<int> &v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> ages = {33, 18, 45, 22, 50, 29, 23, 24, 25, 40, 55, 60};
    print_vector(ages);
    sort_ages(ages);
    print_vector(ages);
    return 0;
}
