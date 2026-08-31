#include<iostream>
#include <cstring>
#include "bank.h"

using namespace std;

int Bank::count = 1;
extern long int createAccountNumber(int count);
extern double getAverageAnnualBalance(double bal, double minBalance);

// default constructor
Bank::Bank(){
    accNo = createAccountNumber(count);
    count++;
    balance = 0;
    minBalance = 0;
    interestRate = 0;
    averageAnnualBalance = 0;
    fname = new char[1];
    fname[0] = '\0';
    lname = new char[1];
    lname[0] = '\0';
    mob = mob;
    email = new char[1];
    email[0] = '\0';
    pin = pin;
    isAccountClosed = false;
}

// parametrized constructor
Bank::Bank(char* fname, char* lname, long long int mob, char* email, int pin, double balance){
    accNo = createAccountNumber(count);
    count++;
    this->balance = balance;
    minBalance = 0;
    interestRate = 0;
    this->fname = new char[strlen(fname) + 1];
    strcpy(this->fname,fname);
    this->lname = new char[strlen(lname) + 1];
    strcpy(this->lname,lname);
    this->mob = mob;
    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);
    this->pin = pin;
    isAccountClosed = false;
}

// getters
long int Bank::getAccNo() const{
        return accNo;
};
double Bank::getBalance() const{
    return balance;
};
int Bank::getCount() const {
    return count;
}

// setters
void Bank::setPin(int oldPin , int newPin){
    if(oldPin != pin){
        cout << "-------entered invalid pin--------" << endl;
        return;
    }
    pin = newPin;
};
void Bank::setAverageAnnualBalance(){
    averageAnnualBalance = getAverageAnnualBalance(this->balance, minBalance);
}
void Bank::setBalance(double balance){
    this->balance = balance;
};

// methods 
void Bank::fxnWithdrawAmount(double withdrawAmount){
    if(balance - withdrawAmount >= minBalance){
        balance -= withdrawAmount;
    }else{
        cout << "-------insufficient balance--------" << endl;
    }
}
void Bank::fxnDepositAmount(double depositAmount){
    balance += depositAmount;
}

bool Bank::getIsAccountClosed() const {
    return isAccountClosed;
}

bool Bank::setIsAccountClosed(bool isAccountClosed) {
    this->isAccountClosed = isAccountClosed;
    return this->isAccountClosed;
}

void Bank::display(){
    
    cout << "Account Number: " << accNo << endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Mobile Number: " << mob << endl;
    cout << "Email: " << email << endl;
    cout << "Balance: " << balance << endl;
    
}; 

// desctructor
Bank::~Bank(){
    delete[] fname;
    delete[] lname;
    delete[] email;
};
