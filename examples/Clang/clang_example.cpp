//
// Created by denis on 25/10/24.
//
// clang_example.cpp
#include <iostream>

__attribute__((overloadable)) void print(int x) {
    std::cout << "Inteiro: " << x << std::endl;
}

__attribute__((overloadable)) void print(double x) {
    std::cout << "Double: " << x << std::endl;
}

int main() {
    print(42);
    print(3.14);
    return 0;
}
