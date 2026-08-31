#ifndef SHARES_H
#define SHARES_H

// Shares class for holding shares
// every share store name, number of shares buying price, date of purchase, selling price, date of selling.
class Shares{
    private:
        char* name;
        int shareCount;
        double perSharePrice;
        int dateOfPurchase;
        int dateOfSelling;
        double sellingPrice;

    public:
        // date of selling and selling price should be setted only on the time of selling the share
        Shares(char* name, int shareCount, double perSharePrice, int dateOfPurchase); 
        // setter
        void setDateOfSelling(int dateOfSelling);
        void setSellingPrice(double sellingPrice);
        void display();

        // getter
        double getProfit() const;

        // destructor
        ~Shares();

};

#endif