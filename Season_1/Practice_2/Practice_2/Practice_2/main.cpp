#include "Student.h"  // Fixed typo in filename
#include <iostream>   // For std::cout

using namespace std;

int main()
{
    Student student1;
    student1.ShowStudentIdList();
    student1.Add("fashid");
    student1.Delete("mohsen");
    student1.ShowStudentIdList();

    static int choose = 1;
    string name;
    while (choose == 1)
    {
        cout << "\n wanna add something? type 1 if you wanted: ";
        cin >> choose;
        if (choose == 1) {
            cout << "pls enter your name: ";
            cin >> name;
            student1.Add(name);
        }
        else {
            student1.ShowStudentIdList();
            cout << "\n Goodbye :-) ";
        }
    }
    return 0;
}