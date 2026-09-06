#include <iostream>
#include <stdexcept>
#include <string>
#include "Warehouse.h"
#include "WarehouseBox.h"

using namespace std;

int main(){

    Warehouse<string>::addBox();
    Warehouse<string>::addBox();
    Warehouse<string>::addBox();

    Warehouse<string>::display();

    Warehouse<string>::addBox();
    Warehouse<string>::addBox();
    Warehouse<string>::addBox();

    Warehouse<string>::display();

    try{                                              
        WarehouseBox<string> largest = Warehouse<string>::findLargest();  
        cout << "Largest box:" << endl << largest;     
    }
    catch (runtime_error &e){
        cout << "error : " << e.what() << endl;
    }

    Warehouse<string>::sortByQuantity();
    Warehouse<string>::display();

    WarehouseBox<string> boxA("Bolts", 50);
    WarehouseBox<string> boxB("Bolts", 30);

    try{
        WarehouseBox<string> combined = boxA + boxB;
        cout << "Combined:" << endl << combined;
    }
    catch (runtime_error &e){
        cout << "error : " << e.what() << endl;
    }

    ++boxA;
    cout << "After increments:  ++boxA -> " << endl
         << boxA;
    boxA++;
    cout << "After increments:  boxA++ -> " << endl
         << boxA;

    return 0;
}