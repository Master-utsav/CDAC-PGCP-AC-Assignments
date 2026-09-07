#include "WarehouseBox.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
WarehouseBox<T>::WarehouseBox(T item, int quantity){
    if (quantity < 0)
        throw runtime_error("Invalid quantity");
    this->item = item;
    this->quantity = quantity;
}

template <typename T>
WarehouseBox<T> WarehouseBox<T>::operator+(const WarehouseBox<T> & other){
    if (this->item != other.item)
        throw runtime_error("the items don't match");  

    WarehouseBox<T> temp;               
    temp.quantity = this->quantity + other.quantity;
    temp.item = other.item;
    return temp;
}

template <typename T>
WarehouseBox<T> WarehouseBox<T>::operator-(const WarehouseBox<T> &other){
    if (this->item != other.item)
        throw runtime_error("the items don't match");
    if (this->quantity - other.quantity < 0)
        throw runtime_error("quantity can't go negative");

    WarehouseBox<T> temp;                 
    temp.quantity = this->quantity - other.quantity;
    temp.item = other.item;
    return temp;
}

template <typename T>
bool WarehouseBox<T>::operator==(const WarehouseBox<T> & other){
    return (this->item == other.item && this->quantity == other.quantity);
}

template <typename T>
bool WarehouseBox<T>::operator<(const WarehouseBox<T> & other){   
    return this->quantity < other.quantity;                        
}

template <typename T>
WarehouseBox<T> WarehouseBox<T>::operator++(int){
    WarehouseBox<T> temp = *this;
    this->quantity++;
    return temp;
}

template <typename T>
WarehouseBox<T>& WarehouseBox<T>::operator++(){
    this->quantity++;
    return *this;
}

template <typename T>
ostream& operator<<(ostream& out, const WarehouseBox<T>& w){ 
    out << "--------------Warehouse Box-------------" << endl  
        << "item : " << w.item << " || " << "quantity : " << w.quantity << endl;
    return out;
}
// ! Required this 
template ostream &operator<< <string>(ostream &, const WarehouseBox<string> &);

template <typename T>
WarehouseBox<T>::~WarehouseBox() {}

template class WarehouseBox<string>;