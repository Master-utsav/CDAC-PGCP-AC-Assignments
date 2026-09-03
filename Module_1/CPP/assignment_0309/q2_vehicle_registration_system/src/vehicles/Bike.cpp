#include <iostream>
#include <string>
#include "Bike2.h"

using namespace std;

Bike::Bike(const string &modelName, const string &manufacturerName, int yearOfManufacture, int engineCapacity)
    : Vehicle(modelName, manufacturerName, yearOfManufacture), engineCapacity(engineCapacity){
    type = VehicleType::BIKE;
    string regNum = "MH" + to_string(yearOfManufacture) + "BIKE" + to_string(getNextId());
    setRegistrationNumber(regNum);
    setNextId();
}

// RegNo: MH20XY5678, Model: Pulsar, Manufacturer: Bajaj, Year: 2020, EngineCapacity: 150cc
void Bike::displayInfo() {
    cout << "Vehicle Type: Bike" << ", "
         << "RegNo: " << getRegistrationNumber() << ", "
         << "Model: " << modelName << ", "
         << "Manufacturer: " << manufacturerName << ", "
         << "Year: " << yearOfManufacture << ", "
         << "EngineCapacity: " << engineCapacity << "cc" << endl;
    cout << "----------------------------------------" << endl;
}


void Bike::serialize(ostream& os) const {
 try {
        // Write type as string
        // string typeStr = "BIKE";
        // int len = typeStr.length();
        // os.write(reinterpret_cast<char *>(&len), sizeof(len));
        // os.write(typeStr.c_str(), len);

        
        // ! this line suffient for enums
        os.write(reinterpret_cast<const char *>(&type), sizeof(type));

        // Write registration number
        int len = getRegistrationNumber().length();
        os.write(reinterpret_cast<char*>(&len), sizeof(len));
        os.write(getRegistrationNumber().c_str(), len);

        // Write model name
        len = modelName.length();
        os.write(reinterpret_cast<char*>(&len), sizeof(len));
        os.write(modelName.c_str(), len);

        // Write manufacturer name
        len = manufacturerName.length();
        os.write(reinterpret_cast<char*>(&len), sizeof(len));
        os.write(manufacturerName.c_str(), len);

        // Write year
        os.write(reinterpret_cast<const char*>(&yearOfManufacture), sizeof(yearOfManufacture));

        // Write engine capacity
        os.write(reinterpret_cast<const char*>(&engineCapacity), sizeof(engineCapacity));

        if (!os) {
            throw runtime_error("Serialization failed");
        }
    } catch (const exception& e) {
        throw runtime_error(string("Bike serialization failed: ") + e.what());
    }
}

void Bike::deserialize(istream& is) {
     try {
        int len;

        // Read and validate type
        // is.read(reinterpret_cast<char*>(&len), sizeof(len));
        // if (!is || len <= 0 || len > 100) throw runtime_error("Invalid type length");
        
        // string typeStr(len, '\0');
        // is.read(&typeStr[0], len);
        // if (!is) throw runtime_error("Failed to read type");
        
        // if (typeStr != "BIKE") {
        //     throw runtime_error("Invalid type: expected BIKE, got " + typeStr);
        // }
        // cout << "Type is: BIKE" << endl;
        type = VehicleType::BIKE;

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

        // Read engine capacity
        is.read(reinterpret_cast<char*>(&engineCapacity), sizeof(engineCapacity));
        if (!is) throw runtime_error("Failed to read engineCapacity");
        this->engineCapacity = engineCapacity;

    } catch (const exception& e) {
        throw runtime_error(string("Bike deserialization failed: ") + e.what());
    }
}


Bike::~Bike(){};