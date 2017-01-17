#include <iostream>
#include "stack_based_queue.h"

using std::cout;
using std::endl;

int main() {
    Queue<char> queue;
    queue.push('a');
    queue.push('b');
    queue.push('c');
    queue.push('d');

    while (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }

    return 0;
}
