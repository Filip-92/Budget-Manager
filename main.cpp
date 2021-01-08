#include <iostream>
#include <iomanip>
#include <ctime>
#include "Markup.h"
#include "BudgetManager.h"

using namespace std;

int main()
{
    BudgetManager budgetManager("Users.xml", "Income.xml", "Expense.xml");

    char choice;

    while (true)
    {
        if (budgetManager.isUserLoggedIn() == false)
        {
            choice = budgetManager.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                system("cls");
                budgetManager.userRegistration();
                break;
            case '2':
                system("cls");
                budgetManager.userLoggingIn();
                break;
            case '3':
                system("cls");
                budgetManager.displayAllUsers();
                break;
            case '9':
                exit(0);
                   break;
            default:
                cout << endl << "No such option in Main Menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budgetManager.selectOptionFromUserMenu();

            switch (choice)
            {
                {
                case '1':
                    system("cls");
                    budgetManager.addIncome();
                    break;
                case '2':
                    system("cls");
                    budgetManager.addExpense();
                    break;
                case '3':
                    system("cls");
                    //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                    break;
                case '4':
                    system("cls");
                    //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                    break;
                case '5':
                    system("cls");
                    //ksiazkaAdresowa.edytujAdresata();
                    break;
                case '6':
                    system("cls");
                    budgetManager.changePasswordOfLoggedUser();
                    break;
                case '7':
                    system("cls");
                    budgetManager.userLogout();
                    break;
            default:
                cout << endl << "No such option in User Menu." << endl << endl;
                system("pause");
                break;
                }
            }
    }
}
return 0;
}
