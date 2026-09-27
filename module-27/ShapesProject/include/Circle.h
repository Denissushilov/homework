#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double x, double y, Color c, double r);
    double getArea() const override;
    BoundingBox getBoundingBox() const override;      
};