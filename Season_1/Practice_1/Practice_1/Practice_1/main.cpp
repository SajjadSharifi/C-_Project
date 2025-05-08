#include <iostream>
#include <format>
#include "Lessons.h"
#include "Cstudent.h"
using namespace std;
int main()
{
	//تمرین فصل 1
	// تمرین بخش 1 و 2

	int score, unitCount;
	string lessonName;
	//cout << "pls enter score: ";
	//cin >> score;

	//cout << "pls enter unit count: ";
	//cin>> unitCount;
	//
	//cout << "pls enter lesson Name: ";
	//cin >> lessonName;
	//
	//Lessons lesson1;
	//lesson1.Name = lessonName;
	//lesson1.UnitCount = unitCount;
	//lesson1.Score = score;

	//lesson1.Show();
	//cout << "Your Final Grade: " << lesson1.FinalGrade();

	// تمرین بخش 1 و 2

	// تمرین بخش 3
	string studentName;
	string studentId;
	Lessons LessonList[3];
	cout << "welcome to training_session 3 \n \n";
	cout << "Pls Enter Student ID: ";
	cin >> studentId;
	cout << "Pls Enter Student Name: ";
	cin >> studentName;

	for (int i = 0; i < 3; i++)
	{
		cout << "pls enter " << "lesson " << i + 1 << " Name: ";
		cin >> lessonName;

		cout << "pls enter " << "lesson "<< i+1 <<" score: ";
		cin >> score;

		cout << "pls enter " << "lesson " << i + 1 << " unit count: ";
		cin >> unitCount;

		LessonList[i].Score = score;
		LessonList[i].Name = lessonName;
		LessonList[i].UnitCount = unitCount;
	}
	Cstudent student(studentName, studentId, LessonList[0], LessonList[1], LessonList[2]);

	student.ShowReportCard();
}