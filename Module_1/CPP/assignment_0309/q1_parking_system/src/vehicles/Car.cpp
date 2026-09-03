#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(double duration) : Vehicle(){
    type = VehicleType::CAR;
    fixedParkingCharge = 100;
    fixedParkingChargeDuration = 3;
    extraChargesperHour = 30;
    this->duration = duration;
    totalParkingCharges = calculateCharge();
    extraCharges = calculateExtraCharges();
}

double Car::calculateCharge() {
    double remDuration = duration - fixedParkingChargeDuration;
    double totalCharge = fixedParkingCharge;
    if(remDuration > 0){
        totalCharge += Car::calculateExtraCharges();
    }
    return totalCharge;
}

inline double Car::calculateExtraCharges() {
    double remDuration = duration - fixedParkingChargeDuration;
    return remDuration > 0 ? remDuration*extraChargesperHour : 0;
}

void Car::displayCal(string couponName) {
     Vehicle::display();
     cout << "Extra charge = Rs. " << extraCharges << endl;
     cout << "Total Parking Charge = Rs. " << totalParkingCharges << endl;
     if(!couponName.empty()){
        if(couponName == this->couponName){
            double chargesAfterDiscount = Car::calculateCharge() - couponDiscountPrice;
            cout << "Total Charge after discount = Rs. " << chargesAfterDiscount << endl;
        }
        else{
            cout << "Invalid coupon..." << endl;
        }
     }
    cout << "--------------------------------" << endl;
}

void Car::display() {
    Vehicle::display();
    cout << "Fixed parking charge: Rs. " << fixedParkingCharge << " for first " << fixedParkingChargeDuration << " hours" << endl;
    cout << "Beyond " << fixedParkingChargeDuration << " hours: Rs. " << extraChargesperHour << " per hour" << endl;
    if (!couponName.empty()){
        cout << "Discount available: Code "<< couponName << " gives Rs. " << couponDiscountPrice << " off" << endl;
    }
    else{
        cout << "No discount available." << endl;
    }
}

Car::~Car(){};