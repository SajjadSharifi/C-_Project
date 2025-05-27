#include "CMyTime.h"
#include <iostream>

int main() {
    CMyTime t1(10, 30, 45); // زمان 10:30:45
    CMyTime t2(8, 45, 20);  // زمان 8:45:20

    std::cout << "First Time: ";
    t1.Display();
    std::cout << std::endl;

    std::cout << "Second Time: ";
    t2.Display();
    std::cout << std::endl;

    CMyTime sum = t1.Add(t2);
    std::cout << "Adding Result: ";
    sum.Display();
    std::cout << std::endl;

    CMyTime diff = t1.Diff(t2);
    std::cout << "Different Result: ";
    diff.Display();
    std::cout << std::endl;

    int comparison = t1.Compare(t2);
    std::cout << "Comparing Result: " << comparison << std::endl;

    return 0;
}