#include "DayType.h"
#include <iostream>
#include <vector>

DayType::DayType() : dayOfWeek("mon")
{}
void DayType::SetDay(std::string day)
{
    std::vector<std::string> days{ "mon","tue","wed","thu","fri","sat","sun" };
    for (auto elem : days)
    {
        if (elem == day.substr(0, 3))
        {
            dayOfWeek = elem;
            break;
        }
    }
}
std::string DayType::ReturnDay() const
{
    return dayOfWeek;
}
std::string DayType::ReturnNextDay()
{
    std::vector<std::string> days{ "mon","tue","wed","thu","fri","sat","sun" };
    auto counter{ 0 };
    for (auto elem : days)
    {
        if (elem == dayOfWeek)
            break;
        ++counter;
    }
    if (counter == 6)
        counter = -1;
    return days.at(counter + 1);
}
std::string DayType::ReturnPreviousDay()
{
    std::vector<std::string> days{ "mon","tue","wed","thu","fri","sat","sun" };
    auto counter{ 0 };
    for (auto elem : days)
    {
        if (elem == dayOfWeek)
            break;
        ++counter;
    }
    if (counter == 0)
        counter = 7;
    return days.at(counter - 1);
}
std::string DayType::NextNumOfDays(int num)
{
    std::vector<std::string> days{ "mon","tue","wed","thu","fri","sat","sun" };
    auto counter{ 0 };
    for (auto elem : days)
    {
        if (elem == dayOfWeek)
            break;
        ++counter;
    }
    for (auto i{ 0 }; i < num; ++i)
    {
        ++counter;
        if (counter > 6)
            counter = 0;
    }
    return days.at(counter);
}
std::ostream& operator<< (std::ostream& ostreamObj, const DayType& right)
{
    ostreamObj << right.dayOfWeek;
    return ostreamObj;
}
