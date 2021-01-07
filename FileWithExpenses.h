#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include <cstdlib>

#include "Expense.h"
#include "TransactionManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
    const string EXPENSES_FILE_NAME;
public:
    FileWithExpenses(string fileWithExpensesName);
    bool doesFileExist();
    //void saveExpensesToFile (vector <Expense> expenses);
    //vector <Expense> loadExpensesFromTheFile();
};

#endif
