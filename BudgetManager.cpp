#include "BudgetManager.h"

void BudgetManager::userRegistration()
{
    userManager.userRegistration();
}
void BudgetManager::writeAllUsers()
{
    userManager.displayAllUsers();
}
void BudgetManager::SignInUser()
{
    userManager.userLogIn();
    if (isTheUserSignIn() == true)
    {
        transactionManager = new TransactionManager (FILE_WITH_INCOME_NAME, FILE_WITH_EXPENSE_NAME, userManager.getLoggedInUser());
        loggedInUser = userManager.getLoggedInUser();
    }
}
void BudgetManager::signOutUser ()
{
    userManager.signOutUser();
}
bool BudgetManager::isTheUserSignIn()
{
    userManager.isTheUserSignIn();
}
char BudgetManager::chooseOptionAtMeinMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log in" << endl;
    cout << "9. End task" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}
char BudgetManager::chooseOptionAtOperationMenu()
{
    char choice;

    system("cls");
    cout << "User name: " << loggedInUser.getName() << endl;
    cout << "User surname: " << loggedInUser.getSurname() << endl;
    cout << "---------------------------" << endl;
    cout << " >>>     USER MENU      <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Specific period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}
void BudgetManager::addIncome()
{
    transactionManager -> addIncome();
}
void BudgetManager::addExpense()
{
    transactionManager -> addExpense();
}
void BudgetManager::showBalanceSheetForTheCurrentMonth ()
{
    transactionManager -> showBalanceSheetForTheCurrentMonth();
}
void BudgetManager::showBalanceSheetForThePreviousMonth ()
{
    transactionManager -> showBalanceSheetForThePreviousMonth ();
}
void BudgetManager::showBalanceSheetForTheSelectedPeriod ()
{
    transactionManager -> showBalanceSheetForTheSelectedPeriod();
}
void BudgetManager::changePasswordOfLoggedUser ()
{
   userManager.changePasswordOfLoggedUser();
}
