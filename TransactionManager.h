#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Income.h"
#include <windows.h>
#include "FileWithIncome.h"
#include "Expense.h"
#include "FileWithExpense.h"
#include "Date.h"
#include <stdlib.h>
#include <algorithm>

#include <vector>

using namespace std;

class TransactionManager
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;
    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;
    vector <Income> incomes;
    vector <Expense> expenses;
    float incomeSum;
    float expenseSum;
    float sum;


    bool checkFormatCorrectness (string);
    bool checkTheTimeInterval(int, int, int);
    void showIncomeForTheSpecificMonth (int);
    void showExpenseForTheSpecificMonth (int);

    Income setDateToVectorIncome (string date);
    Expense setDateToVectorExpense (string date);
    void showIncomeForTheSelectedPeriod (Date , Date);
    void showExpenseForTheSelectedPeriod (Date , Date);

    string replaceCommaWithPeriod (string value);
    int assignIncomeIndex ();
    int assignExpenseIndex();

public:
    TransactionManager (string nameFileWithIncome, string nameFileWithExpense, User LOGGEDINUSER):
        fileWithIncome (nameFileWithIncome, LOGGEDINUSER), loggedInUser(LOGGEDINUSER), fileWithExpense(nameFileWithExpense, LOGGEDINUSER)
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
    void getBalance(int startDate, int endDate);
    void getBalanceCurrentMonth();
    void getBalanceLastMonth();
    void getBalanceCustom();
    void printExpenses(vector<Expense> transactions);
    void printIncomes(vector<Income> transactions);
};
#endif
