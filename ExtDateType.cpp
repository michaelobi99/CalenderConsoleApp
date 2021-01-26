#include "ExtDateType.h"
#include <vector>
#include <vector>
#include <string>

ExtDateType::ExtDateType() : DateType()
{
    monthInString = " ";
}
ExtDateType::ExtDateType(int month, int day, int year) : DateType(month, day, year)
{}
std::string ExtDateType::SetMonthInString(int month)
{
    std::vector<std::string> mth{ "january","feburary","march","april",
                            "may","june","july","august","september",
                            "october","november","december" };
    auto counter{ 1 };
    for (auto elem : mth)
    {
        if (counter == month)
        {
            monthInString = elem;
            break;
        }
        ++counter;
    }
    return monthInString;
}
void ExtDateType::SetDate(int month, int day, int year)
{
    SetMonth(month);
    SetDay(day);
    SetYear(year);
    SetMonthInString(month);
}
void ExtDateType::PrintMonthYear()
{
    std::cout << SetMonthInString(ReturnMonth()) << " " << std::to_string(ReturnYear()) << '\n';
}
