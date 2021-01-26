#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include "CalenderType.h"
using namespace std::chrono;
void showMenu()
{
    std::cout << "Enter\n";
    std::cout << "1> to view the entire calendar of a particular year\n";
    std::cout << "2> to view the calendar of a particular month\n";
}
void getInput(std::uint32_t& input)
{
    while (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "******ERROR!! enter again: ";
    }
}
void printCalendar(std::uint32_t year)
{
    auto error{ true };
    while (error)
    {
        try {
            for (auto i{ 1 }; i <= 12; ++i)
            {
                CalendarType calendar;
                calendar.SetMonth(i);
                calendar.SetYear(year);
                calendar.PrintCalendarForMonth();
                std::cout << "\n\n";
            }
            error = false;
        }
        catch (CalendarType::YearError exp)
        {
            std::cout << "***ERROR: " << exp.GetYear() << " is an invalid year.\n";
            std::cout << "Year: ";
            while (!(std::cin >> year))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "******ERROR!! Year: ";
            }
            error = true;
        }
    }
}
void printCalendar(std::uint32_t month, std::uint32_t year, CalendarType& calendar)
{
    auto error{ true };
    while (error)
    {
        try
        {
            calendar.SetMonth(month);
            calendar.SetYear(year);
            error = false;
        }
        catch (CalendarType::YearError exp)
        {
            std::cout << "***ERROR: " << exp.GetYear() << " is an invalid year.\n";
            std::cout << "Year: ";
            while (!(std::cin >> year))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "******ERROR!! Year: ";
            }
        }
        catch (CalendarType::MonthError exp)
        {
            std::cout << "***Error: " << exp.GetMonth() << " is an invalid month.\n";
            std::cout << "Month: ";
            while (!(std::cin >> month))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "******ERROR!! Month: ";
            }
        }
    }
    calendar.PrintCalendarForMonth();
}
void processInput(std::uint32_t input)
{
    switch (input)
    {
    case 1:
    {
        std::uint32_t year{ 0 };
        std::cout << "Enter the year: ";
        getInput(year);
        printCalendar(year);
        break;
    }
    case 2:
    {
        CalendarType calendar2;
        std::uint32_t month{ 0 }, year{ 0 };
        std::cout << "\nEnter the month and year(i.e in numerical form)\n";
        std::cout << "*******if you enter an invalid date the program will output a default value*******\nmonth: ";
        getInput(month);
        std::cout << "year: ";
        getInput(year);
        printCalendar(month, year, calendar2);
    }
    }
}


int main()
{
    auto still{ true };
    while (still)
    {
        showMenu();
        auto input{ 0 };
        auto error{ true };
        while (error)
        {
            while (!(std::cin >> input))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error!,enter again: ";
            }
            if (input < 1 || input > 2)
            {
                std::cout << "\n****Error!! operation not recognized.******\n";
                std::cout << "Enter again: ";
                continue;
            }
            else
                error = false;
        }
        processInput(input);
        std::cout << "\nDo you want to continue?\ny> yes\nn> no\n";
        auto ch{ ' ' };
        while (ch != 'y' && ch != 'n')
        {
            if (!(std::cin >> ch))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "invalid input! Enter again: ";
                continue;
            }
        }
        if (ch == 'n')
            still = false;
    }
    std::cout << "*****The program will exit in two seconds,GOODBYE!********\n";
    std::this_thread::sleep_for(2s);
    return 0;
}

