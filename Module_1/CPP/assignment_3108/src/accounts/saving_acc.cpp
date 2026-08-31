#include<iostream>
#include <cstring>
#include "bank.h"
#include "saving_acc.h"

using namespace std;

extern int createChequeBookNumber(int count);

// default constructor
SavingAcc::SavingAcc():Bank::Bank(){
    chequeBookNumber = createChequeBookNumber(this->getCount());
    minBalance = 2000;
    interestRate = 4;
}

// parametrized constructor
SavingAcc::SavingAcc(char* fname, char* lname, long long int mob, char* email, int pin, double balance):
    Bank::Bank(fname, lname, mob, email, pin, balance){
    chequeBookNumber = createChequeBookNumber(this->getCount());
    minBalance = 2000;
    interestRate = 4;
}

// getters
int SavingAcc::getChequebooknumber() const { 
        return chequeBookNumber;
};

void SavingAcc::display(){
    Bank::display();
    cout << "Cheque Book Number: " << chequeBookNumber << endl;
}; 

// desctructor
SavingAcc::~SavingAcc(){};
