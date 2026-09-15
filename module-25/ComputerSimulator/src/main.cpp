#include "../include/ram.h"
#include "../include/cpu.h"
#include "../include/disk.h"
#include "../include/gpu.h"
#include "../include/kbd.h"
#include <iostream>
#include <string>

int main() {
    std::string command;
    std::cout << "=== Computer Simulator ===\n";
    std::cout << "Commands: input, sum, save, load, display, exit\n\n";

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Shutting down...\n";
            break;
        } else if (command == "input") {
            input();
        } else if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "display") {
            display();
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
        std::cout << "-------------------------------------\n";
    }

    return 0;
}