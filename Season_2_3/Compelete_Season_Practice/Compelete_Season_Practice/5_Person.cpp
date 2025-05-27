#include <string>
#include<iostream>

class Person {
private:
    std::string name;
    int birthYear;
    int deathYear;
public:
    // Default constructor
    Person() : name(""), birthYear(0), deathYear(0) {}

    // Parameterized constructor
    Person(std::string n, int b, int d) : name(n), birthYear(b), deathYear(d) {}

    // Destructor
    ~Person() {}

    // Accessors
    std::string getName() const { return name; }
    int getBirthYear() const { return birthYear; }
    int getDeathYear() const { return deathYear; }

    // Mutators
    void setName(std::string n) { name = n; }
    void setBirthYear(int y) { birthYear = y; }
    void setDeathYear(int y) { deathYear = y; }

    // Print person info
    void print() const {
        std::cout << name << " (" << birthYear << "-" << deathYear << ")";
    }
};