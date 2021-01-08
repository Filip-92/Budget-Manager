#include "OperationManager.h"

void OperationManager::addIncome()
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
            income.date = date.getCurrentDate();
            income.dayNr = date.getDays(date.getCurrentDate());
            break;
        case '2':
            do
            {
            cout << "Input custom date in format 'yyyy-mm-dd': ";
            cin >> customDate;
            break;
            }
            while(date.checkDate(customDate)!=1);
            income.date = customDate;
            income.dayNr = date.getDays(customDate);
        }
    cout << "Please enter the item of the transaction: ";
    cin >> item;
    cout << "Enter amount: ";
    string amount;
    cin >> amount;
    income.amount = auxiliaryMethods.fixDouble(amount);
    income.userId = loggedInUser.getId();
    income.transactionId = incomes.size();

    incomes.push_back(income);
    fileWithIncome.addIncomeToFile(income);
}

/*void OperationManager::addIncome()
{
    system("cls");
    char character;
    string date = "";
    string incomeName = "";
    string incomeValue ="";
    Income income;
    cout << "Czy przychod dotyczy dzisjszego dnia? potwierdz literka t " << endl;
    character = auxiliaryMethods.loadCharacter();
    if (character == 't')
    {
        SYSTEMTIME systemTime;
        GetSystemTime(&systemTime);
        income.setYear(systemTime.wYear);
        income.setMonth(systemTime.wMonth);
        income.setDay(systemTime.wDay);
    }
    else
    {
        do
        {
            do
            {
                cout << "podaj date przychodu w formacie rrrr-mm-dd: " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkCorrectnessFormat(date));
            income = setDateToVectorIncome(date);
        }
        while(!checkTheTimeInterval(income.getYear(), income.getMonth(), income.getDay()));


    }
    cout << "Czego dotyczy przychod? " << endl;
    incomeName = auxiliaryMethods.loadLine();
    income.setIncomeName(incomeName);

    cout << "Podaj wartosc przychodu: " << endl;
    incomeValue = auxiliaryMethods.loadLine();
    incomeValue = replaceCommaWithPeriod(incomeValue);
    income.setIncomeValue(atof(incomeValue.c_str()));

    income.setIncomeIndex(assignIncomeIndex());
    fileWithIncome.addIncomeToFile(income);
    incomes.push_back(income);
    cout << "Przychod zostal dodany" << endl;
    Sleep(1500);
}*/

