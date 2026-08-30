#include <iostream>
#include "booking.h"

using namespace std;

int main(){
     Booking b1, b2;
    cout << "Enter the data for first booking : " << endl;
    cin >> b1;
    cout << "Enter the data for second booking : " << endl;
    cin >> b2;
    cout << b1 << b2;
     
    
      //  double calculateFair();
    cout << "------------------calculateFair()----------" << endl;
    double b1Fair = b1.calculateFair();
    cout << "Booking default fair charges for : " << endl
         << b1 << "is : " << fixed << b1Fair << endl;


    // double calculateFair(int mode, int vehicle);
    cout << "------------------calculateFair(int mode, int vehicle)----------" << endl;
    int mode, vehicle = 1;
    cout << "enter mode ( 1 for land | 2 for water | 3 for air ) : ";
    cin >> mode;
    if (mode == 1){
      cout << "enter vehicle (1 for two-wheeler and 2 for 4-wheeler ) : ";
      cin >> vehicle;
    }
    double b1Fair2 = b1.calculateFair(mode, vehicle);
    cout << "Booking charges for using vehicle : " << endl
          << b1 << "is : " << fixed << b1Fair2 << endl;
       
 
    //   double calculateFair(int mode, int vehicle, int noOfPassenger);
      cout << "------------------calculateFair(int mode, int vehicle, int noOfPassenger)----------" << endl;
      int noOfPassenger = 1;
      cout << "enter mode ( 1 for land | 2 for water | 3 for air ) : ";
      cin >> mode;
      if(mode == 1){
        cout << "enter vehicle (1 for two-wheeler and 2 for 4-wheeler ) : ";
        cin >> vehicle;
      }
      cout << "enter number of passenger : ";
      cin >> noOfPassenger;
      double b1Fair3 = b1.calculateFair(mode, vehicle, noOfPassenger);
      cout << "Booking charges as per vhicle and no. of passengers : " << endl
           << b1 << "is : " << fixed << b1Fair3 << endl;
      

      //  double calculateFair(bool isPremium, int additionalCharge);
      cout << "------------------calculateFair(bool isPremium, int additionalCharge)----------" << endl;
      bool isPremium = false;
      int additionalCharge = 0;
      cout << "Enter (0 if not Premium or 1 for Premium) : ";
      cin >> isPremium;
      cout << "Enter the additionalCharge: ";
      cin >> additionalCharge;
      double b1Fair4 = b1.calculateFair(isPremium, additionalCharge);
      cout << "Booking charges for Premium as per additionalCharges : " << endl
           << b1 << "is : " << fixed << b1Fair4 << endl;
      
    return 0;
}