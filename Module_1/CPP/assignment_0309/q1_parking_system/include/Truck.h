#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle{
    public:
        Truck(double duration);
        double calculateCharge() override;
        double calculateExtraCharges() override;
        void display() override;
        void displayCal(string couponName) override;
        ~Truck();
};

#endif