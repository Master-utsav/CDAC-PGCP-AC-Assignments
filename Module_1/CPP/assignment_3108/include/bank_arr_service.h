#ifndef BANKING_ARR_SERVICE_H
#define BANKING_ARR_SERVICE_H
#include "bank.h"
#include "saving_acc.h"
#include "current_acc.h"
#include "demat_acc.h"

class BankArrService{
    public:
        BankArrService();

        static void addNewAccount();
        static void displayAccountBalanceById();
        static void closeAccount();
        static void countTypeOfAccount();
        static void withdrawAmount();
        static void depositAmount();
        static void changePin();
        static void dmatAccountLogin();

        ~BankArrService();

};

#endif