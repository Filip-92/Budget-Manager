#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Expense : public Date
{

    string expenseName;
    float expenseValue;
    int expenseIndex;

public:
    void setExpenseName(string);
    void setExpenseValue (float);
    void setExpenseIndex (int);

    string getExpenseName ();
    float getExpenseValue ();
    int getExpenseIndex ();
};
#endif
