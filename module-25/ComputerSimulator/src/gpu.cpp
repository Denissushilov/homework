#include "../include/gpu.h"
#include "../include/ram.h"
#include <iostream>

void display()
{
    std::cout << "[GPU] RAM Buffer display: ";
    for(int i{0}; i < 8; ++i)
    {
        std::cout << read(i) << ' ';
    }
    std::cout << '\n';
}