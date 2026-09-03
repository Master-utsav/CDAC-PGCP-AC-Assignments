#include "VehicleArrayService.h"
#include <iostream>
#include <string>

using namespace std;

extern bool isValidFuelType(FuelType ft);
extern bool readData(const char *fileName, Vehicle **v, int &count);
extern bool writeData(const char *fileName, Vehicle **v, int count);

// template<typename T>
// extern bool isValidYear(T year);

extern bool isValidYear(const string& year);
extern bool isValidYear(int year);

// const int VehicleArrayService::MAX_VEHICLES = 100;
Vehicle* VehicleArrayService::vehicles[MAX_VEHICLES];
int VehicleArrayService::vehicleCount = 0;

bool VehicleArrayService::addVehicle() {
    if (vehicleCount >= MAX_VEHICLES) {
        cout << "Vehicle array is full. Cannot add more vehicles." << endl;
        return false;
    }
    
    // setting the char vehicleType
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

    Vehicle *v = nullptr;
    int engineCap;
    int fuelChoice;

    switch (vehicleTypeInput){
        case 'B':
            cout << "Enter the engine capacity : ";
            cin >> engineCap;
            v = new Bike(modelName, manufacturerName, yearOfManufacture, engineCap);
            vehicles[vehicleCount++] = v;
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
                    v = new Car(modelName, manufacturerName, yearOfManufacture, ft);
                    vehicles[vehicleCount++] = v;
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
            if(vehicleCount > 0 && vehicles[vehicleCount - 1] != nullptr)
                return true;
            else
                return false;
    }

}

void VehicleArrayService::displayAll(){
    for (int i = 0; i < vehicleCount; i++){
        vehicles[i]->displayInfo();
        cout << "----------------------------------" << endl;
    }
    cout << "Total Vehicles stored : " << vehicleCount << endl;
    cout << "----------------------------------" << endl;
}

void VehicleArrayService::countAllType(){
    int bikeCount =0, carCount=0;
    for (int i = 0; i < vehicleCount; i++){
        if(dynamic_cast<Car*>(vehicles[i]))
            carCount++;
    }
    bikeCount = vehicleCount - carCount;
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
            for (int i = 0; i < vehicleCount; i++){
                if (dynamic_cast<Bike *>(vehicles[i])){
                    vehicles[i]->displayInfo();
                    cout << "-----------------------------------";
                }
            }
            break;
        case 'C':
            for (int i = 0; i < vehicleCount; i++){
                if (dynamic_cast<Car *>(vehicles[i])){
                    vehicles[i]->displayInfo();
                    cout << "-----------------------------------";
                }
            }
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
    bool status = readData("./storage/mydata.text", vehicles, vehicleCount);
    cout << (status ? "Loaded Data" : "Failed to load data") << endl;
}


void VehicleArrayService::saveDataToFile(){
    cout << "writing data to file..." << endl;
    bool status = writeData("./storage/mydata.text", vehicles, vehicleCount);
    cout << (status ? "Data saved " : "Failed to save data") << endl;
}

