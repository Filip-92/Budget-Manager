#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    system("cls");
    char choice;
    string date = "";
    string incomeName = "";
    string incomeValue ="";
    Income income;
    cout << "Is the income from (1) today or from (2) some specific day? " << endl;
    cout << endl << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();
    if (choice == '1')
    {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    income.setYear(systemTime.wYear);
    income.setMonth(systemTime.wMonth);
    income.setDay(systemTime.wDay);
    }
    else if (choice == '2')
    {
        do
        {
            do
            {
                cout << "Enter Income date in format 'yyyy-mm-dd': " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkFormatCorrectness(date));
            income = setDateToVectorIncome(date);
        }
        while(!checkTheTimeInterval(income.getYear(), income.getMonth(), income.getDay()));


    }
    cout << "What is the item of the income? " << endl;
    incomeName = auxiliaryMethods.loadLine();
    income.setIncomeName(incomeName);

    cout << "Input the Income amount: " << endl;
    incomeValue = auxiliaryMethods.loadLine();
    incomeValue = replaceCommaWithPeriod(incomeValue);
    income.setIncomeValue(atof(incomeValue.c_str()));

    income.setIncomeIndex(assignIncomeIndex());
    fileWithIncome.addIncomeToFile(income);
    incomes.push_back(income);
    cout << "Income added successfully" << endl;
    Sleep(1500);
}

Income TransactionManager::setDateToVectorIncome (string date)
{
    date += '-';
    int length = date.length();
    Income income;
    string integer;
    int numberSupervention = 1;
    for (int i = 0; i < length; i++)
    {
        if (date[i] != '-')
        {
            integer += date[i];
        }
        else
        {
            switch (numberSupervention)
            {
            case 1:
                income.setYear(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 2:
                income.setMonth(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 3:
                income.setDay(auxiliaryMethods.conversionStringToInt(integer));
                break;
            }
            integer = "";
            numberSupervention++;
        }
    }
    return income;
}

bool TransactionManager::checkFormatCorrectness (string date)
{
    bool isCorrect = true;
    if (date.length() != 10 )
        isCorrect = false;

    for (int i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                isCorrect = false;
        }
        else
        {
            if (!isdigit(date[i]))
                isCorrect = false;
        }
    }
    if (isCorrect == false)
    {
        cout << "Date format is incorrect." << endl;
        Sleep(1500);
        return false;
    }
    else
        return true;

}


bool TransactionManager::checkTheTimeInterval(int year, int month, int day)
{
    bool isTheInterval = true;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    if(year > systemTime.wYear || year < 2000)
    {
        cout << "The year you have entered is outside of 2000 - (current year) range" << endl;
        isTheInterval = false;
    }
    else if (year == systemTime.wYear)
    {
        if (month > systemTime.wMonth)
        {
            isTheInterval = false;
            cout << "Date you have entered exceeds today't date" << endl;
        }
        else if (month == systemTime.wMonth)
        {
            if (day > systemTime.wDay)
            {
                isTheInterval = false;
                cout << "Date you have entered exceeds today't date" << endl;
            }
            else if (day == systemTime.wDay)
            {
                cout << "You have entered today's date" << endl;
                Sleep(1500);
            }
        }
    }
    return isTheInterval;
}

void TransactionManager::addExpense()
{
    system("cls");
    char choice;
    string date = "";
    string expenseName = "";
    string expenseValue ="";
    Expense expense;
    cout << "Is the expense from (1) today or from (2) some specific day? " << endl;
    cout << endl << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();
    if (choice == '1')
    {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    expense.setYear(systemTime.wYear);
    expense.setMonth(systemTime.wMonth);
    expense.setDay(systemTime.wDay);
    }
    else if (choice == '2')
    {
        do
        {
            do
            {
                cout << "Enter Expense date in format 'yyyy-mm-dd': " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkFormatCorrectness(date));
            expense = setDateToVectorExpense(date);
        }
        while(!checkTheTimeInterval(expense.getYear(), expense.getMonth(), expense.getDay() ));


    }
    cout << "What is the item of the income? " << endl;
    expenseName = auxiliaryMethods.loadLine();
    expense.setExpenseName(expenseName);

    cout << "Input the Expense amount: " << endl;
    expenseValue = auxiliaryMethods.loadLine();
    expenseValue = replaceCommaWithPeriod(expenseValue);
    expense.setExpenseValue(atof(expenseValue.c_str()));

    expense.setExpenseIndex(assignExpenseIndex());
    fileWithExpense.addExpenseToFile(expense);
    expenses.push_back(expense);
    cout << "Expense added successfully" << endl;
    Sleep(1500);
}

Expense TransactionManager::setDateToVectorExpense (string date)
{
    date += '-';
    int length = date.length();
    Expense expense;
    string integer;
    int numberSupervention = 1;
    for (int i = 0; i < length; i++)
    {
        if (date[i] != '-')
        {
            integer += date[i];
        }
        else
        {
            switch (numberSupervention)
            {
            case 1:
                expense.setYear(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 2:
                expense.setMonth(auxiliaryMethods.conversionStringToInt(integer));
                break;
            case 3:
                expense.setDay(auxiliaryMethods.conversionStringToInt(integer));
                break;
            }
            integer = "";
            numberSupervention++;
        }
    }
    return expense;
}

void TransactionManager::showBalanceSheetForTheCurrentMonth ()
{
    system("cls");
    cout << "------------ Current Month Balance ------------" << endl;
    cout << "Incomes: " << endl << endl;
    showIncomeForTheSpecificMonth (0);
    cout << "-------------------------------------------------------" << endl;
    cout << "Expenses: " << endl << endl;
    showExpenseForTheSpecificMonth (0);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Sum of incomes: +" << incomeSum << endl;
    cout << "Sum of expenses: -" << expenseSum << endl;
    cout << "Balance for the current month is: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;

}

void TransactionManager::showIncomeForTheSpecificMonth (int howManyMonthsBack)
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getYear() == systemTime.wYear)
        {
            if (incomes[i].getMonth () == (systemTime.wMonth - howManyMonthsBack))
            {
                sort(incomes.begin(), incomes.end(), [](Income& lhs, Income& rhs)
                {
                    return lhs.getDay() < rhs.getDay();
                });
                cout << "Transaction name: " << incomes[i].getIncomeName() << endl;
                cout << "Transaction date: " << incomes[i].getYear () << "-" << incomes[i].getMonth () << "-" << incomes[i].getDay () << endl;
                cout << "Transaction amount: " << "+ " << incomes[i].getIncomeValue() << endl << endl;
                incomeSum += incomes[i].getIncomeValue();
            }
        }
    }
}

