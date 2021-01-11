#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    AuxiliaryMethods auxiliaryMethods;
    int year;
    int month;
    int day;
    bool conditionalMonth (int);
    bool conditionalDay (int);
    bool isLeapYear ();

    int lastOperationIndex;
public:
    void setYear (int);
    void setMonth (int);
    void setDay (int);

    int getYear ();
    int getMonth ();
    int getDay ();
};
#endif
