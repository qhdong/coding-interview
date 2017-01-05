#include <iostream>

class Empty {
    public:
        Empty() {
            std::cout << "Constructor called" << std::endl;
        }
        virtual ~Empty() {
            std::cout << "Desctructor called" << std::endl;
        }
};

int main() {
    Empty empty;
    // 析构函数为虚函数，Empty类型有一个虚函数表，所有实例均含有一个指向徐函数
    // 的指针，在64位机器上为8字节
    std::cout << sizeof(empty) << std::endl;

    return 0;
}

