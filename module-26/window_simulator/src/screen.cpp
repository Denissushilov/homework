#include "../include/screen.h"
#include <iostream>

Screen::Screen() : window(0, 0, 10, 10) {}

void Screen::move_window() {
    int dx, dy;
    std::cout << "Enter shift vector (dx and dy): ";
    std::cin >> dx >> dy;

    window.move(dx, dy, WIDTH, HEIGHT);
    std::cout << "[MOVE] New window coordinates: X = " << window.get_x() 
              << ", Y = " << window.get_y() << "\n";
}

void Screen::resize_window() {
    int new_w, new_h;
    std::cout << "Enter new size (width and height): ";
    std::cin >> new_w >> new_h;

    window.resize(new_w, new_h, WIDTH, HEIGHT);
    std::cout << "[RESIZE] New window size: Width = " << window.get_width() 
              << ", Height = " << window.get_height() << "\n";
}

void Screen::display() const {
    int win_x = window.get_x();
    int win_y = window.get_y();
    int win_w = window.get_width();
    int win_h = window.get_height();

    std::cout << "\n=== Monitor Screen (80x50) ===\n";
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
           
            if (j >= win_x && j < win_x + win_w && i >= win_y && i < win_y + win_h) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
        std::cout << "\n";
    }
    std::cout << "==============================\n";
}