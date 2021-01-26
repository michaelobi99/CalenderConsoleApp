#include "DateType.h"
#include <vector>
#include <iostream>

DateType::DateType() : month(1), day(1), year(1500)
{}
DateType::DateType(int dMonth, int dDay, int dYear)
{
    SetMonth(dMonth);
    SetDay(dDay);
    SetYear(dYear);
}
void DateType::SetMonth(int dMonth)
{
    if (dMonth > 0 && dMonth < 13)
        month = dMonth;
    else
        month = 1;

}
void DateType::SetDay(int dDay)
{
    if (dDay > 0 && dDay <= 28)
        day = dDay;
    else
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if (dDay <= 31)
                day = dDay;
            else
                day = 1;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if (dDay <= 30)
                day = dDay;
            else
                day = 1;
            break;
        }
        case 2:
        {
            if (dDay = 29)
                day = dDay;
            else
                day = 1;
        }
        }
    }
}
void DateType::SetYear(int dYear)
{
    if (dYear >= 1500)
        year = dYear;
    else
        year = 1500;
}
int DateType::ReturnMonth() const
{
    return month;
}
int DateType::ReturnDay() const
{
    return day;
}
int DateType::ReturnYear() const
{
    return year;
}
bool DateType::IsleapYear() const
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    else if (year % 400 == 0)
        return true;
    else
        return false;
}
int DateType::NumOfDaysInMonth()
{
    int numberOfDays;
    std::vector<int> daysInMonth{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (IsleapYear())
        daysInMonth.at(1) = 29;
    for (unsigned i{ 0 }; i < daysInMonth.size(); ++i)
    {
        unsigned currentMonth = i + 1;
        if (month == currentMonth)
        {
            numberOfDays = daysInMonth.at(i);
            break;
        }
    }
    return numberOfDays;
}
int DateType::NumOfDaysPassed()
{
    std::vector<int> daysInMonth{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (IsleapYear())
        daysInMonth.at(1) = 29;
    auto daysPassed{ 0 };
    for (auto i{ 0u }; i < daysInMonth.size(); ++i)
    {
        if (month == i + 1)
        {
            auto counter{ 0 };
            while (counter < day - 1)
            {
                ++counter;
            }
            daysPassed += counter;
            break;
        }
        else
            daysPassed += daysInMonth.at(i);
    }
    return daysPassed;
}
int DateType::NumOfDaysRemaining()
{
    auto daysRemaining{ 0 };
    int daysPassed = NumOfDaysPassed() + 1;
    if (IsleapYear())
        daysRemaining = 366 - daysPassed;
    else
        daysRemaining = 365 - daysPassed;
    return daysRemaining;
}
std::ostream& operator<< (std::ostream& streamObject, const DateType& right)
{
    streamObject << right.month << ":" << right.day << ":" << right.year << '\n';
    return streamObject;
}