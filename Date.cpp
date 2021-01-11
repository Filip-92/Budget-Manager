#include "Date.h"

void Date::setYear (int year)
{
    this -> year = year;
}
void Date::setMonth (int month)
{
    while (!conditionalMonth(month))
    {
        month = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> month = month;
}
void Date::setDay (int day)
{
    while (!conditionalDay(day))
    {
        day = auxiliaryMethods.conversionStringToInt(auxiliaryMethods.loadLine());
    }
    this -> day = day;
}
int Date::getYear ()
{
    return year;
}
int Date::getMonth ()
{
    return month;
}
int Date::getDay ()
{
    return day;
}
bool Date::conditionalMonth (int month)
{
    if(month > 12 || month < 0)
    {
        cout << "You entered month: " << month << ", no such month exists, please enter another one: " << endl;
        return false;
    }
    return true;
}
bool Date::conditionalDay (int day)
{
    int maxDay;
    if (month == 2)
    {
        if(isLeapYear() == true)
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        maxDay = 31;
    else
        maxDay = 30;
    if(day > maxDay || day < 0)
    {
        cout << "You entered date:" <<year<<"-"<<month<<"-"<<day<<", this month does not have such day, please enter another day: " << endl;
        return false;
    }
    return true;
}
bool Date::isLeapYear ()
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}


