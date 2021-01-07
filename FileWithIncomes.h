#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include <cstdlib>

#include "Income.h"
#include "TransactionManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
    const string INCOMES_FILE_NAME;
public:
    FileWithIncomes(string fileWithIncomesName);
    bool doesFileExist();
    void saveIncomesToFile (vector <Income> incomes);
    vector <Income> loadIncomesFromTheFile();
};

#endif
