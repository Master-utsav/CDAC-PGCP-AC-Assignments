#include <iostream>
#include"Vehicle3.h"
#include <string>

using namespace std;

int Vehicle::nextId = 1;
Vehicle::Vehicle(const string &modelName, const string &manufacturerName, int yearOfManufacture)
    : modelName(modelName), manufacturerName(manufacturerName), yearOfManufacture(yearOfManufacture) {}
