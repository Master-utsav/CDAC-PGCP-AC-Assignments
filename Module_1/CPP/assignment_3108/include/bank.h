#ifndef BANK_H
#define BANK_H

class Bank{
    private: 
        static int count;
        double balance;
        long int accNo;
        bool isAccountClosed = false;
        int pin; 
        
    protected:
        char* fname;
        char* lname;
        long long int mob;
        char* email;
        // write getter setter inside Bank class for above 4 data members
        double minBalance;
        double interestRate;
        double averageAnnualBalance;

        void setBalance(double balance);
    public:
        // default constructor
        Bank();
        // parametrized constructor
        Bank(char* fname, char* lname, long long int mob, char* email, int pin, double balance);

        // getters
        long int getAccNo() const;
        int getCount() const;
        double getBalance() const;

        // setters
        void setPin(int oldPin, int newPin);
        void setAverageAnnualBalance();

        // isAccountClosed getter and setter
        bool getIsAccountClosed() const;
        bool setIsAccountClosed(bool isAccountClosed);

        // methods
        void fxnWithdrawAmount(double withdrawAmount);
        void fxnDepositAmount(double depositAmount);

        // virtual void setMinBalance (); // no req. for pure virtual function because demat acc. have no min bal concept
        // virtual void setInterestRate(); // no req. for pure virtual function because demat acc. have no min intrest rate concept

        virtual void display(); 

        // desctructor
        virtual ~Bank();

};

#endif