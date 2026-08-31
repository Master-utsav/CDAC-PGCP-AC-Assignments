#ifndef SAVING_ACC_H
#define SAVING_ACC_H

#include "bank.h"


// If it’s a saving account, then store chequebooknumber
class SavingAcc : public Bank{
    private:
        int chequeBookNumber;
    
    public:
        // constructor
        SavingAcc();
        SavingAcc(char* fname, char* lname, long long int mob, char* email, int pin, double balance);
        
        // setter
        void display();

        // getter
        int getChequebooknumber() const;

        // destructor
        ~SavingAcc();

};

#endif