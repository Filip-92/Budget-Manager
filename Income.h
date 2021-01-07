#ifndef INCOME_H
#define INCOME_H
#include "Transaction.h"

using namespace std;

class Income: public Transaction
{
    string item;

public:
    Income();
    friend class TransactionManager;
    friend class FileWithIncomes;
};

#endif
