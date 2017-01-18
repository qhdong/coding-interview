#include <iostream>

using std::cout;
using std::endl;

size_t get_size(int *data) {
    return sizeof(data);
}

int main() {
    int data1[] = {1, 2, 3, 4, 5};
    cout << sizeof(data1) << endl;
    
    int *pdata1 = data1;
    cout << sizeof(pdata1) << endl;

    cout << get_size(data1) << endl;

    return 0;
}
