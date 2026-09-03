#include<iostream>
#include<fstream>
#include<cstring>
#include <typeinfo>
#include <stdexcept>

#include "Vehicle2.h"
#include "Bike2.h"
#include "Car2.h"

bool writeData(const char* fileName, Vehicle **v, int count){
    try{
        ofstream outfile(fileName , ios::binary);
        if(!outfile){
            cerr << "File Not Found..." << endl;
            throw(runtime_error("File Not Found..."));
        }
        for(int i = 0; i < count; i++){
            cout << "Writing in file" << endl;
            if (v[i] != nullptr) {
                v[i]->serialize(outfile);
            }
        }
        outfile.close();
        cout << "Write successfully inside the " << fileName << endl;
        return true;  
    }
    catch(runtime_error &e){
        cerr << "Error: " << e.what() << endl;
        return false;
    }

}

bool readData(const char* fileName, Vehicle **v, int &count){

    try{
        ifstream infile(fileName, ios::binary);
        if(!infile){
            cerr << "File Not Found..." << endl;
            throw runtime_error("File Not Found...");
        }

        // int len_type;
        VehicleType type;
        while (infile.peek() != EOF) {
            if(!infile.read(reinterpret_cast<char*>(&type), sizeof(type))){
                cerr << "Error reading type length from file." << endl;
                return false;
            }
            // if (len_type <= 0 || len_type > 100) {
            //     throw runtime_error("Invalid type length");
            // }

            // string typeStr(len_type, '\0');
            // infile.read(&typeStr[0], len_type);

            //  Vehicle* s = nullptr;
            // // cout << "Type str -> " << typeStr << endl;
            // if (typeStr == "CAR") {
            //     // cout << "inside CAR" << endl;
            //     s = new Car("", "", 0, FuelType::PETROL);
            // }
            // else if (typeStr == "BIKE") {
            //     // cout << "inside BIKE" << endl;
            //     s = new Bike("", "", 0, 0);
            // }
            // else {
            //     throw runtime_error("Unknown vehicle type: " + typeStr);
            // }

            // ! Do this it works 
            Vehicle *s = nullptr;
            if(type == VehicleType::BIKE){
                s = new Bike("", "", 0, 0);
            }
            else if (type== VehicleType::CAR){
                s = new Car("", "", 0, FuelType::PETROL);
            }
            else{
                throw runtime_error("Unknown vehicle type: ");
            }
            if (s){
                s->deserialize(infile);
                v[count++] = s;
            }
        }
        infile.close();
        cout << "Read successfully from the " << fileName << endl;
        return true;  
    }
    catch(const runtime_error &e){
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}