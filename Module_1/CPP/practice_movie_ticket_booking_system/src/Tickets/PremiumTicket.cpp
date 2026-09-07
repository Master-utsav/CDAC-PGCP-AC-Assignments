#include "RegularTicket.h"
#include "PremiumTicket.h"
#include "Ticket.h"
#include <vector>

#include <iostream>

using namespace std;

PremiumTicket::PremiumTicket(bool hasRecliner, const vector<int> &seatNumbers, string movieName, int showYear, double price)
    : RegularTicket(seatNumbers, movieName, showYear, price), hasRecliner(hasRecliner){
    if (hasRecliner){
        setPrice(surcharges + price);
    }
    type = BookingType::Premium;
}

void PremiumTicket::display(){
    Ticket::display();
    cout << "Price : " << this->getPrice() << endl;
    cout << "Seat Numbers which is booked : [ ";
    for(auto &it: seatNumbers){
        cout << it << ", ";
    }
    cout << " ]" << endl;
    cout << "Recliner : " << (hasRecliner ? "Yes" : "No") << endl;   // FIX: added
    cout << "=========================================" << endl;
}


void PremiumTicket::serialize(ostream &os) const {
    RegularTicket::serialize(os);

    os.write(reinterpret_cast<const char *>(&hasRecliner), sizeof(hasRecliner));

    if(!os){
        throw(runtime_error("Error while serialize.. Premium ticket"));
    }
}


void PremiumTicket::deserialize(istream &is) {
    int len;

    type = BookingType::Premium;

    int bookingId;
    is.read(reinterpret_cast<char *>(&bookingId), sizeof(bookingId));
    this->setBookingId(bookingId);

    is.read(reinterpret_cast<char *>(&len), sizeof(len));
    string movieNm(len, '\0');
    is.read(&movieNm[0], len);
    this->movieName = movieNm;

    is.read(reinterpret_cast<char *>(&showYear), sizeof(showYear));
    this->showYear = showYear;

    is.read(reinterpret_cast<char *>(&price), sizeof(price));
    this->price = price;

    is.read(reinterpret_cast<char *>(&len), sizeof(len));  
    for (int i = 0; i < len; i++) {                        
        int seat;                                            
        is.read(reinterpret_cast<char *>(&seat), sizeof(seat));  
        this->seatNumbers.push_back(seat);                 
    }

    is.read(reinterpret_cast<char *>(&hasRecliner), sizeof(hasRecliner));
    this->hasRecliner = hasRecliner;

    if(!is){
        throw(runtime_error("Error while reading the data : error in Premium ticket deserialize"));
    }
}