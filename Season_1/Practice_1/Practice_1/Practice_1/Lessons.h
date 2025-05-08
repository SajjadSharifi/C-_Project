#pragma once  // Prevents duplicate includes
#include <iostream>
#include <string>

class Lessons {
public:
    std::string Name;
    int Score;
    int UnitCount;

    Lessons();
    void Show();
    int FinalGrade();
};