#include <iostream>
#include <string>
#include "Truck.h"

using namespace std;

Truck::Truck(double duration) : Vehicle(){
    type = VehicleType::TRUCK;
    fixedParkingCharge = 200;
    fixedParkingChargeDuration = 2;
    extraChargesperHour = 50;
    this->duration = duration;
    couponName = "TRUCK50";
    couponDiscountPrice = 50;
    totalParkingCharges = calculateCharge();
    extraCharges = calculateExtraCharges();
}

double Truck::calculateCharge() {
    double remDuration = duration - fixedParkingChargeDuration;
    double totalCharge = fixedParkingCharge;
    if(remDuration > 0){
        totalCharge += Truck::calculateExtraCharges();
    }
    return totalCharge;
}

inline double Truck::calculateExtraCharges() {
    double remDuration = duration - fixedParkingChargeDuration;
    return remDuration > 0 ? remDuration*extraChargesperHour : 0;
}

void Truck::displayCal(string couponName){
     Vehicle::display();
     cout << "Extra charge = Rs. " << extraCharges << endl;
     cout << "Total Parking Charge = Rs. " << totalParkingCharges << endl;
     if(!couponName.empty()){
        if(couponName == this->couponName){
            double chargesAfterDiscount = Truck::calculateCharge() - couponDiscountPrice;
            cout << "Total Charge after discount = Rs. " << chargesAfterDiscount << endl;
        }
        else{
            cout << "Invalid coupon..." << endl;
        }
     }
     cout << "--------------------------------" << endl;
}

void Truck::display(){
    Vehicle::display();
    cout << "Fixed parking charge: Rs. " << fixedParkingCharge << " for first " << fixedParkingChargeDuration << " hours" << endl;
    cout << "Beyond " << fixedParkingChargeDuration << " hours: Rs. " << extraChargesperHour << " per hour" << endl;
    if(!couponName.empty()){
        cout << "Discount available: Code "<< couponName << " gives Rs. " << couponDiscountPrice << " off" << endl;
    }
    else{
        cout << "No discount available." << endl;
    }
}

Truck::~Truck(){};