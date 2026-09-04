#include "VehicleArrayService3.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>

using namespace std;

extern bool isValidFuelType(FuelType ft);
extern bool readData(string fileName, vector<shared_ptr<Vehicle>> &v);
extern bool writeData(string fileName, vector<shared_ptr<Vehicle>> &v);

extern bool isValidYear(const string& year);
extern bool isValidYear(int year);

vector<shared_ptr<Vehicle>> VehicleArrayService::vehicles;

bool VehicleArrayService::addVehicle() {
    char vehicleTypeInput;
    bool status = false; 
    do{
        cout << "Enter type of vehicle (C for Car, B for Bike, E for Back to Menu): ";
        try{
            cin >> vehicleTypeInput;
            if(vehicleTypeInput != 'C' && vehicleTypeInput != 'B' && vehicleTypeInput != 'E'){
                throw runtime_error("Invalid vehicle type. Please enter 'C' for Car or 'B' for Bike or 'E' for Back.");
            }
            else
                break;
        }
        catch(runtime_error &e){
            cerr << "Error: " << e.what() << endl;
        }
    } while (vehicleTypeInput != 'E' || vehicleTypeInput != 'C' || vehicleTypeInput != 'B');
    cin.ignore();

    string modelName, manufacturerName;
    int yearOfManufacture;
    
    // eeter model nam and manufacture
    cout << "Enter Model Name: ";
    getline(cin, modelName);
    cout << "Enter Manufacturer: ";
    getline(cin, manufacturerName);
    
    // enter the year 
    cout << "Enter Year: ";
    int chanceToEnterYear = 3;
    for (int i = chanceToEnterYear; i > 0; i--){
        try{
            cin >> yearOfManufacture;
            status = isValidYear(yearOfManufacture);
            if(!status) {
                throw(runtime_error("Year in not valid [it should be in range of 2000 till current]"));
            }
            else break;
        }
        catch (runtime_error &e){
            cout << e.what() << endl;
            cout << "try attempts left : " << i - 1 << endl;
        }
    }
    if(!status) return false;
    cin.ignore();

    shared_ptr<Vehicle> v;
    int engineCap;
    int fuelChoice;

    switch (vehicleTypeInput){
        case 'B':
            cout << "Enter the engine capacity : ";
            cin >> engineCap;
            v = make_shared<Bike>(modelName, manufacturerName, yearOfManufacture, engineCap);
            vehicles.push_back(v);
            // vehicles[vehicleCount++] = v;
            break;
        case 'C':
            try{
                cout << "Enter Fuel Type " << endl;
                cout << "1. Petrol || 2. Dieset || 3. Electric || 4. CNG\n";
                cin >> fuelChoice;
                FuelType ft = static_cast<FuelType>(fuelChoice - 1);
                if (!isValidFuelType(ft))
                    throw(runtime_error("Invalid fuel choice entered"));
                else {
                    // v = new Car(modelName, manufacturerName, yearOfManufacture, ft);
                    v = make_shared<Car>(modelName, manufacturerName, yearOfManufacture, ft);
                    vehicles.push_back(v);
                    // vehicles[vehicleCount++] = v;
                }
            }
            catch(runtime_error& e){
                cout << e.what() << endl;
            }
            break;
        case 'E':
            cout << "backing to the menu..." << endl;
            break;
        default:
            if(!vehicles.empty() && vehicles[vehicles.size() - 1] != nullptr)
                return true;
            else
                return false;
    }

}

void VehicleArrayService::displayAll(){
    for (auto &v : vehicles){
        v->displayInfo();
        cout << "----------------------------------" << endl;
    }
    cout << "Total Vehicles stored : " << vehicles.size() << endl;
    cout << "----------------------------------" << endl;
}

void VehicleArrayService::countAllType(){
    int bikeCount =0, carCount=0;
    for (auto &v : vehicles){
        //? v.get() is used for getting the actual className 
        if(dynamic_cast<Car*>(v.get())) carCount++;
    }
    bikeCount = vehicles.size() - carCount;
    cout << "Total Bikes are : " << bikeCount << endl;
    cout << "Total Cars are : " << carCount << endl;
    cout << "----------------------------------" << endl;
}

void VehicleArrayService::displayByType(){
    char vehicleTypeInput;
    bool status = false; 
    do{
        cout << "Enter type of vehicle (C for Car, B for Bike, E for Back to Menu): ";
        try{
            cin >> vehicleTypeInput;
            if(vehicleTypeInput != 'C' && vehicleTypeInput != 'B' && vehicleTypeInput != 'E'){
                throw runtime_error("Invalid vehicle type. Please enter 'C' for Car or 'B' for Bike or 'E' for Back");
            }
            else
                break;
        }
        catch(runtime_error &e){
            cerr << "Error: " << e.what() << endl;
        }
    } while (vehicleTypeInput != 'E' || vehicleTypeInput != 'C' || vehicleTypeInput != 'B');
    cin.ignore();

    switch(vehicleTypeInput){
        case 'B':
            displayInfoAsPerType(VehicleType::BIKE);
            break;
        case 'C':
            displayInfoAsPerType(VehicleType::CAR);
            break;
        case 'E':
            cout << "backing to the menu..." << endl;
            break;
        default:
            cout << "Exiting this menu... of display vehicle by type" << endl;
            cout << "--------------------------------------------------" << endl;
    }

}

void VehicleArrayService::loadDataFromFile(){
    cout << "reading data from file..." << endl;
    bool status = readData("./storage/mydata.text", vehicles);
    cout << (status ? "Loaded Data" : "Failed to load data") << endl;
}


void VehicleArrayService::saveDataToFile(){
    cout << "writing data to file..." << endl;
    bool status = writeData("./storage/mydata.text", vehicles);
    cout << (status ? "Data saved " : "Failed to save data") << endl;
}

void VehicleArrayService::displayInfoAsPerType(VehicleType vt){
    switch(vt){
        case VehicleType::BIKE:
            for (auto &it : vehicles){
                if (dynamic_cast<Bike *>(it.get())) it->displayInfo();
            }   
            break;
        case VehicleType::CAR:
            for (auto &it : vehicles){
                if (dynamic_cast<Car *>(it.get())) it->displayInfo();
            }   
            break;
        default:
            cout << "-----------------------------------" << endl;
            return;
    }
      
}