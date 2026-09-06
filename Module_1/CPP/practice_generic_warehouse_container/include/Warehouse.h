#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "WarehouseBox.h"

using namespace std;

template<typename T>
class Warehouse{
    private:
        static vector<WarehouseBox<T>> wareArray;

    public:
        static void addBox();
        static WarehouseBox<T> findLargest();
        static void sortByQuantity();
        static void display();
};

#endif