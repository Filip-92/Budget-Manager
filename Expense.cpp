#include "Expense.h"


void Expense::setExpenseName(string expenseName)
{
    this -> expenseName = expenseName;
}
void Expense::setExpenseValue (float expenseValue)
{
    this -> expenseValue = expenseValue;
}
void Expense::setExpenseIndex (int expenseIndex)
{
    this -> expenseIndex = expenseIndex;
}
string Expense::getExpenseName ()
{
    return expenseName;
}
float Expense::getExpenseValue ()
{
    return expenseValue;
}
int Expense::getExpenseIndex ()
{
    return expenseIndex;
}
