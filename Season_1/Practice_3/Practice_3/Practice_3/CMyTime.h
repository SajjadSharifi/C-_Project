#pragma once
#ifndef CMYTIME_H  // This checks if the macro is not defined
#define CMYTIME_H  // This defines the macro

class CMyTime {
private:
    int hour;    // ساعت 0 تا 23
    int minute;  // دقیقه 0 تا 59
    int second;  // ثانیه 0 تا 59

    void normalize();

public:

    CMyTime();                                   
    CMyTime(int h, int m, int s);               
    CMyTime(const CMyTime& other);              

    CMyTime Diff(const CMyTime& t) const;  // محاسبه تفاضل زمانی
    CMyTime Add(const CMyTime& t) const;   // محاسبه جمع زمانی
    int Compare(const CMyTime& t) const;   // مقایسه دو زمان

    void Display() const;
};

#endif // CMYTIME_H