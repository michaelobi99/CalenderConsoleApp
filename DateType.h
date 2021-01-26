#pragma once


#include <iostream>

class DateType
{
public:
    DateType();
    //default constructor,initializes the variables with a default value if no one is provided.
    //postcondition: month = 1
    //               day = 1
    //               year = 1500;
    DateType(int, int, int);
    //constructor that takes parameters.
    void SetMonth(int);
    //function to assign the value passed by the client code to month
    void SetDay(int);
    //function to assign the value passed by the client code to day
    void SetYear(int);
    //function to assign the value passed by the client code to year
    int ReturnMonth() const;
    //function to return the value of month
    //postcondition: return month
    int ReturnDay() const;
    //function to return the value of day
    //postcondition: return day
    int ReturnYear() const;
    //function to return the value of year
    //postcondition: return year
    bool IsleapYear() const;
    //function to check if a particular year is leap
    //return true or false
    int NumOfDaysInMonth();
    //function to calculate and return the number of days in a particular month
    int NumOfDaysPassed();
    //function to use the current date to calculate and return the number of days that has passed in a particular year
    int NumOfDaysRemaining();
    //function to use the current date to calculate and return the number of days that remain in a particular year
    friend std::ostream& operator<< (std::ostream&, const DateType&);
private:
    int month;
    int day;
    int year;
};

