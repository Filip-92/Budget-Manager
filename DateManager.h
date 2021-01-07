#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

class DateManager
{
    vector <int> normalYear{31,28,31,30,31,30,31,31,30,31,30,31};
    vector <int> leapYear{31,29,31,30,31,30,31,31,30,31,30,31};

public:
	DateManager();

    string getCurrentDate();
    int getDays(string date);
    int getNumberOfDays(int month, int year);
    bool isLeap(int year);
    bool checkDate(string date);
    int dateToInt(string date);
    int getTimeRange(string dateBegin, string dateEnd);
    int getYear(string date);
    int getMonth(string date);
    int getDay(string date);
};

#endif
