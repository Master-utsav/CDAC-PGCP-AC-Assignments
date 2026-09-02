#include "Person.h"
#include<iostream>
#include<cstring>

using namespace std;

int Person::nextId = 1;
int Person::addressCount = 0;

Person::Person() : name(nullptr), age(0), id(nextId++) {
}
Person::Person(const char *name, int age) : age(age), id(nextId++) {
    setName(name);
}
Person::~Person() {
    delete[] name; 
}

void Person::setName(const char *name) {
    delete[] this->name;
    if (name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    } else {
        this->name = nullptr;
    }
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setAddress(Address **address) {
    if (addressCount < 10) {
        this->address[addressCount++] = *address;
    } else {
        cout << "Maximum address limit reached for this person." << endl;
    }
}

void Person::display() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << (name ? name : "guest") << endl;
    cout << "Age: " << age << endl;
    cout << "Address: ";
    for (int i = 0; i < addressCount; i++) {
        if (this->address[i]) {
            cout << this->address[i]->getStreet() << "," 
                 << this->address[i]->getCity() << ", " 
                 << this->address[i]->getState() << ", " 
                 << this->address[i]->getPin() << endl;
        }
        else
            break;
    }
}

const char* Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

Address* Person::getAddress() const {
    return address[0]; // Returning the first address, if it exists
}

int Person::getId() const {
    return id;
}