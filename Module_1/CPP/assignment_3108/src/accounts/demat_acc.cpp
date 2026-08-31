#include <iostream>
#include <cstring>
#include "bank.h"
#include "demat_acc.h"

using namespace std;

int DematAcc::shareId = 0;

// For demat account store share details, for every share store name, number of shares buying price, date of purchase, selling price, date of selling.
DematAcc::DematAcc() : Bank::Bank() {}
DematAcc::DematAcc(char *fname, char *lname, long long int mob, char *email, int pin, double balance) : Bank::Bank(fname, lname, mob, email, pin, balance) {}

void DematAcc::setShare(char *name, int shareCount, double perSharePrice, int dateOfPurchase){
        Shares *s = new Shares(name, shareCount, perSharePrice, dateOfPurchase);
        share[shareId++] = s;
}

void DematAcc::display(){
    Bank::display();
    cout << "Shares Details: " << endl;
    for(int i = 0; i < shareId; i++){
        share[i]->display();
    }
}

Shares* DematAcc::getShares() const{
    return *share;
}

Shares* DematAcc::getShareById(int id) const {
    if(id < 0 || id >= shareId){
        return nullptr;
    }
    return share[id];
}

void DematAcc::sellShare(int shareId, double sellingPrice, int dateOfSelling) const {
    if(shareId < 0 || shareId >= DematAcc::shareId){
        cout << "Invalid share ID." << endl;
        return;
    }
    share[shareId]->setSellingPrice(sellingPrice);
    share[shareId]->setDateOfSelling(dateOfSelling);
}

void DematAcc::displayProfit(int shareId) {
    if(shareId < 0 || shareId >= DematAcc::shareId){
        cout << "Invalid share ID." << endl;
        return;
    }
    double profit = share[shareId]->getProfit();
    Bank::setBalance(Bank::getBalance() + profit);
    cout << "Updated Account Balance: " << Bank::getBalance() << endl;
    cout << "Profit for Share ID " << shareId << ": " << profit << endl;
}

DematAcc::~DematAcc(){
    for(int i = 0; i < shareId; i++){
        delete share[i];
    }
}
