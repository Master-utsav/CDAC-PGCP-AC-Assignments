#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
using namespace std;

class Booking{
    private:
        static int bookingIdCounter;
        int bookingId;
        char* source;
        char* destination;
        double distance;
        double fair;

        double calculateFair(double distance);

    public:
        Booking();
        Booking(char *source, char *destination, double distance);
        Booking(Booking &t);
        
        // getters
        const char* getSource() const;
        const char* getDestination() const;
        int getBookingId() const;
        double getDistance() const;
        double getFair() const;

        // setters
        void setSource(char* source);
        void setDestination(char* destination);
        void setDistance(double distance);

        // methods
        double calculateFair();
        double calculateFair(int mode, int vehicle);
        double calculateFair(int mode, int vehicle, int noOfPassenger);
        double calculateFair(bool isPremium, int additionalCharge);
        
        //destructor
        ~Booking();

        friend ostream& operator<<(ostream& out, Booking &b);
        friend istream& operator>>(istream& in, Booking &b);
};

#endif