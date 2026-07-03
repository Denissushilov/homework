#include <iostream>
#include <cmath>
#include <iomanip> // Для красивого вывода координат с плавающей точкой

struct Vector {
private:
    double x{0.0}, y{0.0};
public:
    Vector(double a = 0.0, double b = 0.0) : x(a), y(b) {}
    Vector(const Vector& other) : x(other.x), y(other.y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void add(const Vector& other) {
        this->x += other.x;
        this->y += other.y;
    }

    void subtract(const Vector& other) {
        this->x -= other.x;
        this->y -= other.y;
    }

    void scale(double k) {
        this->x *= k;
        this->y *= k;
    }

    void normalize() {
        double mod = this->length();
        if (mod > 0.0) {
            this->x /= mod;
            this->y /= mod;
        }
    }

    static Vector add(const Vector& a, const Vector& b) {
        return Vector(a.x + b.x, a.y + b.y);
    }

    static Vector subtract(const Vector& a, const Vector& b) {
        return Vector(a.x - b.x, a.y - b.y);
    }

    static Vector scale(const Vector& a, double k) {
        return Vector(a.x * k, a.y * k);
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }


    void print() const {
        std::cout << "Current Vector: (" << x << ", " << y << ")\n";
    }
};

enum Commands {QUIT, ADD, SUBTRACT, SCALE, NORMALIZE, LENGTH};

int main() {
   

    return 0;
}
