#include <iostream>
#include "VehicleArrayService.h"

using namespace std;

// Enter type of vehicle (C for Car, B for Bike): C
// Enter Registration Number: MH20AB1234 //! NOT REQUIRED
// Enter Model Name: Swift
// Enter Manufacturer: Maruti
// Enter Year: 2018 
// Enter Fuel Type: Petrol

int main(){
    int choice;
    bool status = false;
    VehicleArrayService::loadDataFromFile();
    // cout << "Data loaded from file : " << (status ? "Success" : "Failure") << endl;

    do{
        cout << "1. Add Vehicle\n2. Display All\n3. Display As per Type\n4. Count Of Vehicles\n5. Save and Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice){
        case 1:
            status = VehicleArrayService::addVehicle();
            cout << "Vehicle added : " << (status ? "Success" : "Failure") << endl;
            break;
        case 2:
            VehicleArrayService::displayAll();
            break;
        case 3:
            VehicleArrayService::displayByType();
            break;
        case 4:
            VehicleArrayService::countAllType();
            break;
        case 5:
        cout << "Saving data to file..." << endl;
            VehicleArrayService::saveDataToFile();
            // status ? cout << "Data saved successfully." << endl : cout << "Data saving failed." << endl;
            cout << "Thankyou for visiting...\n";
            break;
        default:
            cout << "Wrong Input Exiting the program without saving Data\n";
      }

    } while(choice != 5);

    return 0;
}