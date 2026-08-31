#include <iostream>
#include <cstring>
#include "shares.h"

using namespace std;

extern double calculateProfit(int shareCount , int perSharePrice , double sellingPrice);

// date of selling and selling price should be setted only on the time of selling the share
Shares::Shares(char* name, int shareCount, double perSharePrice, int dateOfPurchase){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->shareCount = shareCount;
    this->perSharePrice = perSharePrice;
    this-> dateOfPurchase = dateOfPurchase;
}

// setter int , double 
void Shares::setDateOfSelling(int sellingDate){
    dateOfSelling = sellingDate;
};
void Shares::setSellingPrice(double sellingPrice){
    this->sellingPrice = sellingPrice;
};

void Shares::display(){
    cout << "Share Name: " << name << endl;
    cout << "Share Count: " << shareCount << endl;
    cout << "Per Share Price: " << perSharePrice << endl;
    cout << "Date of Purchase: " << dateOfPurchase << endl;
    if(dateOfSelling != 0){
        cout << "Date of Selling: " << dateOfSelling << endl;
        cout << "Selling Price: " << sellingPrice << endl;
    }
};

// getter
double Shares::getProfit() const { 
    return calculateProfit(shareCount , perSharePrice , sellingPrice);
};

// destructor
Shares::~Shares(){
    delete[] name;
}
