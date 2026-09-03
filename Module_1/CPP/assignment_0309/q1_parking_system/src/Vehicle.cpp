#include <iostream>
#include "Vehicle.h"

using namespace std;

int Vehicle::nextId = 1;

Vehicle::Vehicle(){
    id = nextId++;
};
Vehicle::~Vehicle(){};

void Vehicle::display(){
    cout << "ID : " << id << endl;
    cout << "Vehicle Type : " 
         << (static_cast<int>(VehicleType::CAR) == 0 ? "CAR" : "TRUCK") 
         << endl;
}

void Vehicle::displayCal(string couponName){};


