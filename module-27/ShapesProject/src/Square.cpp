#include "../include/Square.h"

Square::Square(double x, double y, Color c, double length)
: Shape(x, y, c), edgeLength(length) {}

double Square::getArea() const
{
    return edgeLength * edgeLength;
}

BoundingBox Square::getBoundingBox() const
{
    return BoundingBox{edgeLength, edgeLength};
}