#ifndef BIKE2_H
#define BIKE2_H

#include "Vehicle3.h"
#include <string>
using namespace std;

class Bike : public Vehicle{
    private:
        int engineCapacity;
    public:
        Bike(const string &modelName, const string &manufacturerName, int yearOfManufacture,  int engineCapacity);
        void displayInfo() override;
        void serialize(ostream &outfile) const;
        void deserialize(istream &infile);

        // Bike(Bike &&other) noexcept = default;
        // Bike &operator=(Bike &&other) noexcept = default;
        
        ~Bike() override = default;
};

#endif