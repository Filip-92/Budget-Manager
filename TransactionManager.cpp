#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    Income income;
    int selectDate;
    string customDate, item;
    char choice;
    cout << "Select an Option:" << endl;
    cout << "Do you want to input a transaction with (1) today's date or (2) custom date?" << endl;
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

        switch (choice)
        {
        case '1':
            income.date = dateManager->getCurrentDate();
            income.dayNr = dateManager->getDays(dateManager->getCurrentDate());
            break;
        case '2':
            do
            {
            cout << "Input custom date in format 'yyyy-mm-dd': ";
            cin >> customDate;
            break;
            }
            while(dateManager->checkDate(customDate)!=1);
            income.date = customDate;
            income.dayNr = dateManager->getDays(customDate);
        }
    cout << "Please enter the item of the transaction: ";
    cin >> item;
    cout << "Enter amount: ";
    string amount;
    cin >> amount;
    income.amount = AuxiliaryMethods::fixDouble(amount);
    income.userId = LOGGED_IN_USER_ID;
    income.transactionId = incomes.size();

    incomes.push_back(income);
    fileWithIncomes->saveIncomesToFile(incomes);
}
