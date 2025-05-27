#include<iostream>
class Point2D {
private:
    double x, y;
public:
    // Default constructor
    Point2D() : x(0), y(0) {}

    // Parameterized constructor
    Point2D(double x, double y) : x(x), y(y) {}

    // Copy constructor
    Point2D(const Point2D& other) : x(other.x), y(other.y) {}

    // Negate the point
    Point2D negative() const {
        return Point2D(-x, -y);
    }

    // Calculate norm (distance from origin)
    double norm() const {
        return sqrt(x * x + y * y);
    }

    // Print point
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};