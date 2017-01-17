#include <iostream>
#include "queue_based_stack.h"

using std::cout;
using std::endl;

int main() {
    Stack<char> stack;
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.push('e');

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << endl;

    return 0;
}
