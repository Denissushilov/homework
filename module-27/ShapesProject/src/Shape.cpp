#include "../include/Shape.h"
#include <iostream>

Shape::Shape(double x, double y, Color c) : centerX(x), centerY(y), color(c) {}

std::string Shape::getColorName() const 
{
    switch(color) {
        case Color::Red: return "Red";
        case Color::Blue: return "Blue";
        case Color::Green: return "Green";
        default: return "No color";
    }
}

void Shape::printCommonInfo() const 
{
    std::cout << "Center: (" << centerX << ", " << centerY << ") | Color: " << getColorName() << "\n";
}