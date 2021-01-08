#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    vector <int> normalYear{31,28,31,30,31,30,31,31,30,31,30,31};
    vector <int> leapYear{31,29,31,30,31,30,31,31,30,31,30,31};
    AuxiliaryMethods auxiliaryMethods;
    int year;
    int month;
    int day;
    bool conditionalMonth (int);
    bool conditionalDay (int);

    int lastOperationIndex;
public:
    void setYear (int);
    void setMonth (int);
    void setDay (int);

    int getYear ();
    int getMonth ();
    int getDay ();

    string getCurrentDate();
    int getDays(string date);
    int getNumberOfDays(int month, int year);
    bool isLeap(int year);
    bool checkDate(string date);
};
#endif
