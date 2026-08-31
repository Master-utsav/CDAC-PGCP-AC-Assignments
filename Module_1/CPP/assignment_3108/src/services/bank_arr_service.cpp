#include "bank_arr_service.h"
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ACCOUNTS = 100; 
Bank* bankArr[MAX_ACCOUNTS]; // array of Bank pointers to store different types of accounts

BankArrService::BankArrService() {
    // Initialize the bankArr with nullptrs
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        bankArr[i] = nullptr;
    }
}
void BankArrService::addNewAccount() {
    // Logic to add a new account
    int choice;
    Bank *newAccount = nullptr;
    char fname[50], lname[50], email[50];
    char *fnameptr;
    char *lnameptr;
    char *emailptr;
    long long int mob;
    int pin;
    double balance;

    cout << "Enter first name: ";
    cin >> fname;
    fnameptr = new char[strlen(fname) + 1];
    strcpy(fnameptr, fname);
    cout << "Enter last name: ";
    cin >> lname;
    lnameptr = new char[strlen(lname) + 1];
    strcpy(lnameptr, lname);
    cout << "Enter mobile number: ";
    cin >> mob;
    cout << "Enter email: ";
    cin >> email;
    emailptr = new char[strlen(email) + 1];
    strcpy(emailptr, email);
    cout << "Enter pin: ";
    cin >> pin;
    cout << "Enter initial balance: ";
    cin >> balance;

    cout << "Select account type to add: " << endl;
    cout << "1. Saving Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "3. Demat Account" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            newAccount = new SavingAcc(fnameptr, lnameptr, mob, emailptr, pin, balance);
            break;
        case 2:
            newAccount = new CurrentAcc(fnameptr, lnameptr, mob, emailptr, pin, balance);
            break;
        case 3:
            newAccount = new DematAcc(fnameptr, lnameptr, mob, emailptr, pin, balance);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    if (newAccount) {
        for (int i = 0; i < MAX_ACCOUNTS; ++i) {
            if (bankArr[i] == nullptr) {
                bankArr[i] = newAccount;
                newAccount->display();
                break;
            }
        }
    }
}
void BankArrService::displayAccountBalanceById() {
    // Implementation for displaying account balance by ID
    long int accNo;
    cout << "Enter account number: ";
    cin >> accNo;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            bankArr[i]->display();
            return;
        }
    }
    cout << "Account not found." << endl;
}
void BankArrService::closeAccount() {
    // Implementation for closing an account
    long int accNo;
    cout << "Enter account number to close: ";
    cin >> accNo;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            bankArr[i]->setIsAccountClosed(true);
            cout << "Account closed successfully." << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}


void BankArrService::countTypeOfAccount() {
    // Implementation for counting types of accounts
    int savingCount = 0, currentCount = 0, dematCount = 0;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr) {
            if (dynamic_cast<SavingAcc*>(bankArr[i])) {
                savingCount++;
            } else if (dynamic_cast<CurrentAcc*>(bankArr[i])) {
                currentCount++;
            } else if (dynamic_cast<DematAcc*>(bankArr[i])) {
                dematCount++;
            }
        }
    }
    cout << "Saving Accounts: " << savingCount << endl;
    cout << "Current Accounts: " << currentCount << endl;
    cout << "Demat Accounts: " << dematCount << endl;
}

void BankArrService::withdrawAmount() {
    // Implementation for withdrawing amount
    long int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            bankArr[i]->fxnWithdrawAmount(amount);
            return;
        }
    }
    cout << "Account not found." << endl;
}
void BankArrService::depositAmount() {
    // Implementation for depositing amount
    long int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            bankArr[i]->fxnDepositAmount(amount);
            return;
        }
    }
    cout << "Account not found." << endl;
}
void BankArrService::changePin() {
    // Implementation for changing PIN
    long int accNo;
    int oldPin, newPin;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter old PIN: ";
    cin >> oldPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            bankArr[i]->setPin(oldPin, newPin);
            return;
        }
    }
    cout << "Account not found." << endl;
}

void BankArrService::dmatAccountLogin() {
    // Implementation for Demat account login
    long int accNo;
    cout << "Enter Demat account number: ";
    cin >> accNo;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (bankArr[i] != nullptr && bankArr[i]->getAccNo() == accNo) {
            DematAcc* dematAcc = dynamic_cast<DematAcc*>(bankArr[i]);
            if (dematAcc) {
                // Logic for Demat account operations
                cout << "Demat Account Login Successful." << endl;
                dematAcc->display();

                int choice;
                do {
                    cout << "1. Add Share" << endl;
                    cout << "2. Display Shares" << endl;
                    cout << "3. sell Share" << endl;
                    cout << "4. Display Profit" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch(choice) {
                        case 1: {
                            char shareName[50];
                            char *shareNameptr;
                            int shareCount, dateOfPurchase;
                            double perSharePrice;

                            cout << "Enter share name: ";
                            cin >> shareName;
                            shareNameptr = new char[strlen(shareName) + 1];
                            strcpy(shareNameptr, shareName);

                            cout << "Enter number of shares: ";
                            cin >> shareCount;
                            cout << "Enter price per share: ";
                            cin >> perSharePrice;
                            cout << "Enter date of purchase (YYYYMMDD): ";
                            cin >> dateOfPurchase;
                            dematAcc->setShare(shareName, shareCount, perSharePrice, dateOfPurchase);
                            break;
                        }
                        case 2:
                            dematAcc->display();
                            break;
                        case 3:
                            // Implementation for selling shares
                            int shareId;
                            double sellingPrice;
                            int dateOfSelling;
                            cout << "Enter share ID: ";
                            cin >> shareId;
                            cout << "Enter selling price: ";
                            cin >> sellingPrice;
                            cout << "Enter date of selling (DDMMYYYY): ";
                            cin >> dateOfSelling;
                            dematAcc->sellShare(shareId, sellingPrice, dateOfSelling);
                            dematAcc->displayProfit(shareId);
                            break;
                        case 4:
                            dematAcc->getBalance();
                            break;
                        case 0:
                            cout << "Logging out..." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 0);
            } else {
                cout << "This is not a Demat account." << endl;
                return;
            }
        }
    }
    cout << "Account not found." << endl;
}

BankArrService::~BankArrService() {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        delete bankArr[i];
    }
}

