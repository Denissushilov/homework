#include "../include/cpu.h"
#include "../include/ram.h"
#include <iostream>

void compute()
{
    int sum {0};
    for(int i{0}; i < 8; ++i)
        sum += read(i);

        std::cout << "[CPU] Sum of RAM buffer: " << sum << "\n";
}