#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include "TextFile.h"
#include "Markup.h"
#include "Income.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class FileWithIncome : public TextFile
{
    AuxiliaryMethods auxiliaryMethods;
    User loggedInUser;

public:
    FileWithIncome(string nameFileWtihIncome, User LOGGEDINUSER) : TextFile(nameFileWtihIncome), loggedInUser(LOGGEDINUSER) {};
    void addIncomeToFile (Income income);
    vector <Income> loadIncomeFromFile();

};
#endif
