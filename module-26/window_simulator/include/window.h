#pragma once

class Window {
private:
    int x {0}, y{0};
    int width{10}, height{10};
    
public:
    Window(int in_x, int in_y, int in_w, int in_h);
    
    int get_x() const;
    int get_y() const;
    int get_width() const;
    int get_height() const;

    void move(int dx, int dy, int screen_width, int screen_height);

    void resize(int new_w, int new_h, int screen_width, int screen_height);
};