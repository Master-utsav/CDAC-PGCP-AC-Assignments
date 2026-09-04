#include <iostream>
#include <string>
#include "Bike3.h"

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
        // ! this line suffient for enums
        os.write(reinterpret_cast<const char *>(&type), sizeof(type));

        //? Write registration number -> this will not work since its a string you have to figure out the length first then you have to create a buffer then .c_str till len to completetly wirte the string into it
        //! os.write(reinterpret_cast<const char *>(&regNum), sizeof(regNum));
        int len = getRegistrationNumber().length();
        os.write(reinterpret_cast<char *>(&len), sizeof(len));
        // read the char by char till the length
        os.write(getRegistrationNumber().c_str() , len);

        //? Write model name -> similary for the remaing string you have to do this again and again first write the length then the str contains as per the len you write
        len = modelName.length();
        os.write(reinterpret_cast<char *>(&len), sizeof(len));
        os.write(modelName.c_str(), len);
        // os.write(reinterpret_cast<const char *>(&modelName), sizeof(modelName));

        // Write manufacturer name
        len = manufacturerName.length();
        os.write(reinterpret_cast<char *>(&len), sizeof(len));
        os.write(manufacturerName.c_str(), len);
        // os.write(reinterpret_cast<const char *>(&manufacturerName), sizeof(manufacturerName));

        // Write yearm -> this will work because its an integer but for string which is actually a char* you have to specify the len first  
        os.write(reinterpret_cast<const char *>(&yearOfManufacture), sizeof(yearOfManufacture));

        // Write engine capacity -> same as above
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

        type = VehicleType::BIKE;

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

        // Read engine capacity
        is.read(reinterpret_cast<char*>(&engineCapacity), sizeof(engineCapacity));
        if (!is) throw runtime_error("Failed to read engineCapacity");
        this->engineCapacity = engineCapacity;

    } catch (const exception& e) {
        throw runtime_error(string("Bike deserialization failed: ") + e.what());
    }
}
