#include <iostream>
#include "VehicleArrayService3.h"
using namespace std;

int main(){
    int choice; bool status = false;
    VehicleArrayService::loadDataFromFile();

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
            cout << "Thankyou for visiting...\n";
            break;
        default:
            cout << "Wrong Input Exiting the program without saving Data\n";
      }
    } while(choice != 5);
    return 0;
}