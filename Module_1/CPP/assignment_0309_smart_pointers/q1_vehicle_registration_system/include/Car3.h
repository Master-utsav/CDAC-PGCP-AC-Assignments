#ifndef CAR2_H
#define CAR2_H

#include "Vehicle3.h"
#include <string>
using namespace std;

enum class FuelType{
    PETROL,
    DIESEL,
    ELECTRIC,
    CNG
};

class Car : public Vehicle{
    private:
        FuelType fuelType;
    public:
        Car(const string &modelName, const string &manufacturerName, int yearOfManufacture, FuelType fuelType);
        void displayInfo() override;
        void serialize(ostream &outfile) const;
        void deserialize(istream &infile);

        // Car(Car &&other) noexcept = default;
        // Car &operator=(Car &&other) noexcept = default;
        
        ~Car() override = default;
};

#endif