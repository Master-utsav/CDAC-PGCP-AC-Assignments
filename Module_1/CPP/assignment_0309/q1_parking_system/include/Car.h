#ifndef CAR_H
#define CAR_H

#include <string>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle{
    public:
        Car(double duration);
        double calculateCharge() override;
        double calculateExtraCharges() override;
        void display() override;
        void displayCal(string couponName) override;
        ~Car();
};


#endif