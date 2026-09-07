#include "RegularTicket.h"
#include "Ticket.h"
#include <vector>

#include <iostream>

using namespace std;

RegularTicket::RegularTicket(const vector<int> &seatNumbers, string movieName, int showYear, double price) : Ticket(seatNumbers, movieName, showYear, price){
    type = BookingType::Regular;
}

void RegularTicket::display(){
    Ticket::display();
    cout << "Price : " << this->getPrice() << endl;
    cout << "Seat Numbers which is booked : [ ";
    for(auto &it: seatNumbers){
        cout << it << ", ";
    }
    cout << " ]" << endl;
    cout << "=========================================" << endl;
}

void RegularTicket::serialize(ostream &os) const {
    int len;

    os.write(reinterpret_cast<const char *>(&type), sizeof(type));

    int bookingId = getBookingId();
    os.write(reinterpret_cast<const char *>(&bookingId), sizeof(bookingId));

    len = movieName.length();
    os.write(reinterpret_cast<char *>(&len), sizeof(len));
    os.write(movieName.c_str(), len);

    os.write(reinterpret_cast<const char *>(&showYear), sizeof(showYear));

    os.write(reinterpret_cast<const char *>(&price), sizeof(price));

    len = seatNumbers.size();
    os.write(reinterpret_cast<char *>(&len), sizeof(len));
    for (int seat : seatNumbers) {
        os.write(reinterpret_cast<char *>(&seat), sizeof(seat));
    }

    if(!os){
        throw(runtime_error("Error while serialize.. Regular ticket"));
    }
}
void RegularTicket::deserialize(istream &is) {
    int len;

    // is.read(reinterpret_cast<char *>(&type), sizeof(type));
    type = BookingType::Regular;

    int bookingId;
    is.read(reinterpret_cast<char *>(&bookingId), sizeof(bookingId));
    this->setBookingId(bookingId);

    is.read(reinterpret_cast<char *>(&len), sizeof(len));
    string movieNm(len, '\0');
    is.read(&movieNm[0], len);
    movieName = movieNm;

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
      if(!is){
        throw(runtime_error("Error while reading the data : error in Regular ticket deserialize"));
    }

}