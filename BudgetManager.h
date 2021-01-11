#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "TransactionManager.h"
#include "User.h"

using namespace std;

class BudgetManager
{
    UserManager userManager;
    User loggedInUser;
    TransactionManager *transactionManager;
    AuxiliaryMethods auxiliaryMethods;
    int IdSignInUser;
    const string FILE_WITH_INCOME_NAME;
    const string FILE_WITH_EXPENSE_NAME;

public:
    BudgetManager (string fileWithUsersName, string fileWithIncomeName, string fileWithExpenseName):
        userManager(fileWithUsersName), FILE_WITH_INCOME_NAME(fileWithIncomeName), FILE_WITH_EXPENSE_NAME(fileWithExpenseName)
    {

    };
    void userRegistration();
    void writeAllUsers();
    void SignInUser();
    void signOutUser ();
    bool isTheUserSignIn();
    char chooseOptionAtMeinMenu();
    char chooseOptionAtOperationMenu();
    void addIncome();
    void addExpense();
    void showBalanceSheetForTheCurrentMonth ();
    void showBalanceSheetForThePreviousMonth ();
    void showBalanceSheetForTheSelectedPeriod ();
    void changePasswordOfLoggedUser ();
};
#endif
