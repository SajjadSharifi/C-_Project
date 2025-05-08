#include "Lessons.h"
using namespace std;


Lessons::Lessons() {};
string Name;
int Score;
int UnitCount;

void Lessons::Show()
{
	cout << "\n Lesson Name: " << Name << endl << "\t Units: "
		<< UnitCount << endl << " \t Exam Score: " << Score << endl;
}

int Lessons::FinalGrade()
{
	return UnitCount * Score;
}

