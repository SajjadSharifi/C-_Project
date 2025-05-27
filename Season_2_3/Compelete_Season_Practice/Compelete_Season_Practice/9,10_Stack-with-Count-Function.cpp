#include<iostream>
#include "2_Integer-Stack.cpp"
class IntStackWithCount : public IntStack {
public:
    // Get count of elements
    int count() const {
        return top + 1;
    }
};

class IntStackWithPrint : public IntStackWithCount {
public:
    // Print stack contents
    void print() const {
        for (int i = 0; i <= top; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};