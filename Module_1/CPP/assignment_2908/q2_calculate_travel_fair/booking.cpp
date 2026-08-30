#include <iostream>
#include "booking.h"
#include "constants.h"
#include <cstring>

using namespace std;

int Booking::bookingIdCounter = 1;

// Booking constructor we are defining
Booking::Booking(){
    bookingId = bookingIdCounter++;
    source = new char[1];
    source[0] = '\0';
    destination = new char[1];
    destination[0] = '\0';
    distance = 0;
    fair = 0;
}

Booking::Booking(char *source, char *destination, double distance){
    bookingId = bookingIdCounter++;
    this->source = new char[strlen(source) + 1];
    strcpy(this->source, source);
    this->destination = new char[strlen(destination) + 1];
    strcpy(this->destination, destination);
    this->distance = distance;   
    this->calculateFair(distance);
}

Booking::Booking(Booking &b){
    bookingId = bookingIdCounter++;
    source = b.source;
    destination = b.destination;
    distance = b.distance;
    fair = b.fair;
}

// private method calculateFair
double Booking::calculateFair(double distance){
        return (Constants::getdDefaultFair() * distance);
}

// getters
int Booking::getBookingId() const {
    return bookingId;
}
const char* Booking::getDestination() const {
    // cout << "before returning the destination : " << destination << endl;
    return destination;
}
const char* Booking::getSource() const {
    // cout << "before returning the source : " << source << endl;
    return source;
};
double Booking::getDistance() const {
    return distance;
};
double Booking::getFair() const {
    return fair;
};

// setters
void Booking::setSource(char* source){
    if(this->source){
        delete[] this->source;
    }
    this->source = new char[strlen(source) + 1];
    strcpy(this->source, source);
}

void Booking::setDestination(char* destination){
    if(this->destination){
        delete[] this->destination;
    }
    this->destination = new char[strlen(destination) + 1];
    strcpy(this->destination, destination);
}

void Booking::setDistance(double distance){
    this->distance = distance;
}

// methods
// double calculateFair();
// double calculateFair(int mode, int vehicle);
// double calculateFair(int mode, int vehicle, int noOfPassenger);
// double calculateFair(bool isPremium=false, int additionalCharge);

double Booking::calculateFair(){
    return this->getFair();
}

double Booking::calculateFair(int mode, int vehicle){
    // double normalFair = this->getFair() / Constants::getdDefaultFair();
    // cout << "normalFair : " << normalFair <<endl;

    switch(mode){
        // 1 - land
        case 1:
            switch(vehicle){
                // 1 - two wheeler
                case 1:
                    return (Constants::getLandTwoWheelerDefaultFair() * this->getDistance());
                    break;
                // 2 - 4 wheeler
                case 2:
                    return (Constants::getLandFourWheelerDefaultFair() * this->getDistance());
                    break;
                default:
                    cout << "Enter the wrong choice\n";
                    break;
                }
            break;
        // 2 - water
        case 2:
            return (Constants::getWaterVehicleDefaultFair() * this->getDistance());
            break;
        // 3 - air
        case 3:
            return (Constants::getAirVehicleDefaultFair() * this->getDistance());
            break;
        default:
            cout << "Enter the wrong choice\n";
            break;
    }
    return 0;
}

double Booking::calculateFair(int mode, int vehicle, int noOfPassenger){
    // double normalFair = this->getFair() / Constants::getdDefaultFair();
    double peopleFairMultiplier = noOfPassenger * Constants::getDefaultfairIncreaseAsPerPeople();
    // cout << "normalFair : " << normalFair << endl;
    cout << "peopleFairMultiplier : " << peopleFairMultiplier << endl;

    switch(mode){
        // 1 - land
        case 1:
            switch(vehicle){
                // 1 - two wheeler
                case 1:
                    return (Constants::getLandTwoWheelerDefaultFair() * this->getDistance() * peopleFairMultiplier);
                    break;
                // 2 - 4 wheeler
                case 2:
                    return (Constants::getLandFourWheelerDefaultFair() * this->getDistance() * peopleFairMultiplier);
                    break;
                default:
                    cout << "Enter the wrong choice\n";
                    break;
                }
            break;
        // 2 - water
        case 2:
            return (Constants::getWaterVehicleDefaultFair() * this->getDistance() * peopleFairMultiplier);
            break;
        // 3 - air
        case 3:
            return (Constants::getAirVehicleDefaultFair() * this->getDistance() * peopleFairMultiplier);
            break;
        default:
            cout << "Enter the wrong choice\n";
            break;
        }
    return 0;
}

double Booking::calculateFair(bool isPremium, int additionalCharge){
    if(!isPremium){
        return this->getFair();
    }
    else{
        return this->getFair() + additionalCharge;
    }
}


//desctructor
Booking::~Booking(){
    if(source){
        delete[] source;
    }
    if(destination){
        delete[] destination;
    }
}

ostream& operator<<(ostream& out, Booking &b){
    out << "bookingId : " << b.getBookingId() << endl
        << "source : " << b.getSource() << endl
        << "destination : " << b.getDestination() << endl
        <<  "distance : " << fixed << b.getDistance() << endl
        <<  "fair : " << fixed << b.getFair() << endl
        << "------------------------------" << endl;
    return out;
}

istream& operator>>(istream& in, Booking &e){
    char source[100];
    char destination[100];
    double distance;
    double fair;

    cout << "Enter the source : ";
    in >> source;
    cout << "Enter the destination : ";
    in >> destination;
    cout << "Enter the distance : ";
    in >> distance;
    
    char *sr;
    sr = new char[strlen(source) + 1];
    strcpy(sr, source);
    // cout << "at the time of set sr : " << sr << endl;

    char *dest;
    dest = new char[strlen(destination) + 1];
    strcpy(dest, destination);
    // cout << "at the time of set dest : " << dest << endl;
    e.setSource(sr);
    e.setDestination(dest);
    e.setDistance(distance);
    e.fair = e.calculateFair(distance);

    return in;
}

