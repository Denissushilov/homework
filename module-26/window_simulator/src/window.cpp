#include "../include/window.h"

Window::Window(int in_x, int in_y, int in_w, int in_h)
: x(in_x), y(in_y), width(in_w), height(in_h) {}

int Window::get_x() const { return x; }
int Window::get_y() const { return y; }
int Window::get_width() const { return width; }
int Window::get_height() const { return height; }

void Window::move(int dx, int dy, int screen_width, int screen_height)
{
    int new_x = x + dx;
    if(new_x < 0) new_x = 0;
    if(new_x > screen_width-1) new_x = screen_width-1;
    this->x = new_x;

    int new_y = y + dy;
    if(new_y < 0) new_y = 0;
    if(new_y > screen_height-1) new_y = screen_height-1;
    this->y = new_y;
}

void Window::resize(int new_w, int new_h, int screen_width, int screen_height)
{
    if(new_w < 0) new_w = 0;
    if(new_h < 0) new_h = 0;

    if(x + new_w > screen_width) new_w = screen_width - x;
    if(y + new_h > screen_height) new_h = screen_height - y;

    width = new_w;
    height = new_h;
}