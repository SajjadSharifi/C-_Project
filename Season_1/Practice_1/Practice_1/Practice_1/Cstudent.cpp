#include "Cstudent.h"
using namespace std;


string _studentId;
string _studentName;
Lessons _studentLesson[3];
int _sumOfLessonScore;
int _sumOfLessonUnit;

Cstudent::Cstudent(string studentName, string studentId, Lessons& lesson1, Lessons& lesson2, Lessons& lesson3)
	: _sumOfLessonScore(0), _sumOfLessonUnit(0), _studentLesson{ lesson1, lesson2, lesson3 } {
	this->_studentName = studentName;
	this->_studentId = studentId;
}

void Cstudent::ShowReportCard()
{
	cout << "Student ID: " << _studentId << " Student Name: " << _studentName;
	for (int i = 0; i < 3; i++)
	{
		_studentLesson[i].Show();
		cout << "\t Lesson Final Score: " << _studentLesson[i].FinalGrade();
		_sumOfLessonScore += _studentLesson[i].FinalGrade();
		_sumOfLessonUnit += _studentLesson[i].UnitCount;
	}

	cout << "\n Final Grade: " << _sumOfLessonScore / _sumOfLessonUnit;
}