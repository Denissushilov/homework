#include "../include/surgery.h"
#include <iostream>
#include <cmath>

Point input_point()
{
    double x{0.0}, y{0.0};
    std::cout << "Input coords X and Y: ";
    std::cin >> x >> y;
    return Point(x, y);
}

bool are_points_equal(const Point& p1, const Point& p2)
{
    const double EPSILON {1e-6};
    return (std::abs(p1.x - p2.x) < EPSILON) && (std::abs(p1.y - p2.y) < EPSILON);
}

void scalpel(const Point& start, const Point& end)
{
    std::cout << "[Scalpel]: a cut has been made from (" << start.x << ", " << start.y <<
    ") to (" << end.x << ", " << end.y << ")\n";
}

void hemostat(const Point& p)
{
    std::cout << "[Clamp] A clamp has been made at the point (" << p.x << ", " << p.y << ")\n";
}

void tweezers(const Point& p)
{
    std::cout << "[Tweezers] Tweezers were used at the point (" << p.x << ", " << p.y << ")\n";
}

void suture(const Point& start, const Point& end)
{
     std::cout << "[Needle] A suture has been applied from (" << start.x << ", " << start.y <<
    ") to (" << end.x << ", " << end.y << ")\n";
}