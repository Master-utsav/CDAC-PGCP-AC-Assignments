#include <iostream>
#include <cstring>
#include "ArrayService.h"

using namespace std;

int ArrayService::personCount = 0;
Person *ArrayService::persons[ArrayService::maxCount];

void ArrayService::addPerson() {
    if (personCount >= maxCount) {
        cout << "Cannot add more persons. Maximum limit reached." << endl;
        return;
    }

    char name[100];
    char *nm;
    int age;

    cout << "Enter name: ";
    cin >> name;
    nm = new char[strlen(name) + 1];
    strcpy(nm, name);

    cout << "Enter age: ";
    cin >> age;

    persons[personCount++] = new Person(nm, age);
    cout << "Person added successfully." << endl;
}

/*
        static void findAddressById();
        static void displayPersonsInCity();
*/

void ArrayService::addAddressToPerson() {
    int id;
    cout << "Enter Person ID to add address : ";
    cin >> id;

    for (int i = 0; i < personCount; ++i) {
        if (persons[i]->getId() == id) {
            char street[100], city[100], state[100];
            char *st, *ct, *stt;
            int pin;

            cout << "Enter street: ";
            cin >> street;
            st = new char[strlen(street) + 1];
            strcpy(st, street);

            cout << "Enter city: ";
            cin >> city;
            ct = new char[strlen(city) + 1];
            strcpy(ct, city);

            cout << "Enter state: ";
            cin >> state;
            stt = new char[strlen(state) + 1];
            strcpy(stt, state);

            cout << "Enter pin: ";
            cin >> pin;

            Address *address = new Address(street, city, state, pin);
            Address *addressPtr = address;
            persons[i]->setAddress(&addressPtr);
            cout << "Address added successfully...." << endl;
            return;
        }
    }
    cout << "Person with ID " << id << " not found." << endl;
}

void ArrayService::displayAllPersons() {
    if (personCount == 0) {
        cout << "No persons to display." << endl;
        return;
    }

    for (int i = 0; i < personCount; ++i) {
        persons[i]->display();
        cout << "------------------------" << endl;
    }
}

void ArrayService::searchById() {
    int id;
    cout << "Enter Person ID to search: ";
    cin >> id;

    for (int i = 0; i < personCount; ++i) {
        if (persons[i]->getId() == id) {
            persons[i]->display();
            // return persons[i];
        }
    }
    // cout << "Person with ID " << id << " not found." << endl;
    // return nullptr;
}

void ArrayService::searchByName() {
    char name[100];
    cout << "Enter Person name to search: ";
    cin >> name;

    for (int i = 0; i < personCount; ++i) {
        if (strcmp(persons[i]->getName(), name) == 0) {
            persons[i]->display();
            // return persons[i];
        }
    }
    // cout << "Person with name " << name << " not found." << endl;
    // return nullptr;
}

bool ArrayService::modifyAddress() {
    int id;
    cout << "Enter Person ID to modify address: ";
    cin >> id;

    for (int i = 0; i < personCount; ++i) {
        if (persons[i]->getId() == id) {
            char street[100], city[100], state[100];
            char *st, *ct, *stt;
            int pin;

            cout << "Enter new street: ";
            cin >> street;
            st = new char[strlen(street) + 1];
            strcpy(st, street);

            cout << "Enter new city: ";
            cin >> city;
            ct = new char[strlen(city) + 1];
            strcpy(ct, city);

            cout << "Enter new state: ";
            cin >> state;
            stt = new char[strlen(state) + 1];
            strcpy(stt, state);

            cout << "Enter new pin: ";
            cin >> pin;

            Address *address = new Address(street, city, state, pin);
            Address *addressPtr = address;
            persons[i]->setAddress(&addressPtr);
            cout << "Address modified successfully." << endl;
            return true;
        }
    }
    cout << "Person with ID " << id << " not found." << endl;
    return false;
}

Address* ArrayService::findAddressById() {
    int id;
    cout << "Enter Person ID to find address: ";
    cin >> id;

    for (int i = 0; i < personCount; ++i) {
        if (persons[i]->getId() == id) {
            cout << "Address for Person ID " << id << ":" << endl;
            Address *address = persons[i]->getAddress();
            if (address) {
                cout << "Street: " << address->getStreet() << endl;
                cout << "City: " << address->getCity() << endl;
                cout << "State: " << address->getState() << endl;
                cout << "Pin: " << address->getPin() << endl;
            } else {
                cout << "No address found for this person." << endl;
            }
            return persons[i]->getAddress();
        }
    }
    cout << "Person with ID " << id << " not found." << endl;
    return nullptr;
}

void ArrayService::displayPersonsInCity() {
    char city[100];
    cout << "Enter city to display persons: ";
    cin >> city;

    bool found = false;
    for (int i = 0; i < personCount; ++i) {
        Address *address = persons[i]->getAddress();
        if (address && strcmp(address->getCity(), city) == 0) {
            persons[i]->display();
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No persons found in city " << city << "." << endl;
    }
}

