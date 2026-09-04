#include <ctime>
#include <string>
#include <stdexcept>
#include <Car3.h>

using namespace std;

// template <typename T>
// bool isValidYear(T year) {
//     time_t now = time(nullptr);
//     tm* timeinfo = localtime(&now);
//     int currentYear = timeinfo->tm_year + 1900;

//     if (is_same_v<T, string>) {
//         try {
//             int yearInt = stoi(year);
//             return yearInt >= 2000 && yearInt <= currentYear;
//         } catch (const invalid_argument&) {
//             return false;  
//         }
//     }
//     return (year >= 2000 && year <= currentYear);
// }

bool isValidYear(const string& year) {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    int currentYear = timeinfo->tm_year + 1900;

    try {
        int yearInt = stoi(year);
        return yearInt >= 2000 && yearInt <= currentYear;
    } catch (const invalid_argument&) {
        return false;
    }
}

// Overload for int
bool isValidYear(int year) {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    int currentYear = timeinfo->tm_year + 1900;

    return year >= 2000 && year <= currentYear;
}

bool isValidFuelType(FuelType ft) {
    return ft == FuelType::PETROL || 
           ft == FuelType::DIESEL || 
           ft == FuelType::ELECTRIC || 
           ft == FuelType::CNG;
}

string fuelTypeToString(FuelType ft) {
    switch (ft) {
        case FuelType::PETROL:
            return "PETROL";
        case FuelType::DIESEL:
            return "DIESEL";
        case FuelType::ELECTRIC:
            return "ELECTRIC";
        case FuelType::CNG:
            return "CNG";
        default:
            throw runtime_error("Invalid fuel type");
    }
}

// Helper: Convert string to FuelType enum
FuelType stringToFuelType(const string& ft) {
    if (ft == "PETROL") return FuelType::PETROL;
    if (ft == "DIESEL") return FuelType::DIESEL;
    if (ft == "ELECTRIC") return FuelType::ELECTRIC;
    if (ft == "CNG") return FuelType::CNG;
    throw runtime_error("Invalid fuel type string: " + ft);
}