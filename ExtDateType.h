#pragma once
#include "DateType.h"
#include <string>
#include <iostream>

class ExtDateType : public DateType
{
public:
    ExtDateType();
    ExtDateType(int, int, int);
    void SetDate(int, int, int);
    void PrintMonthYear();
    std::string SetMonthInString(int);
private:
    std::string monthInString;
};

