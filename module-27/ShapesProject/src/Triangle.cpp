#include "../include/Triangle.h"
#include <cmath>

Triangle::Triangle(double x, double y, Color c, double length)
: Shape(x, y, c), edgeLength(length) {}

double Triangle::getArea() const
{
    return edgeLength * edgeLength * std::sqrt(3.0) / 4.0;
}

BoundingBox Triangle::getBoundingBox() const 
{
    double height = (edgeLength * std::sqrt(3.0)) / 2.0;
    return BoundingBox{edgeLength, height};
}