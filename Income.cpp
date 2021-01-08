#include "Income.h"

void Income::setIncomeName(string incomeName)
{
    this -> incomeName = incomeName;
}
void Income::setIncomeValue (float incomeValue)
{
    this -> incomeValue = incomeValue;
}
void Income::setIncomeIndex (int incomeIndex)
{
    this ->incomeIndex = incomeIndex;
}


string Income::getIncomeName ()
{
    return incomeName;
}
float Income::getIncomeValue ()
{
    return incomeValue;
}
int Income::getIncomeIndex()
{
    return incomeIndex;
}