void TransactionManager::showExpenseForTheSpecificMonth (int howManyMonthsBack)
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getYear() == systemTime.wYear)
        {
            if (expenses[i].getMonth () == (systemTime.wMonth - howManyMonthsBack))
            {
                sort(expenses.begin(), expenses.end(), [](Expense& lhs, Expense& rhs)
                {
                    return lhs.getDay() < rhs.getDay();
                });
                cout << "Transaction name: " << expenses[i].getExpenseName() << endl;
                cout << "Transaction date: " << expenses[i].getYear () << "-" << expenses[i].getMonth () << "-" << expenses[i].getDay () << endl;
                cout << "Transaction value: " << "- " << expenses[i].getExpenseValue() << endl << endl;
                expenseSum += expenses[i].getExpenseValue();
            }
        }
    }
}

void TransactionManager::showBalanceSheetForThePreviousMonth ()
{
    system("cls");
    cout << "--------------- Previous month balance ----------------" << endl;
    cout << "Incomes: " << endl << endl;
    showIncomeForTheSpecificMonth (1);
    cout << "-------------------------------------------------------" << endl;
    cout << "Expenses: " << endl << endl;
    showExpenseForTheSpecificMonth (1);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Sum of incomes: +" << incomeSum << endl;
    cout << "Sum of expenses: -" << expenseSum << endl;
    cout << "Balance for the previous month is: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;
}

void TransactionManager::showBalanceSheetForTheSelectedPeriod ()
{
    system("cls");
    Date firstDate;
    string date = "";
    Date secondDate;
    do
    {
        do
        {
            cout << "Enter starting date of the desired period in format 'rrrr-mm-dd': " << endl;
            date = auxiliaryMethods.loadLine();
        }
        while (!checkFormatCorrectness(date));
        firstDate = setDateToVectorIncome(date);
    }
    while(!checkTheTimeInterval(firstDate.getYear(), firstDate.getMonth(), firstDate.getDay()));

    do
    {
        do
        {
            cout << "Enter finishing date of the desired period in format 'rrrr-mm-dd': " << endl;
            date = auxiliaryMethods.loadLine();
        }
        while (!checkFormatCorrectness(date));
        secondDate = setDateToVectorIncome(date);
    }
    while(!checkTheTimeInterval(secondDate.getYear(), secondDate.getMonth(), secondDate.getDay()));
    cout << "----------- Balance for the specific period -----------" << endl;
    cout << "Incomes: " << endl << endl;
    showIncomeForTheSelectedPeriod(firstDate, secondDate);
    cout << "-------------------------------------------------------" << endl;
    cout << "Expenses: " << endl << endl;
    showExpenseForTheSelectedPeriod (firstDate, secondDate);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Sum of incomes: +" << incomeSum << endl;
    cout << "Sum of expenses: -" << expenseSum << endl;
    cout << "Balance for the selected period is: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;
}

