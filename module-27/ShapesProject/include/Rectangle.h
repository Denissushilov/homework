#pragma once
#include "Shape.h"

class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double x, double, Color c, double w, double h);
    double getArea() const override;
    BoundingBox getBoundingBox() const override;    
};