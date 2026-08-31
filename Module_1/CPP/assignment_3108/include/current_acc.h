#ifndef CURRENT_ACC_H
#define CURRENT_ACC_H

#include "bank.h"

//If current account then store number of transactions/day, 
// number of transactions will be different for every account based on average annual 
// balance in the account and will keep on changing based on how customer maintains the balance in the account.
class CurrentAcc : public Bank{
    private:
        int trxnPerDay;
        // setter
        void setTrxnPerDay();

    public:
        // constructor
        CurrentAcc();
        CurrentAcc(char* fname, char* lname, long long int mob, char* email, int pin, double balance);
 
        void display();

        // getter
        int getTrxnPerDay() const;

        // destructor
        ~CurrentAcc();

};

#endif