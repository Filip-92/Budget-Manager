#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include "XmlFile.h"
#include "Markup.h"
#include "Expense.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class FileWithExpense : public XmlFile
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;

public:
    FileWithExpense(string nameFileWtihExpense, User LOGGEDINUSER) : XmlFile(nameFileWtihExpense), loggedInUser(LOGGEDINUSER) {};
    void addExpenseToFile (Expense expense);
    vector <Expense> loadExpenseFromFile();
};

#endif

