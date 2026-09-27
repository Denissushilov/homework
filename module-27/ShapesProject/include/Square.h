#pragma once
#include "Shape.h"

class Square : public Shape {
    double edgeLength;
public:
    Square(double x, double y, Color c, double length);
    double getArea() const override;
    BoundingBox getBoundingBox() const override;    
};