Income OperationManager::setDateToVectorIncome (string date)
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
bool OperationManager::checkCorrectnessFormat (string date)
{
    bool isCorrectness = true;
    if (date.length() != 10 )
        isCorrectness = false;

    for (int i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                isCorrectness = false;
        }
        else
        {
            if (!isdigit(date[i]))
                isCorrectness = false;
        }
    }
    if (isCorrectness == false)
    {
        cout << "format daty jest nie poprawny" << endl;
        Sleep(1500);
        return false;
    }
    else
        return true;

}
bool OperationManager::checkTheTimeInterval(int year, int month, int day)
{
    bool isTheInterval = true;
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    if(year > systemTime.wYear || year < 2000)
    {
        cout << "Rok ktory podales nie miesci sie w przedziale 2000 - (obecny rok)" << endl;
        isTheInterval = false;
    }
    else if (year == systemTime.wYear)
    {
        if (month > systemTime.wMonth)
        {
            isTheInterval = false;
            cout << "data ktora podales jest czasowo przekracza dzisiejsza date" << endl;
        }
        else if (month == systemTime.wMonth)
        {
            if (day > systemTime.wDay)
            {
                isTheInterval = false;
                cout << "data ktora podales czasowo przekracza dzisiejsza date" << endl;
            }
            else if (day == systemTime.wDay)
            {
                cout << "podales dzisiejsza date" << endl;
                Sleep(1500);
            }
        }
    }
    return isTheInterval;
}
void OperationManager::addExpense()
{
    system("cls");
    char character;
    string date = "";
    string expenseName = "";
    string expenseValue ="";
    Expense expense;
    cout << "Czy wydatek dotyczy dzisjszego dnia? potwierdz literka t " << endl;
    character = auxiliaryMethods.loadCharacter();
    if (character == 't')
    {
        SYSTEMTIME systemTime;
        GetSystemTime(&systemTime);
        expense.setYear(systemTime.wYear);
        expense.setMonth(systemTime.wMonth);
        expense.setDay(systemTime.wDay);
    }
    else
    {
        do
        {
            do
            {
                cout << "podaj date przychodu w formacie rrrr-mm-dd: " << endl;
                date = auxiliaryMethods.loadLine();
            }
            while (!checkCorrectnessFormat(date));
            expense = setDateToVectorExpense(date);
        }
        while(!checkTheTimeInterval(expense.getYear(), expense.getMonth(), expense.getDay() ));


    }
    cout << "Czego dotyczy wydatek? " << endl;
    expenseName = auxiliaryMethods.loadLine();
    expense.setExpenseName(expenseName);

    cout << "Podaj wartosc wydatek: " << endl;
    expenseValue = auxiliaryMethods.loadLine();
    expenseValue = replaceCommaWithPeriod(expenseValue);
    expense.setExpenseValue(atof(expenseValue.c_str()));

    expense.setExpenseIndex(assignExpenseIndex());
    fileWithExpense.addExpenseToFile(expense);
    expenses.push_back(expense);
    cout << "Wydatek zostal dodany" << endl;
    Sleep(1500);
}
Expense OperationManager::setDateToVectorExpense (string date)
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
void OperationManager::showBalanceSheetForTheCurrentMonth ()
{
    cout << "------------ Bilans z ostatniego miesiaca ------------" << endl;
    cout << "Przychody: " << endl << endl;
    showIncomeForTheSpecifitMonth (0);
    cout << "-------------------------------------------------------" << endl;
    cout << "Wydatki: " << endl << endl;
    showExpenseForTheSpecifitMonth (0);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Suma przychodow: +" << incomeSum << endl;
    cout << "Suma wydatkow: -" << expenseSum << endl;
    cout << "Bilans z biezacego miesiaca wynosi: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;

}
void OperationManager::showIncomeForTheSpecifitMonth (int howManyMonthsBack)
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getYear() == systemTime.wYear)
        {
            if (incomes[i].getMonth () == (systemTime.wMonth - howManyMonthsBack))
            {
                cout << "Nazwa operacji: " << incomes[i].getIncomeName() << endl;
                cout << "Data operacji: " << incomes[i].getYear () << "-" << incomes[i].getMonth () << "-" << incomes[i].getDay () << endl;
                cout << "Wartosc operacji: " << "+ " << incomes[i].getIncomeValue() << endl << endl;
                incomeSum += incomes[i].getIncomeValue();
            }
        }
    }
}
void OperationManager::showExpenseForTheSpecifitMonth (int howManyMonthsBack)
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getYear() == systemTime.wYear)
        {
            if (expenses[i].getMonth () == (systemTime.wMonth - howManyMonthsBack))
            {
                cout << "Nazwa operacji: " << expenses[i].getExpenseName() << endl;
                cout << "Data operacji: " << expenses[i].getYear () << "-" << expenses[i].getMonth () << "-" << expenses[i].getDay () << endl;
                cout << "Wartosc operacji: " << "- " << expenses[i].getExpenseValue() << endl << endl;
                expenseSum += expenses[i].getExpenseValue();
            }
        }
    }
}
void OperationManager::showBalanceSheetForThePreviousMonth ()
{
    cout << "------------ Bilans z poprzedniego miesiaca ------------" << endl;
    cout << "Przychody: " << endl << endl;
    showIncomeForTheSpecifitMonth (1);
    cout << "-------------------------------------------------------" << endl;
    cout << "Wydatki: " << endl << endl;
    showExpenseForTheSpecifitMonth (1);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Suma przychodow: +" << incomeSum << endl;
    cout << "Suma wydatkow: -" << expenseSum << endl;
    cout << "Bilans z poprzedniego miesiaca wynosi: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;
}
void OperationManager::showBalanceSheetForTheSelectedPeriod ()
{
    system("cls");
    Date firstDate;
    string date = "";
    Date secondDate;
    do
    {
        do
        {
            cout << "Podaj pocz¹tkowa date okresu w formacie rrrr-mm-dd: " << endl;
            date = auxiliaryMethods.loadLine();
        }
        while (!checkCorrectnessFormat(date));
        firstDate = setDateToVectorIncome(date);
    }
    while(!checkTheTimeInterval(firstDate.getYear(), firstDate.getMonth(), firstDate.getDay()));

    do
    {
        do
        {
            cout << "Podaj koncowa date okresu w formacie rrrr-mm-dd: " << endl;
            date = auxiliaryMethods.loadLine();
        }
        while (!checkCorrectnessFormat(date));
        secondDate = setDateToVectorIncome(date);
    }
    while(!checkTheTimeInterval(secondDate.getYear(), secondDate.getMonth(), secondDate.getDay()));
    cout << "------------ Bilans z wybranego okresu ------------" << endl;
    cout << "Przychody: " << endl << endl;
    showIncomeForTheSelectedPeriod(firstDate, secondDate);
    cout << "-------------------------------------------------------" << endl;
    cout << "Wydatki: " << endl << endl;
    showExpenseForTheSelectedPeriod (firstDate, secondDate);
    cout << "-------------------------------------------------------" << endl;
    sum = incomeSum - expenseSum;
    cout << "Suma przychodow: +" << incomeSum << endl;
    cout << "Suma wydatkow: -" << expenseSum << endl;
    cout << "Bilans z poprzedniego miesiaca wynosi: " << sum << endl;
    system ("pause");
    sum = 0;
    expenseSum = 0;
    incomeSum = 0;


}
void OperationManager::showIncomeForTheSelectedPeriod (Date firstDate, Date secondDate)
{
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
            cout << "Nazwa operacji: " << incomes[i].getIncomeName() << endl;
            cout << "Data operacji: " << incomes[i].getYear () << "-" << incomes[i].getMonth () << "-" << incomes[i].getDay () << endl;
            cout << "Wartosc operacji: " << "+ " << incomes[i].getIncomeValue() << endl << endl;
            incomeSum += incomes[i].getIncomeValue();
        }
    }
    cout << "wyszedlem" << endl;
}
void OperationManager::showExpenseForTheSelectedPeriod (Date firstDate, Date secondDate)
{
    cout << "wszedlem" << endl;
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
            cout << "Nazwa operacji: " << expenses[i].getExpenseName() << endl;
            cout << "Data operacji: " << expenses[i].getYear () << "-" << expenses[i].getMonth () << "-" << expenses[i].getDay () << endl;
            cout << "Wartosc operacji: " << "+ " << expenses[i].getExpenseValue() << endl << endl;
            expenseSum += expenses[i].getExpenseValue();
        }
    }
}
string OperationManager::replaceCommaWithPeriod (string value)
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
int OperationManager::assignIncomeIndex ()
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
int OperationManager::assignExpenseIndex()
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
