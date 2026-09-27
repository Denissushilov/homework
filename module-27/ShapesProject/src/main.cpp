#include <iostream>
#include <string>
#include <memory>

#include "../include/Shape.h"
#include "../include/Circle.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"

Color parseColor(int colorCode)
{
    switch(colorCode) {
        case 1: return Color::Red;
        case 2: return Color::Blue;
        case 3: return Color::Green;
        default: return Color::None;
    }
}

void printShapeDetails(const Shape& shape)
{
    shape.printCommonInfo();
    std::cout << "The area of the figure: " << shape.getArea() << "\n";
    BoundingBox box = shape.getBoundingBox();
    std::cout << "Describing rectangle -> Width: " << box.width << ", Height: " << box.height << "\n";
    std::cout << "-------------------------------------------\n";
}

int main()
{
    std::string command;
    std::cout << "Welcome to the geometric processor!\n";
    std::cout << "Available commands: circle, square, triangle, rectangle, exit\n";

    while(true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if(command == "exit") break;

        double x, y;
        int colorCode;
        std::unique_ptr<Shape> currentShape {nullptr};

        if(command == "circle" || command == "square" || command == "triangle" || command == "rectangle") {
            std::cout << "Enter coords of center X and Y: ";
            std::cin >> x >> y;
            std::cout << "Select the color (1 - Red, 2 - Blue, 3 - Green, other - None color): ";
            std::cin >> colorCode;
            Color color = parseColor(colorCode);

            if(command == "circle") {
                double radius;
                std::cout << "Enter radius of circle: ";
                std::cin >> radius;
                currentShape = std::make_unique<Circle>(x, y, color, radius);
            } else if(command == "square") {
                double length;
                std::cout <<"Enter the length of the square’s edge: ";
                std::cin >> length;
                currentShape = std::make_unique<Square>(x, y, color, length);
            } else if(command == "triangle") {
                double length;
                std::cout << "Enter the length of the triangle’s side: ";
                std::cin >> length;
                currentShape = std::make_unique<Triangle>(x, y, color, length);
            } else if(command == "rectangle") {
                double width; 
                double height;
                std::cout << "Enter the width and height of the rectangle: ";
                std::cin >> width >> height;
                currentShape = std::make_unique<Rectangle>(x, y, color, width, height);
            } else {
                std::cout << "Unknown command. Try again.\n";
                continue;
            }

            if(currentShape != nullptr) {
                std::cout << "\n--- Calculation results ---\n";
                printShapeDetails(*currentShape);
            }
        }

    }

    std::cout << "The program has been completed." << std::endl;
    return 0;
}