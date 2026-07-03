#include <iostream>
#include <cmath>
#include <string>

struct Vector {
private:
    double x{0.0};
    double y{0.0};

public:
    Vector(double a = 0.0, double b = 0.0) : x(a), y(b) {}
    Vector(const Vector& other) : x(other.x), y(other.y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void add(const Vector& other)
    {
        this->x += other.x;
        this->y += other.y;
    }

    void subtract(const Vector& other)
    {
        this->x -= other.x;
        this->y -= other.y;
    }

    void scale(double k)
    {
        this->x *= k;
        this->y *= k;
    }

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    void normalize()
    {
        double mod = this->length();
        if (mod > 0.0) {
            this->x /= mod;
            this->y /= mod;
        }
    }

    void print() const {
        std::cout << "Result Vector: (" << x << ", " << y << ")" << std::endl;
    }
};

Vector inputVector() {
    double x{0.0}, y{0.0};
    std::cout << "Enter vector coordinates (x y): ";
    std::cin >> x >> y;
    return Vector(x, y);
}

Vector add(const Vector& a, const Vector& b) {
    Vector result = a; 
    result.add(b);     
    return result;
}

Vector subtract(const Vector& a, const Vector& b) {
    Vector result = a;
    result.subtract(b);
    return result;
}

Vector scale(const Vector& v, double k) {
    Vector result = v;
    result.scale(k);
    return result;
}
double length(const Vector& v) {
    return v.length(); // Вызываем внутренний метод
}

Vector normalize(const Vector& v) {
    Vector result = v;
    result.normalize();
    return result;
}

int main() {
    std::string operation;
    std::cout << "=== VECTOR CALCULATOR ===" << std::endl;
    std::cout << "Enter command (add, subtract, scale, length, normalize): ";
    std::cin >> operation;

    if (operation == "add") {
        std::cout << "First vector:" << std::endl;
        Vector v1 = inputVector();
        std::cout << "Second vector:" << std::endl;
        Vector v2 = inputVector();

        Vector result = add(v1, v2);
        result.print();
    } 
    else if (operation == "subtract") {
        std::cout << "First vector:" << std::endl;
        Vector v1 = inputVector();
        std::cout << "Second vector:" << std::endl;
        Vector v2 = inputVector();

        Vector result = subtract(v1, v2);
        result.print();
    } 
    else if (operation == "scale") {
        Vector v = inputVector();
        double k{0.0};
        std::cout << "Enter scalar value: ";
        std::cin >> k;

        Vector result = scale(v, k);
        result.print();
    } 
    else if (operation == "length") {
        Vector v = inputVector();
        double resLength = length(v);
        std::cout << "Result Length: " << resLength << std::endl;
    } 
    else if (operation == "normalize") {
        Vector v = inputVector();
        Vector result = normalize(v);
        result.print();
    } 
    else {
        std::cout << "Unknown command!" << std::endl;
    }

    return 0;
}
