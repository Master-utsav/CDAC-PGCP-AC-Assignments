#include <iostream>
#include "bank_arr_service.h"

using namespace std;

int main(){
    int choice;
    do {
        cout << "------------------------------" << endl;
        cout << "1. Add new account" << endl;
        cout << "2. Display account balance by id" << endl;
        cout << "3. Close account" << endl;
        cout << "4. Count a type of account" << endl;
        cout << "5. Withdraw amount" << endl;
        cout << "6. Deposit amount" << endl;
        cout << "7. Change pin" << endl;
        cout << "8. Demat Account Login" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "------------------------------" << endl;
        switch(choice){
            case 1:
                BankArrService::addNewAccount();
                break;
            case 2:
                BankArrService::displayAccountBalanceById();
                break;
            case 3:
                BankArrService::closeAccount();
                break;
            case 4:
                BankArrService::countTypeOfAccount();
                break;
            case 5:
                BankArrService::withdrawAmount();
                break;
            case 6:
                BankArrService::depositAmount();
                break;
            case 7:
                BankArrService::changePin();
                break;
            case 8:
                BankArrService::dmatAccountLogin();
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;    
        }
    } while (choice != 0);

    return 0;
}