#pragma once
#include <string>

enum class Color {
    None,
    Red,
    Blue,
    Green
};

struct BoundingBox {
    double width;
    double height;
};

class Shape {
protected:
    double centerX;
    double centerY;
    Color color;   
public:
    Shape(double x, double y, Color c); 
    
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual BoundingBox getBoundingBox() const = 0;

    std::string getColorName() const;
    void printCommonInfo() const;
};