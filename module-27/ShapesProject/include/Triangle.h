#pragma once
#include "Shape.h"

class Triangle : public Shape {
    double edgeLength;
public:
    Triangle(double x, double y, Color c, double length);
    double getArea() const override;
    BoundingBox getBoundingBox() const override;    
};