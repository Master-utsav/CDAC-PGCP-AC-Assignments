#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

enum class VehicleType{
    CAR,
    TRUCK
};

class Vehicle{
    private:
        int id;
        static int nextId;
        
    protected:
        VehicleType type;
        double fixedParkingCharge;
        int fixedParkingChargeDuration;
        double extraChargesperHour;
        string couponName;
        int couponDiscountPrice;
        double duration;
        double extraCharges;
        double totalParkingCharges;

    public:
        Vehicle();
        virtual double calculateCharge() = 0;
        virtual double calculateExtraCharges() = 0;
        virtual void display();
        virtual void displayCal(string couponName);
        int getId() const {return id;}
        virtual ~Vehicle();
};


#endif