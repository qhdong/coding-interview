#ifndef _STACK_BASED_QUEUE_H_
#define _STACK_BASED_QUEUE_H_

#include <stack>

template <typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;
    
    void push(const T &x);
    void pop();
    T& front();
    bool empty() const;

private:
    std::stack<T> stack;
};

template <typename T>
void Queue<T>::push(const T &x) {
    std::stack<T> tmp;
    while (!stack.empty()) {
        tmp.push(stack.top());
        stack.pop();
    }
    stack.push(x);
    while (!tmp.empty()) {
        stack.push(tmp.top());
        tmp.pop();
    }
}

template <typename T>
void Queue<T>::pop() {
    stack.pop();
}

template <typename T>
T& Queue<T>::front() {
    return stack.top();
}

template <typename T>
bool Queue<T>::empty() const {
    return stack.empty();
}

#endif
