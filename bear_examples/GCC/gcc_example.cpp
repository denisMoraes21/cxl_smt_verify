//
// Created by denis on 25/10/24.
//
// gcc_example.cpp
#include <iostream>

int main() {
    int num = 42;
    int count = __builtin_popcount(num); // Função específica do GCC
    std::cout << "Número de bits '1' em " << num << ": " << count << std::endl;
    return 0;
}
