#include <iostream>
#include <cstring> //for abs

class Ratio {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int findGCD(int a, int b) {
        return b == 0 ? a : findGCD(b, a % b);
    }

public:
    Ratio(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }

    // Addition operator
    Ratio operator+(const Ratio& other) const {
        return Ratio(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // Division operator
    Ratio operator/(const Ratio& other) const {
        return Ratio(numerator * other.denominator,
            denominator * other.numerator);
    }

    // Prefix decrement
    Ratio& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    // Postfix decrement
    Ratio operator--(int) {
        Ratio temp = *this;
        numerator -= denominator;
        simplify();
        return temp;
    }

    // Subtraction assignment
    Ratio& operator-=(const Ratio& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    // Multiplication assignment
    Ratio& operator*=(const Ratio& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }
    // Greater than operator
    bool operator>(const Ratio& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Less than operator
    bool operator<(const Ratio& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ratio& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }

    // Print ratio
    void print() const {
        std::cout << numerator << "/" << denominator;
    }
};