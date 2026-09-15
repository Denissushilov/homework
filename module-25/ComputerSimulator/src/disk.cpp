#include "../include/disk.h"
#include "../include/ram.h"
#include <iostream>
#include <fstream>

void save()
{
    std::ofstream file("data.txt");
    if(!file.is_open())
    {
        std::cout << "[DISK] Error: Could not create data.txt\n";
        return;
    }
    for(int i{0}; i < 8; ++i)
        file << read(i) << ' ';
    file.close(); 
    std::cout << "[DISK] RAM state saved to data.txt\n";
}

void load()
{
    std::ifstream file("data.txt");
    if(!file.is_open())
    {
        std::cout << "[DISK] Error: data.txt not found\n";
        return;
    }
    int value {0};

    for(int i {0}; i < 8; ++i)
    {
        if(file >> value)
            write(i, value);
    }

    file.close();
    std::cout << "[DISK] Data loaded from data.txt to RAM\n";
}