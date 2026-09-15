#include "../include/kbd.h"
#include "../include/ram.h"
#include <iostream>

void input()
{
    std::cout << "[KBD] Enter 8 integers: ";
    int value{0};
    for(int i{0}; i < 8; ++i)
    {
        std::cin >> value;
        write(i, value);
    }
}