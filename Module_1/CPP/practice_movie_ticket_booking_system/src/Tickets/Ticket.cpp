#include "Ticket.h"
#include <iostream>
#include <vector>
using namespace std;

int Ticket::nextBookingId = 1;

Ticket::Ticket(const vector<int> &seatNumbers, string movieName, int showYear, double price)
    : movieName(movieName), showYear(showYear), price(price), bookingId(nextBookingId++), seatNumbers(seatNumbers) {};

Ticket::~Ticket() {};

void Ticket::display(){
    cout << "Booking Id : " << bookingId << endl;
    cout << "movie Name : " << movieName << endl;
    cout << "show Year : " << showYear << endl;
}