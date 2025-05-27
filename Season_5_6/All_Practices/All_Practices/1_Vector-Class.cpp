#include <iostream>
#include <cstring> // for memcpy

class Vector {
private:
    double* data;
    size_t size;
public:
    // Default constructor
    Vector(size_t n = 0) : size(n), data(n ? new double[n]() : nullptr) {}

    // Copy constructor
    Vector(const Vector& other) : size(other.size), data(other.size ? new double[other.size] : nullptr) {
        if (data) memcpy(data, other.data, size * sizeof(double));
    }

    // Destructor
    ~Vector() { delete[] data; }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new double[size] : nullptr;
            if (data) memcpy(data, other.data, size * sizeof(double));
        }
        return *this;
    }

    // Equality operator
    bool operator==(const Vector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    // Print vector
    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << "]";
    }
};