#pragma once

struct Point {
    double x{0.0}, y{0.0};
    Point(double x = 0.0, double y = 0.0)
    : x(x), y(y) {  }
};

Point input_point();
bool are_points_equal(const Point& p1, const Point& p2);

void scalpel(const Point& start, const Point& end);
void hemostat(const Point& p);
void tweezers(const Point& p);
void suture(const Point& start, const Point& end);