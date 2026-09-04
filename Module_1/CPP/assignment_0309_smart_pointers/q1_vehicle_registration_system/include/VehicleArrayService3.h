#ifndef VEHICLE_ARRAY_SERVICE_H
#define VEHICLE_ARRAY_SERVICE_H

#include "Vehicle3.h"
#include "Car3.h"
#include "Bike3.h"
#include <vector>
#include <memory>

class VehicleArrayService {
    private:
        static vector<shared_ptr<Vehicle>> vehicles;
        // static const int MAX_VEHICLES = 100;
        // static Vehicle* vehicles[MAX_VEHICLES];
        // static int vehicleCount;

    public:
        static bool addVehicle();
        static void displayAll();
        static void displayByType();
        static void countAllType();
        static void saveDataToFile();
        static void loadDataFromFile();
        static void displayInfoAsPerType(VehicleType vt);
};

#endif