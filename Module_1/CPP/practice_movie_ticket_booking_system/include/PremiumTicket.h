
#ifndef PREMIUM_TICKET_H
#define PREMIUM_TICKET_H

#include <string>
#include <vector>
#include "Ticket.h"
#include "RegularTicket.h"

using namespace std;

class PremiumTicket : public RegularTicket{
    private:
        double surcharges = 200;
        bool hasRecliner = false;

    public:
        PremiumTicket(bool hasRecliner, const vector<int> &seatNumbers, string movieName, int showYear, double price);

        double getPrice() const { return price; }
        void setPrice(double newPrice) {
            price = newPrice;
        };

        virtual void serialize(ostream &os) const override;
        virtual void deserialize(istream &is) override;

        void display() override;
};

#endif