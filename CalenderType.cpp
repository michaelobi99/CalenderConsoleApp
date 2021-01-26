#include "CalenderType.h"
#include <iostream>
#include <iomanip>

void CalendarType::FirstDayOfTheMonth()
{
    auto mth = date.ReturnMonth();
    auto yr = date.ReturnYear();
    auto numberOfDays{ 0 };
    numberOfDays += 365;
    auto referenceYear = 1500;
    ++referenceYear;
    while (referenceYear < yr)
    {
        if ((referenceYear % 4 == 0 && referenceYear % 100 != 0) || (referenceYear % 400 == 0))
            numberOfDays += 366;
        else
            numberOfDays += 365;
        ++referenceYear;
    }
    std::vector<int> month{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
        month.at(1) = 29;
    auto counter{ 1 };
    while (counter < mth)
    {
        numberOfDays += month.at(counter - 1);
        ++counter;
    }
    std::vector<std::string> days{ "mon","tue","wed","thu","fri","sat","sun" };
    std::string firstDay{ "" };
    firstDay = day.NextNumOfDays(numberOfDays);
    day.SetDay(firstDay);
}
CalendarType::CalendarType()
{
    ExtDateType();
    DayType();
}
void CalendarType::SetMonth(int month)
{
    if (month >= 1 && month <= 12)
        date.SetMonth(month);
    else
        throw MonthError(month);
    date.SetDay(1);
}
void CalendarType::SetYear(int year)
{
    if (year >= 1500)
        date.SetYear(year);
    else
        throw YearError(year);
    FirstDayOfTheMonth();
}
int CalendarType::ReturnMonth() const
{
    return date.ReturnMonth();
}
int CalendarType::ReturnYear() const
{
    return date.ReturnYear();
}
void CalendarType::PrintCalendarForMonth()
{
    std::cout << "                ";
    date.PrintMonthYear();
    std::vector<std::string> days{ "sun","mon","tue","wed","thu","fri","sat" };
    for (auto elem : days)
        std::cout << std::right << std::setw(6) << elem;
    std::cout << '\n';
    std::vector<int> month{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (date.IsleapYear())
        month.at(1) = 29;
    auto valOfMonth = date.ReturnMonth();
    auto valOfDay = std::string{ day.ReturnDay() };
    auto noOfDays{ 0 };
    for (auto counter{ 1u }; counter <= month.size(); ++counter)
    {
        if (counter == valOfMonth)
        {
            noOfDays = month.at(counter - 1);
            break;
        }
    }
    if (valOfDay == "sun")
    {
        auto counter{ 1 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else if (valOfDay == "mon")
    {
        auto counter{ 2 };
        std::cout << std::setw(6) << " ";
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else if (valOfDay == "tue")
    {
        std::cout << std::setw(6) << " " << std::setw(6) << " ";
        auto counter{ 3 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else if (valOfDay == "wed")
    {
        std::cout << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " ";
        auto counter{ 4 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else if (valOfDay == "thu")
    {
        std::cout << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " ";
        auto counter{ 5 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else if (valOfDay == "fri")
    {
        std::cout << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " ";
        auto counter{ 6 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
    else
    {
        std::cout << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " " << std::setw(6) << " ";
        auto counter{ 7 };
        for (auto i{ 1 }; i <= noOfDays; ++i)
        {
            std::cout << std::right << std::setw(6) << i;
            if (counter == 7)
            {
                counter = 0;
                std::cout << '\n';
            }
            ++counter;
        }
    }
}