void TransactionManager::showIncomeForTheSelectedPeriod (Date firstDate, Date secondDate)
{
    system("cls");
    bool isItInTheRange;
    for (int i = 0; i < incomes.size(); i++)
    {
        isItInTheRange = false;
        if (incomes[i].getYear() >= firstDate.getYear() && incomes[i].getYear() <= secondDate.getYear())
        {
            if (incomes[i].getYear() == firstDate.getYear() || incomes[i].getYear() == secondDate.getYear())
            {
                if(incomes[i].getMonth() >= firstDate.getMonth() && incomes[i].getMonth() <= secondDate.getMonth())
                {
                    if (incomes[i].getMonth() == firstDate.getMonth() || incomes[i].getMonth() == secondDate.getMonth())
                    {
                        if(incomes[i].getDay() <= secondDate.getDay())
                        {
                           isItInTheRange = true;
                        }
                    }
                    else
                    {
                        isItInTheRange = true;
                    }
                }
            }
            else
            {
                isItInTheRange = true;
            }
        }
        if (isItInTheRange == true)
        {
            cout << "Transaction name: " << incomes[i].getIncomeName() << endl;
            cout << "Transaction date: " << incomes[i].getYear () << "-" << incomes[i].getMonth () << "-" << incomes[i].getDay () << endl;
            cout << "Transaction value: " << "+ " << incomes[i].getIncomeValue() << endl << endl;
            incomeSum += incomes[i].getIncomeValue();
        }
    }
    cout << "wyszedlem" << endl;
}

void TransactionManager::showExpenseForTheSelectedPeriod (Date firstDate, Date secondDate)
{
    system("cls");
    bool isItInTheRange;
    for (int i = 0; i < expenses.size(); i++)
    {
        isItInTheRange = false;
        if (expenses[i].getYear() >= firstDate.getYear() && expenses[i].getYear() <= secondDate.getYear())
        {
            if (expenses[i].getYear() == firstDate.getYear() || expenses[i].getYear() == secondDate.getYear())
            {
                if(expenses[i].getMonth() >= firstDate.getMonth() && expenses[i].getMonth() <= secondDate.getMonth())
                {
                    if (expenses[i].getMonth() == firstDate.getMonth() || expenses[i].getMonth() == secondDate.getMonth())
                    {
                        if(expenses[i].getDay() <= secondDate.getDay())
                        {
                            isItInTheRange = true;
                        }
                    }
                    else
                    {
                        isItInTheRange = true;
                    }
                }
            }
            else
            {
                isItInTheRange = true;
            }
        }
        if (isItInTheRange == true)
        {
            cout << "Transaction name: " << expenses[i].getExpenseName() << endl;
            cout << "Transaction date: " << expenses[i].getYear () << "-" << expenses[i].getMonth () << "-" << expenses[i].getDay () << endl;
            cout << "Transaction value: " << "+ " << expenses[i].getExpenseValue() << endl << endl;
            expenseSum += expenses[i].getExpenseValue();
        }
    }
}

string TransactionManager::replaceCommaWithPeriod (string value)
{
    string newValue;
    for (int i = 0; i < value.length(); i++)
    {
        if (value[i] == ',')
        {
            newValue += '.';
        }
        else
        {
            newValue += value[i];
        }
    }
    return newValue;
}

int TransactionManager::assignIncomeIndex ()
{
    int index = 0;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getIncomeIndex() > index)
        {
            index = incomes[i].getIncomeIndex();
        }
    }
    return index + 1;
}

int TransactionManager::assignExpenseIndex()
{
    int index = 0;
    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getExpenseIndex() > index)
        {
            index = expenses[i].getExpenseIndex();
        }
    }
    return index + 1;
}
