#ifndef WAREHOUSEBOX_H
#define WAREHOUSEBOX_H

#include<iostream>

using namespace std;

template<typename T>
class WarehouseBox{
    private:
        T item;
        int quantity;

    public:
        WarehouseBox(T item, int quantity);
        WarehouseBox() : item(T()), quantity(0) {}

        WarehouseBox<T> operator+(const WarehouseBox<T> &);
        WarehouseBox<T> operator-(const WarehouseBox<T> &);
        bool operator==(const WarehouseBox<T> &);
        bool operator<(const WarehouseBox<T> &);

        // prefix and postfix
        WarehouseBox<T> operator++(int); // postfix
        WarehouseBox<T>& operator++();   // prefix

        int getQuantity() const { return quantity; }
        T getItem() const { return item; }

        template<typename U>
        friend ostream& operator<<(ostream &out, const WarehouseBox<U> &e);

        ~WarehouseBox();
};

#endif