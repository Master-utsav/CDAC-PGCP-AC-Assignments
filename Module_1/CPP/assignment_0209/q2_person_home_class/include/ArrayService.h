#ifndef ARRAY_SERVICE_H
#define ARRAY_SERVICE_H

#include "Person.h"
#include "Address.h"

/*
 ArrayService::addPerson();
ArrayService::addAddressToPerson();
ArrayService::displayAllPersons();
ArrayService::searchById();
ArrayService::searchByName();
ArrayService::modifyAddress();
ArrayService::findAddressById();
ArrayService::displayPersonsInCity();
*/

class ArrayService {
    private:
        static const int maxCount = 100;
        static Person *persons[maxCount];
        static int personCount;
    public:
        static void addPerson();
        static void addAddressToPerson();
        static void displayAllPersons();
        static void searchById();
        static void searchByName();
        static bool modifyAddress();
        static Address* findAddressById();
        static void displayPersonsInCity();
};


#endif