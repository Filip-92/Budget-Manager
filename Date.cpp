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
        cout << "Podales miesiac: " << month << ", nie ma takiego miesiaca, podaj inny: " << endl;
        return false;
    }
    return true;
}

bool Date::conditionalDay (int day)
{
    int maxDay;
    if (month == 2)
    {
        if(isLeap(year) == true)
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
        cout << "Podales date:" <<year<<"-"<<month<<"-"<<day<<", ten miesiac nie posaida takiego dnia, podaj inny dzien: " << endl;
        return false;
    }
    return true;
}

string Date::getCurrentDate()
{
    time_t timeNow;
    tm *datestr;
    time( & timeNow );
    string date,yr,mn,d;
    datestr=localtime(&timeNow);
    yr=to_string(datestr->tm_year+1900);
    if(datestr->tm_mon>8)
        mn=to_string(datestr->tm_mon+1);
    else
        mn="0"+to_string(datestr->tm_mon+1);
    if(datestr->tm_mday>8)
        d=to_string(datestr->tm_mday);
    else
        d="0"+to_string(datestr->tm_mday);
    date=yr+"-"+mn+"-"+d;
    return date;
}

int Date::getDays(string date)
{
    int year,month,day,days{0};
    year=stoi(date.substr(0,4));
    month=stoi(date.substr(5,6));
    day=stoi(date.substr(8,9));

   for(int y=2000;y<year;y++)
    {
       if(isLeap(y))
       days+=366;
       else
       days+=365;
    }
   for(int m=1;m<month;m++){
       if(isLeap(year))
           days+=leapYear[m-1];
       else {
           days+=normalYear[m-1];
       }
   }
   days+=day;

    return days;
}

int Date::getNumberOfDays(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else if (month == 02)
    {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapYear == 0)
                return 28;
        else
                return 29;
    }
    else
    return 31;
}

bool Date::isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

bool Date::checkDate(string date)
{
    if(date.length()!=10)
        return false;
    else
    {
        string currentDate=getCurrentDate();
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,6));
        int day=stoi(date.substr(7,8));
        if(date.length()!=10)
            return false;
        if(year>=2000 && year<=stoi(currentDate.substr(0,4)) && month >=1 && month <= 12 && day >=1 && day <= getNumberOfDays(month,year))
            return true;
        else
            cout << "Incorrect date submitted, please try again.";
        return false;
    }
}
