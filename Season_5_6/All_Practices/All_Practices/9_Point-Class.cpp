#include<iostream>
class Point2D {
private:
    double x, y;

public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Addition operator
    Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
    }

    // Multiplication operator (dot product)
    double operator*(const Point2D& other) const {
        return x * other.x + y * other.y;
    }

    // Print point
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};