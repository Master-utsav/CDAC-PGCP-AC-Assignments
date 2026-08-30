#ifndef CONSTANTS_H
#define CONSTANTS_H

class Constants{
    static int defaultFair;
    static int landTwoWheelerDefaultFair;
    static int landFourWheelerDefaultFair;
    static int waterVehicleDefaultFair;
    static int airVehicleDefaultFair;
    static int defaultfairIncreaseAsPerPeople;

    public:
        static const int getdDefaultFair() {
            return defaultFair;
        }
        static const int getLandTwoWheelerDefaultFair() {
            return landTwoWheelerDefaultFair;
        }
        static const int getLandFourWheelerDefaultFair() {
            return landFourWheelerDefaultFair;
        }
        static const int getWaterVehicleDefaultFair() {
            return waterVehicleDefaultFair;
        }
        static const int getAirVehicleDefaultFair() {
            return airVehicleDefaultFair;
        }
        static const int getDefaultfairIncreaseAsPerPeople() {
            return defaultfairIncreaseAsPerPeople;
        }

};

int Constants::defaultFair = 50;
int Constants::landTwoWheelerDefaultFair = 10;
int Constants::landFourWheelerDefaultFair = 25;
int Constants::waterVehicleDefaultFair = 150;
int Constants::airVehicleDefaultFair = 200;
int Constants::defaultfairIncreaseAsPerPeople = 2;

#endif