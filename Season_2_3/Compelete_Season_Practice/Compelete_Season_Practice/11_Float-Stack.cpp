#include<iostream>
class FloatStack {
private:
    static const int MAX_SIZE = 100;
    float data[MAX_SIZE];
    int top;
public:
    FloatStack() : top(-1) {}

    bool push(float value) {
        if (isFull()) return false;
        data[++top] = value;
        return true;
    }

    bool pop(float& value) {
        if (isEmpty()) return false;
        value = data[top--];
        return true;
    }

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX_SIZE - 1; }
    int count() const { return top + 1; }

    void print() const {
        for (int i = 0; i <= top; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};