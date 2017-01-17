#ifndef _QUEUE_BASED_STACK_H_
#define _QUEUE_BASED_STACK_H_

#include <queue>

template <typename T>
class Stack {
public:
    Stack() = default;
    ~Stack() = default;

    void push(const T &x);
    void pop();
    T& top();
    bool empty() const;

private:
    std::queue<T> queue;
};


template <typename T>
void Stack<T>::push(const T &x) {
    queue.push(x);
    for (decltype(queue.size()) i = 0; i < queue.size()-1; ++i) {
        queue.push(queue.front());
        queue.pop();
    }
}

template <typename T>
void Stack<T>::pop() {
    queue.pop();
}

template <typename T>
T& Stack<T>::top() {
    return queue.front();
}

template <typename T>
bool Stack<T>::empty() const {
    return queue.empty();
}


#endif
