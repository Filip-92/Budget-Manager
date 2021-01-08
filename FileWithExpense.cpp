#include "FileWithExpense.h"

void FileWithExpense::addExpenseToFile (Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( getNameFile() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expense");
    }
    if (fileExists)
    {
        xml.Load(getNameFile());
        while (xml.FindChildElem("User"))
        {
            xml.IntoElem();
            xml.FindChildElem("UserId");
            if (atoi(xml.GetChildData().c_str()) == loggedInUser.getId())
            {
                xml.IntoElem();
                xml.AddElem("Expenses");
                xml.IntoElem();
                xml.AddElem("Index", expense.getExpenseIndex());
                xml.AddElem("ExpenseName", expense.getExpenseName());
                xml.AddElem("ExpenseYear", expense.getYear());
                xml.AddElem("ExpenseMonth", expense.getMonth());
                xml.AddElem("ExpenseDay", expense.getDay());
                xml.AddElem("ExpenseValue", auxiliaryMethods.converionFloatToString(expense.getExpenseValue()));
                xml.Save(getNameFile());
                return;
            }
            xml.OutOfElem();
        }
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", loggedInUser.getId());
    xml.AddElem("Expenses");
    xml.IntoElem();
    xml.AddElem("Index", expense.getExpenseIndex());
    xml.AddElem("ExpenseName", expense.getExpenseName());
    xml.AddElem("ExpenseYear", expense.getYear());
    xml.AddElem("ExpenseMonth", expense.getMonth());
    xml.AddElem("ExpenseDay", expense.getDay());
    xml.AddElem("ExpenseValue", auxiliaryMethods.converionFloatToString(expense.getExpenseValue()));
    xml.Save(getNameFile());
}

vector <Expense> FileWithExpense::loadExpenseFromFile()
{
    vector <Expense> expense;
    CMarkup xml;
    int i = 0;
    xml.Load(getNameFile());
    while (xml.FindChildElem("User"))
    {
        xml.IntoElem();
        xml.FindChildElem("UserId");
        if (atoi(xml.GetChildData().c_str()) == loggedInUser.getId())
        {

            while (xml.FindChildElem("Expenses"))
            {
                expense.push_back(Expense());
                xml.IntoElem();
                xml.FindChildElem("Index");
                expense[i].setExpenseIndex (atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeName");
                expense[i].setExpenseName(xml.GetChildData());
                xml.FindChildElem("IncomeYear");
                expense[i].setYear(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeMonth");
                expense[i].setMonth(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeDay");
                expense[i].setDay(atoi(xml.GetChildData().c_str()));
                xml.FindChildElem("IncomeValue");
                expense[i].setExpenseValue(atof(xml.GetChildData().c_str()));
                xml.OutOfElem();
                i++;
            }
            return expense;
        }
        xml.OutOfElem();
    }
}
