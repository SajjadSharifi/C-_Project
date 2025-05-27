#include<iostream>

class Circle {
private:
    float x, y; // Center coordinates
    float radius;
public:
    // Default constructor
    Circle() : x(0), y(0), radius(1) {}

    // Parameterized constructor
    Circle(float x, float y, float r) : x(x), y(y), radius(r) {}

    // Accessors
    float getX() const { return x; }
    float getY() const { return y; }
    float getRadius() const { return radius; }

    // Mutators
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setRadius(float r) { radius = r; }

    // Calculate area
    float area() const {
        return 3.14159f * radius * radius;
    }

    // Print circle info
    void print() const {
        std::cout << "Center: (" << x << ", " << y << "), Radius: " << radius;
    }
};