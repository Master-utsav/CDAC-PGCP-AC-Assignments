#include<iostream>
#include <cstring>
#include "bank.h"
#include "current_acc.h"

using namespace std;

extern int calculatetrxnPerDayLimit(double averageAnnualBalance);

// default constructor
CurrentAcc::CurrentAcc():Bank::Bank(){
    setAverageAnnualBalance();
    trxnPerDay = calculatetrxnPerDayLimit(averageAnnualBalance);
    minBalance = 1000;
    interestRate = 1;
}

// parametrized constructor
CurrentAcc::CurrentAcc(char* fname, char* lname, long long int mob, char* email, int pin, double balance):
    Bank::Bank(fname, lname, mob, email, pin, balance){
    setAverageAnnualBalance();
    trxnPerDay = calculatetrxnPerDayLimit(averageAnnualBalance);
    minBalance = 1000;
    interestRate = 1;
}

// setter
void CurrentAcc::setTrxnPerDay(){
    setAverageAnnualBalance();
    trxnPerDay = calculatetrxnPerDayLimit(averageAnnualBalance);
}

// getter
int CurrentAcc::getTrxnPerDay() const {
    return trxnPerDay;
}

void CurrentAcc::display(){
    Bank::display();
    cout << "Average Annual Balance: " << averageAnnualBalance << endl;
    cout << "Transaction Per Day Limit: " << trxnPerDay << endl;
}; 

// desctructor
CurrentAcc::~CurrentAcc(){};
