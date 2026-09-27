#include "../include/Rectangle.h"

Rectangle::Rectangle(double x, double y, Color c, double w, double h)
: Shape(x, y, c), width(w), height(h) {}

double Rectangle::getArea() const
{
    return width * height;
}

BoundingBox Rectangle::getBoundingBox() const
{
    return BoundingBox{width, height};
}