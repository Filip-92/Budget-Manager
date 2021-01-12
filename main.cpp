#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{
 char choice;
    BudgetManager budgetManager ("users.xml","income.xml", "expense.xml");

    while (true)
    {
        if (budgetManager.isTheUserSignIn() == false)
        {
            choice = budgetManager.chooseOptionAtMeinMenu();

            switch (choice)
            {
            case '1':
                budgetManager.userRegistration();
                break;
            case '2':
                budgetManager.SignInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option in the menu available." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budgetManager.chooseOptionAtOperationMenu();

            switch (choice)
            {
            case '1':
                    budgetManager.addIncome();
                break;
            case '2':
                    budgetManager.addExpense();
                break;
            case '3':
                    budgetManager.showBalanceSheetForTheCurrentMonth();
                break;
            case '4':
                    budgetManager.showBalanceSheetForThePreviousMonth();
                break;
            case '5':
                    budgetManager.showBalanceSheetForTheSelectedPeriod();
                break;
            case '6':
                    budgetManager.changePasswordOfLoggedUser();
                break;
            case '7':
                    budgetManager.signOutUser();
                break;
            default:
                cout << endl << "No such option in the menu available." << endl << endl;
                system("pause");
                break;
            }
        }



    }

    return 0;
}

