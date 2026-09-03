#include <iostream>
#include <Vehicle.h>
#include <Car.h>
#include <Truck.h>
#include <string>

using namespace std;

// Enter type of Vehicle (C for Car, T for Truck): T
// Enter parking hours: 5
// Enter discount code if available (or press Enter to skip): TRUCK50

int main(){
    char choice;
    double duration;
    string couponName;
    Vehicle *v = nullptr;
    do{
      cout << "Enter type of Vehicle (C for Car, T for Truck , E for Exit): ";
      cin.get(choice);
      
      switch (choice){
        case 'C':
            cout << "Enter the parking hours : ";
            cin >> duration;
            cin.ignore();
            cout << "Enter discount code if available (or press Enter to skip): ";
            getline(cin, couponName);
            v = new Car(duration);
            v->display();
            cout << endl << "--------------Reciept info-------------" << endl << endl;
            v->displayCal(couponName);
            break;
        case 'T':
            cout << "Enter the parking hours : ";
            cin >> duration;
            cin.ignore();
            cout << "Enter discount code if available (or press Enter to skip): ";
            getline(cin, couponName);
            v = new Truck(duration);
            v->display();
            cout << "--------------Reciept info-------------" << endl;
            v->displayCal(couponName);
            break;
        case 'E':
            cout << "Thankyou for visiting...\n";
            break;
        default:
            cout << "Wrong Input Exiting the program\n";
      }
    }while(choice != 'E');

    delete v;

    return 0;
}