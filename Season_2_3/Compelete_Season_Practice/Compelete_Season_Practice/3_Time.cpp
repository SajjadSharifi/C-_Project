#include <iostream>
class Time {
private:
    int hour, minute, second;
public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        normalize();
    }

    // Reset time
    void reset(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        normalize();
    }

    // Advance time
    void advance(int h, int m, int s) {
        hour += h;
        minute += m;
        second += s;
        normalize();
    }

    // Print time
    void print() const {
        std::cout << hour << ":" << minute << ":" << second;
    }

private:
    // Normalize time values
    void normalize() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }
};