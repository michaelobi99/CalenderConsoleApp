#pragma once
#include <string>

class DayType
{
public:
    DayType();
    void SetDay(std::string);
    std::string ReturnDay() const;
    std::string ReturnNextDay();
    std::string ReturnPreviousDay();
    std::string NextNumOfDays(int);
    friend std::ostream& operator<< (std::ostream&, const DayType&);
private:
    std::string dayOfWeek;
};

