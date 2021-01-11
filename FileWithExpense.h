#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include "TextFile.h"
#include "Markup.h"
#include "Expense.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class FileWithExpense: public TextFile
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;
public:
    FileWithExpense (string nameFileWtihExpense, User LOGGEDINUSER) : TextFile(nameFileWtihExpense), loggedInUser(LOGGEDINUSER) {};
    void addExpenseToFile (Expense);
    vector <Expense> loadExpenseFromFile();

};
#endif

