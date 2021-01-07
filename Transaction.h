#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
        int userId;
        int transactionId;
        string date;
        int dayNr;
        string item;
        double amount;

    public:
        Transaction();
        friend class TransactionManager;
        friend class FileWithIncomes;
        friend class FileWithExpenses;
};

#endif
