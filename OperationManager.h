#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include <windows.h>
#include "FileWithIncome.h"
#include "Expense.h"
#include "FileWithExpense.h"
#include "Date.h"
#include <stdlib.h>

#include <vector>

using namespace std;

class OperationManager
{
    AuxiliaryMethods auxiliaryMethods;
    Date date;
    User loggedInUser;
    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;
    vector <Income> incomes;
    vector <Expense> expenses;
    float incomeSum;
    float expenseSum;
    float sum;


    bool checkCorrectnessFormat (string);
    bool checkTheTimeInterval(int, int, int);
    void showIncomeForTheSpecifitMonth (int);
    void showExpenseForTheSpecifitMonth (int);

    Income setDateToVectorIncome (string date);
    Expense setDateToVectorExpense (string date);
    void showIncomeForTheSelectedPeriod (Date , Date);
    void showExpenseForTheSelectedPeriod (Date , Date);

    string replaceCommaWithPeriod (string value);
    int assignIncomeIndex ();
    int assignExpenseIndex();

public:
    OperationManager (string nameFileWithIncome, string nameFileWithExpense, User LOGGEDINUSER): fileWithIncome (nameFileWithIncome, LOGGEDINUSER), loggedInUser(LOGGEDINUSER), fileWithExpense(nameFileWithExpense, LOGGEDINUSER)
    {
        incomes = fileWithIncome.loadIncomeFromFile();
        expenses = fileWithExpense.loadExpenseFromFile();
        sum = 0;
        expenseSum = 0;
        incomeSum = 0;

    };
    void addIncome();
    void addExpense();
    void showBalanceSheetForTheCurrentMonth ();
    void showBalanceSheetForThePreviousMonth ();
    void showBalanceSheetForTheSelectedPeriod ();
};
#endif
