#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

class TransactionManager
{
	const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    //vector <Expense> expenses;
    FileWithIncomes* fileWithIncomes;
    //FileWithExpenses* fileWithExpenses;
    DateManager* dateManager;

public:
TransactionManager(string incomesFile, string expensesFile, int loggedInUserId)
/*: fileWithExpenses(expensesFile), fileWithIncomes(incomesFile), LOGGED_IN_USER_ID(loggedInUserId)
{
    incomes=fileWithIncomes.loadIncomesFromTheFile();
    //expenses=fileWithIncomes.loadIncomesFromTheFile();
};*/

    void loadIncomesFromTheFile();
    void loadExpensesFromTheFile();
    void addIncome();
    void addExpense();
    void displayIncomes();
    void displayExpenses();
    void getBalanceForThisMonth();
    void getBalanceForPreviousMonth();
    void getBalanceForSpecificPeriod();
};

#endif
