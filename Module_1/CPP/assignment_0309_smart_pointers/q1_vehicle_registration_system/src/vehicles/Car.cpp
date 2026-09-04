#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "Car3.h"

using namespace std;

extern bool isValidFuelType(FuelType ft);
//?? no need now since we direclty use the nums to file store
// extern string fuelTypeToString(FuelType ft);
// extern FuelType stringToFuelType(const string& ft);

Car::Car(const string &modelName, const string &manufacturerName, int yearOfManufacture, FuelType fuelType)
    : Vehicle(modelName, manufacturerName, yearOfManufacture), fuelType(fuelType){
    type = VehicleType::CAR;
    string regNum = "MH" + to_string(yearOfManufacture) + "CAR" + to_string(getNextId());
    setRegistrationNumber(regNum);
    setNextId();
}

// RegNo: MH20AB1234, Model: Swift, Manufacturer: Maruti, Year: 2018, FuelType: Petrol
void Car::displayInfo() {
    cout << "Vehicle Type: Car" << ", "
         << "RegNo: " << getRegistrationNumber() << ", "
         << "Model: " << modelName << ", "
         << "Manufacturer: " << manufacturerName << ", "
         << "Year: " << yearOfManufacture << ", "
         << "FuelType: ";
    switch (fuelType) {
        case FuelType::PETROL:
            cout << "Petrol";
            break;
        case FuelType::DIESEL:
            cout << "Diesel";
            break;
        case FuelType::ELECTRIC:
            cout << "Electric";
            break;
        case FuelType::CNG:
            cout << "CNG";
            break;
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
}

void Car::serialize(ostream& os) const {
     // ! this line suffient for enums
     os.write(reinterpret_cast<const char *>(&type), sizeof(type));

     // Write registration number
     string regNum = getRegistrationNumber();
     int len = regNum.length();
     os.write(reinterpret_cast<char *>(&len), sizeof(len));
     os.write(regNum.c_str(), len);

     // Write model name
     len = modelName.length();
     os.write(reinterpret_cast<char *>(&len), sizeof(len));
     os.write(modelName.c_str(), len);

     // Write manufacturer name
     len = manufacturerName.length();
     os.write(reinterpret_cast<char *>(&len), sizeof(len));
     os.write(manufacturerName.c_str(), len);

     // Write year
     os.write(reinterpret_cast<const char *>(&yearOfManufacture), sizeof(yearOfManufacture));

     // ! this line suffient for enums
     os.write(reinterpret_cast<const char *>(&fuelType), sizeof(fuelType));

     if (!os){
         throw runtime_error("Serialization failed");
     }
}

void Car::deserialize(istream& is) {
    try {
        int len;
        type = VehicleType::CAR;

        // Read registration number
         //? Read registration number -> this also not works since we first have to read the string len then the contains of it till the null terminator -> '\0'
        //! string regNum;
        //! is.read(reinterpret_cast<char *>(&regNum), sizeof(regNum));
        is.read(reinterpret_cast<char *>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100) throw runtime_error("Invalid regNum length");
        string regNum(len, '\0');
        // you dont have to do that beacuse its store the address any way so just extract it by using the is.read[&modelName[0], len];
        // is.read(reinterpret_cast<char *>(&regNum), sizeof(regNum));
        is.read(&regNum[0], len);
        if (!is) throw runtime_error("Failed to read regNum");
        setRegistrationNumber(regNum);

        // Read model name
        // is.read(reinterpret_cast<char*>(&modelName), sizeof(modelName));
        // if (!is) throw runtime_error("Failed to read regNum");

        is.read(reinterpret_cast<char *>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100)
            throw runtime_error("Invalid  modelName length");
        string modelName(len, '\0');
        is.read(&modelName[0], len);
        if (!is) throw runtime_error("Failed to read modelName");
        this->modelName = modelName;

        // Read manufacturer name
        // is.read(reinterpret_cast<char *>(&manufacturerName), sizeof(manufacturerName));
        // if (!is) throw runtime_error("Failed to read manufacturerName");
        is.read(reinterpret_cast<char *>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100) throw runtime_error("Invalid  manufacturerName length");
        string manufacturerName(len, '\0');
        is.read(&manufacturerName[0], len);
        if (!is) throw runtime_error("Failed to read regNum");
        this->manufacturerName = manufacturerName;

        // Read year
        is.read(reinterpret_cast<char*>(&yearOfManufacture), sizeof(yearOfManufacture));
        if (!is) throw runtime_error("Failed to read yearOfManufacture");
        this->yearOfManufacture = yearOfManufacture;

        //! ALL you have to do is this below for enums no string store required
        is.read(reinterpret_cast<char *>(&fuelType), sizeof(fuelType));
        if (!is) throw runtime_error("Failed to read fuelType");
        this->fuelType = fuelType;

    } 
    catch (const exception& e) {
        throw runtime_error(string("Car deserialization failed: ") + e.what());
    }
}