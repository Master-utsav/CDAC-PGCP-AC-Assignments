#include "Address.h"
#include <cstring>

Address::Address() : street(nullptr), city(nullptr), state(nullptr), pin(0) {}
Address::Address(const char *street, const char *city, const char *state, int pin) : pin(pin) {
    setStreet(street);
    setCity(city);
    setState(state);
}

Address::~Address() {
    delete[] street;
    delete[] city;
    delete[] state;
}

void Address::setStreet(const char *street) {
    delete[] this->street;
    if (street) {
        this->street = new char[strlen(street) + 1];
        strcpy(this->street, street);
    } else {
        this->street = nullptr;
    }
}

void Address::setCity(const char *city) {
    delete[] this->city;
    if (city) {
        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);
    } else {
        this->city = nullptr;
    }
}

void Address::setState(const char *state) {
    delete[] this->state;
    if (state) {
        this->state = new char[strlen(state) + 1];
        strcpy(this->state, state);
    } else {
        this->state = nullptr;
    }
}

void Address::setPin(int pin) {
    this->pin = pin;
}

const char* Address::getStreet() const {
    return street;
}

const char* Address::getCity() const {
    return city;
}

const char* Address::getState() const {
    return state;
}

int Address::getPin() const {
    return pin;
}

