#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include "Date.h"

using namespace std;

class Income : public Date
{
    string incomeName;
    float incomeValue;
    int incomeIndex;

public:

    void setIncomeName(string);
    void setIncomeValue (float);
    void setIncomeIndex (int);

    string getIncomeName ();
    float getIncomeValue ();
    int getIncomeIndex ();
};
#endif
