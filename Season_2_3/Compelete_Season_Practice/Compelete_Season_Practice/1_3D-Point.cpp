#include <cmath>
#include <iostream>
class Point3D {
private:
    double x, y, z;
public:
    // Default constructor
    Point3D() : x(0), y(0), z(0) {}

    // Parameterized constructor
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Copy constructor
    Point3D(const Point3D& other) : x(other.x), y(other.y), z(other.z) {}

    // Negate the point
    Point3D negative() const {
        return Point3D(-x, -y, -z);
    }

    // Calculate norm (distance from origin)
    double norm() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Print function
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};