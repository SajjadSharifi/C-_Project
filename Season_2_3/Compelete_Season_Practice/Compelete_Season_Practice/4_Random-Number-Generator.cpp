#include <cstdlib>
#include <ctime>

class Random {
public:
    Random() {
        srand(time(0)); // Seed with current time
    }

    // Generate random integer between min and max
    int nextInt(int min, int max) {
        return min + rand() % (max - min + 1);
    }

    // Generate random double between 0 and 1
    double nextDouble() {
        return static_cast<double>(rand()) / RAND_MAX;
    }
};