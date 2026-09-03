#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "Car2.h"

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
    
     // Write type as string
    // string typeStr;
    // int len = typeStr.length();
    // os.write(reinterpret_cast<char*>(&len), sizeof(len));
    // os.write(typeStr.c_str(), len);

     // ! this line suffient for enums
     os.write(reinterpret_cast<const char *>(&type), sizeof(type));

     // Write registration number
     int len = getRegistrationNumber().length();
     os.write(reinterpret_cast<char *>(&len), sizeof(len));
     os.write(getRegistrationNumber().c_str(), len);

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

     // Write fuel type as string
    //  string fuelTypeStr = fuelTypeToString(fuelType);
    //  len = fuelTypeStr.length();
    //  os.write(reinterpret_cast<char *>(&len), sizeof(len));
    //  os.write(fuelTypeStr.c_str(), len);

     // ! this line suffient for enums
     os.write(reinterpret_cast<const char *>(&fuelType), sizeof(fuelType));

     if (!os){
         throw runtime_error("Serialization failed");
     }
}

void Car::deserialize(istream& is) {
    try {
        int len;

        // Read and validate type
        // is.read(reinterpret_cast<char*>(&len), sizeof(len));
        // if (!is || len <= 0 || len > 100) throw runtime_error("Invalid type length");
        
        // string typeStr(len, '\0');
        // is.read(&typeStr[0], len);
        // if (!is) throw runtime_error("Failed to read type");
        
        // if (typeStr != "CAR") {
        //     throw runtime_error("Invalid type: expected CAR, got " + typeStr);
        // }
        // cout << "Type is: CAR" << endl;
        type = VehicleType::CAR;

        // Read registration number
        is.read(reinterpret_cast<char*>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100) throw runtime_error("Invalid regNum length");
        
        string regNum(len, '\0');
        is.read(&regNum[0], len);
        if (!is) throw runtime_error("Failed to read regNum");
        setRegistrationNumber(regNum);

        // Read model name
        is.read(reinterpret_cast<char*>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100) throw runtime_error("Invalid modelName length");
        
        string modelName(len, '\0');
        is.read(&modelName[0], len);
        if (!is) throw runtime_error("Failed to read modelName");
        this->modelName = modelName;

        // Read manufacturer name
        is.read(reinterpret_cast<char*>(&len), sizeof(len));
        if (!is || len <= 0 || len > 100) throw runtime_error("Invalid manufacturerName length");
        
        string manufacturerName(len, '\0');
        is.read(&manufacturerName[0], len);
        if (!is) throw runtime_error("Failed to read manufacturerName");
        this->manufacturerName = manufacturerName;

        // Read year
        is.read(reinterpret_cast<char*>(&yearOfManufacture), sizeof(yearOfManufacture));
        if (!is) throw runtime_error("Failed to read yearOfManufacture");
        this->yearOfManufacture = yearOfManufacture;

        // Read and convert fuel type from string
        // is.read(reinterpret_cast<char*>(&len), sizeof(len));
        // if (!is || len <= 0 || len > 100) throw runtime_error("Invalid fuelType length");
        
        // string fuelTypeStr(len, '\0');
        // is.read(&fuelTypeStr[0], len);
        // if (!is) throw runtime_error("Failed to read fuelType");
        
        // fuelType = stringToFuelType(fuelTypeStr);
        // if (!isValidFuelType(fuelType)) {
        //     throw runtime_error("Invalid fuel type: " + fuelTypeStr);
        // }

        //! ALL you have to do is this below for enums no string store required
        is.read(reinterpret_cast<char *>(&fuelType), sizeof(fuelType));
        if (!is) throw runtime_error("Failed to read fuelType");
        this->fuelType = fuelType;

    } catch (const exception& e) {
        throw runtime_error(string("Car deserialization failed: ") + e.what());
    }
}

Car::~Car(){};