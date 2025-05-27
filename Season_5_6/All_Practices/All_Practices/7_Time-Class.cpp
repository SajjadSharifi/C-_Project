class Time {
private:
    int hour, minute, second;

    void normalize() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        normalize();
    }

    // Subtraction operator
    Time operator-(const Time& other) const {
        int totalSec = (hour - other.hour) * 3600 +
            (minute - other.minute) * 60 +
            (second - other.second);
        return Time(totalSec / 3600, (totalSec % 3600) / 60, totalSec % 60);
    }

    // Equality operator
    bool operator==(const Time& other) const {
        return hour == other.hour && minute == other.minute && second == other.second;
    }

    // Less than operator
    bool operator<(const Time& other) const {
        if (hour != other.hour) return hour < other.hour;
        if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }
};