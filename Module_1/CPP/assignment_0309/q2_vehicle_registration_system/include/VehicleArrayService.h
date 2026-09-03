#ifndef VEHICLE_ARRAY_SERVICE_H
#define VEHICLE_ARRAY_SERVICE_H

#include "Vehicle2.h"
#include "Car2.h"
#include "Bike2.h"

class VehicleArrayService {
    private:
        static const int MAX_VEHICLES = 100;
        static Vehicle* vehicles[MAX_VEHICLES];
        static int vehicleCount;

    public:
        static bool addVehicle();
        static void displayAll();
        static void displayByType();
        static void countAllType();
        static void saveDataToFile();
        static void loadDataFromFile();
};

#endif