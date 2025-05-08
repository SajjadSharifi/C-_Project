#pragma once
#include <vector>
#include <iostream>

class Student {
private:
    std::vector<std::string> _studentName = { "ali", "mohsen", "sajjad" };

public:
    /**
     * Adds a student to the list
     * return 1 if successful, 0 if failed
     */
    int Add(const std::string& studentName);

    /**
     * Deletes a student from the list
     * return 1 if successful, 0 if failed or not found
     */
    int Delete(const std::string& studentName);

    /**
     * Displays all students in the list
     */
    void ShowStudentIdList();
};
