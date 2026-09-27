#include "../include/Circle.h"
#include <cmath>

Circle::Circle(double x, double y, Color c, double r)
: Shape(x, y, c), radius(r) {}

double Circle::getArea() const
{
    return std::atan(1.0) * 4.0 * radius * radius;
}

BoundingBox Circle::getBoundingBox() const
{
    return BoundingBox{ radius * 2.0, radius * 2.0};
}