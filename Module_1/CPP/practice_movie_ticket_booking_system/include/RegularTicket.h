// RegularTicket — adds SeatNumber
//     PremiumTicket — adds SeatNumber and
//     HasRecliner(bool),
//     price includes a recliner surcharge

#ifndef REGULAR_TICKET_H
#define REGULAR_TICKET_H

#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

class RegularTicket : public Ticket{
    
    public:
        RegularTicket(const vector<int> &seatNumbers, string movieName, int showYear, double price);

        double getPrice() const { return price; }
        void setPrice(double newPrice) { price = newPrice; };

        virtual void serialize(ostream &os) const override;
        virtual void deserialize(istream &is) override;

        void display() override;
};

#endif
