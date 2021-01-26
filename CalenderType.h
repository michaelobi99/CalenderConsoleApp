#pragma once
#include "ExtDateType.h"
#include "DayType.h"
#include <vector>

class CalendarType
{
public:
    class YearError
    {
    private:
        int yr;
    public:
        YearError(int year)
        {
            yr = year;
        }
        int GetYear() const
        {
            return yr;
        }
    };
    class MonthError
    {
    private:
        int mth;
    public:
        MonthError(int month)
        {
            mth = month;
        }
        int GetMonth() const
        {
            return mth;
        }
    };
    CalendarType();
    void FirstDayOfTheMonth();
    void SetMonth(int);
    void SetYear(int);
    int ReturnMonth() const;
    int ReturnYear() const;
    void PrintCalendarForMonth();
private:
    ExtDateType date;
    DayType day;
};

