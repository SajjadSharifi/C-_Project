class IntStack {
private:
    static const int MAX_SIZE = 100;
protected:
    int top;
    int data[MAX_SIZE];

public:
    // Constructor
    IntStack() : top(-1) {}

    // Destructor
    ~IntStack() {}

    // Push operation
    bool push(int value) {
        if (isFull()) return false;
        data[++top] = value;
        return true;
    }

    // Pop operation
    bool pop(int& value) {
        if (isEmpty()) return false;
        value = data[top--];
        return true;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

};