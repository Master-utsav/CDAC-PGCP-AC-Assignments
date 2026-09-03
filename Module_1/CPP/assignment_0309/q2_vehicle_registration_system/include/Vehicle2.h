#ifndef VEHICLE2_H
#define VEHICLE2_H

#include<string>
using namespace std;

enum class VehicleType{
    CAR,
    BIKE
};

class Vehicle{
    private:
        string RegistrationNumber;
        static int nextId;
        
    protected:
        VehicleType type;
        string modelName;
        string manufacturerName;
        int yearOfManufacture;
        string couponName;

    public:
        Vehicle(const string &modelName, const string &manufacturerName, int yearOfManufacture);
        virtual void displayInfo() = 0;
        string getRegistrationNumber() const { return RegistrationNumber; }
        void setNextId() { nextId++; }
        int getNextId() const { return nextId; }
        void setRegistrationNumber(const string& regNum) { RegistrationNumber = regNum; }
        virtual void serialize(ostream &outfile) const = 0;
        virtual void deserialize(istream &infile) = 0;

        virtual ~Vehicle();
};


#endif