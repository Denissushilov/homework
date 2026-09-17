#include "../include/screen.h"
#include <iostream>
#include <string>

int main() {
    Screen monitor;
    std::string command;

    std::cout << "=== Window Manager Simulator ===\n";
    std::cout << "Commands: move, resize, display, close\n\n";

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "close") {
            std::cout << "Closing window and shutting down...\n";
            break;
        } else if (command == "move") {
            monitor.move_window();
        } else if (command == "resize") {
            monitor.resize_window();
        } else if (command == "display") {
            monitor.display();
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
        std::cout << "-------------------------------------\n";
    }

    return 0;
}
