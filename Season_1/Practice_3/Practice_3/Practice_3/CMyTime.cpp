#include "CMyTime.h"  // شامل کردن فایل هدر کلاس
#include <iostream>    
#include <cmath>       // برای تابع abs

// سازنده پیش‌فرض مقداردهی اولیه به 00:00:00
CMyTime::CMyTime() : hour(0), minute(0), second(0) {}


CMyTime::CMyTime(int h, int m, int s) : hour(h), minute(m), second(s) {
    normalize(); // نرمال‌سازی مقادیر ورودی
}


CMyTime::CMyTime(const CMyTime& other)
    : hour(other.hour), minute(other.minute), second(other.second) {
}


CMyTime CMyTime::Diff(const CMyTime& t) const {
    // تبدیل هر دو زمان به ثانیه
    int totalSeconds1 = hour * 3600 + minute * 60 + second;
    int totalSeconds2 = t.hour * 3600 + t.minute * 60 + t.second;

    // محاسبه اختلاف مطلق همیشه مثبت
    int diffSeconds = abs(totalSeconds1 - totalSeconds2);

    // تبدیل مجدد به فرمت ساعت:دقیقه:ثانیه
    return CMyTime(
        diffSeconds / 3600,     
        (diffSeconds % 3600) / 60, 
        diffSeconds % 60        
    );
}


CMyTime CMyTime::Add(const CMyTime& t) const {
    // محاسبه کل ثانیه‌ها
    int totalSeconds = (hour + t.hour) * 3600 +
        (minute + t.minute) * 60 +
        (second + t.second);

    // تبدیل به فرمت استاندارد
    return CMyTime(
        totalSeconds / 3600,      
        (totalSeconds % 3600) / 60, 
        totalSeconds % 60        
    );
}


int CMyTime::Compare(const CMyTime& t) const {
    if (hour > t.hour) return 1;
    if (hour < t.hour) return -1;

    if (minute > t.minute) return 1;
    if (minute < t.minute) return -1;

    if (second > t.second) return 1;
    if (second < t.second) return -1;

    return 0; // تمام مقادیر برابر بودند
}

void CMyTime::Display() const {
    std::cout << hour << ":" << minute << ":" << second;
}

void CMyTime::normalize() {
    // تبدیل ثانیه‌های اضافه به دقیقه
    minute += second / 60;
    second = second % 60;

    // تبدیل دقیقه‌های اضافه به ساعت
    hour += minute / 60;
    minute = minute % 60;

    // محدود کردن ساعت به محدوده 0-23
    hour = hour % 24;
}