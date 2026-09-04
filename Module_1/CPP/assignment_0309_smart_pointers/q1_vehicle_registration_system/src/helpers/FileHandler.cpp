#include<iostream>
#include<fstream>
#include<cstring>
#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <memory>

#include "Vehicle3.h"
#include "Bike3.h"
#include "Car3.h"

bool writeData(string fileName, vector<shared_ptr<Vehicle>> &v){
    try{
        ofstream outfile(fileName , ios::binary);
        if(!outfile){
            cerr << "File Not Found..." << endl;
            throw(runtime_error("File Not Found..."));
        }
        for(auto &it : v){
            cout << "Writing in file" << endl;
            if (it != nullptr) {
                it->serialize(outfile);
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

bool readData(string fileName, vector<shared_ptr<Vehicle>> &v){

    try{
        ifstream infile(fileName, ios::binary);
        if(!infile){
            cerr << "File Not Found..." << endl;
            throw runtime_error("File Not Found...");
        }

        VehicleType type;
        // shared_ptr<Vehicle> vhPtr;

        while (infile.peek() != EOF) {
            if(!infile.read(reinterpret_cast<char*>(&type), sizeof(type))){
                cerr << "Error reading type length from file." << endl;
                return false;
            }
            
            if(type == VehicleType::BIKE){
                shared_ptr<Vehicle> temp = make_shared<Bike>("", "", 0, 0);
                // vhPtr = temp;
                temp->deserialize(infile);
                v.push_back(temp);
            }
            else if (type== VehicleType::CAR){
                shared_ptr<Vehicle> temp = make_shared<Car>("", "", 0, FuelType::PETROL);
                // vhPtr = temp;
                temp->deserialize(infile);
                v.push_back(temp);
            }
            else{
                throw runtime_error("Unknown vehicle type: ");
            }
            // if (vhPtr){
            //     vhPtr->deserialize(infile);
            //     v.push_back(vhPtr);
            // }
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