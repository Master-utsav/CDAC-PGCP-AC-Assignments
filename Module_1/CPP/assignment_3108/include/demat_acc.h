#ifndef DEMAT_ACC_H
#define DEMAT_ACC_H

#include "bank.h"
#include "shares.h"

const int MAX_SHARES = 100; // maximum number of shares that can be stored in a demat account
// For demat account store share details, for every share store name, number of shares buying price, date of purchase, selling price, date of selling.
class DematAcc : public Bank{
    private:
        static int shareId;
        Shares* share[MAX_SHARES];  
    
    public:
        // constructor
        DematAcc();
        DematAcc(char *fname, char *lname, long long int mob, char *email, int pin, double balance);
        
        // setter
        void setShare(char* name, int shareCount, double perSharePrice, int dateOfPurchase);

        //getter
        Shares *getShareById(int id) const;
        void sellShare(int shareId, double sellingPrice, int dateOfSelling) const;
        void displayProfit(int shareId);

        void display();

        // getter
        Shares* getShares() const;

        // destructor
        ~DematAcc();

};

#endif