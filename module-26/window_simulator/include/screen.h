#pragma once 
#include "window.h"

class Screen {
private: 
    static const int WIDTH {80};
    static const int HEIGHT {50};

    Window window;

public:
    Screen();
    
    void move_window();
    void resize_window();
    void display() const;
};