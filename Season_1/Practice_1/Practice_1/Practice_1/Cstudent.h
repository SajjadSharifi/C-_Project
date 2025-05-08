#pragma once
#include "Lessons.h"

class Cstudent {
private:
    std::string _studentId;
    std::string _studentName;
    Lessons _studentLesson[3];
    int _sumOfLessonScore;
    int _sumOfLessonUnit;

public:
    Cstudent(std::string studentName, std::string studentId, Lessons& lesson1, Lessons& lesson2, Lessons& lesson3);
    void ShowReportCard();
};