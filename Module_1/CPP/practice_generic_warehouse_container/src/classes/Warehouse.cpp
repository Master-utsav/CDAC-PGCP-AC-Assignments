#include "WarehouseBox.h"
#include "Warehouse.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
vector<WarehouseBox<T>> Warehouse<T>::wareArray; 

template <typename T>
void Warehouse<T>::addBox(){
    T item;                                  
    cout << "Enter the item : " << endl;
    cin >> item;                           

    int quantity;
    cout << "Enter the quantity : " << endl;
    cin >> quantity;

    try{                                        
        WarehouseBox<T> w(item, quantity);       
        wareArray.push_back(w);
    }
    catch (runtime_error &e){
        cout << "error : " << e.what() << endl;
    }
}

template <typename T>
WarehouseBox<T> Warehouse<T>::findLargest() {
    if (wareArray.empty()){
        throw runtime_error("No records found");   // FIX: can't 'return nullptr' for a class return
    }                                                // type — throw and let the caller handle/display it

    WarehouseBox<T> maxW = wareArray[0];
    for (int i = 1; i < wareArray.size(); ++i){   // FIX: size_t instead of int, matches
        if (wareArray[i].getQuantity() > maxW.getQuantity()){  // vector::size()'s unsigned type
            maxW = wareArray[i];
        }
    }
    return maxW;
}

template <typename T>
void Warehouse<T>::sortByQuantity(){
    sort(wareArray.begin(), wareArray.end(), [](const WarehouseBox<T> &w1, const WarehouseBox<T> &w2)
         { return w1.getQuantity() < w2.getQuantity(); });   // FIX: added missing semicolon
}

template <typename T>
void Warehouse<T>::display(){
    for (int i = 0; i < wareArray.size(); ++i){    // FIX: size_t, same reason as above
        cout << wareArray[i];
    }
}

template class Warehouse<string>;   // FIX: same explicit-instantiation fix as WarehouseBox.cpp —
                                     // required since main.cpp never includes this .cpp file