#ifndef CUSTOM_TIME_H
#define CUSTOM_TIME_H

#include <iostream>
using namespace std;

class CustomTime{
    private:
        static int idCounter;
        int id;    // just for to define the all objects unique
        int hours; // hours (time)
        int minutes; // minutes (time)
    
    public:
    // constructors
        CustomTime(); // default constructor with zero args
        CustomTime(int hours, int minutes); // parametrized constructor with args (hrs and minutes)
        CustomTime(const CustomTime &t); // copy constructor for making teh deep copy of the object

    // setter
        void setHours(int hours);     // setter method for set -> hours(private)
        void setMinutes(int minutes); // setter method for set -> minutes(private)

        // getter
        int getId(); // getter method for get -> id(private)
        int gethours(); // getter method for get -> hours(private)
        int getMinutes(); // getter method for get -> minutes(private)
    
    // operator overloads
        CustomTime operator+(const CustomTime &t) const; // operator overloading for c1 + c2
        CustomTime operator-(const CustomTime &t) const; // operator overloading for c1 - c2
        CustomTime operator=(const CustomTime &t); // operator overloading for c1 = c2
        CustomTime operator++(int);          // operator overloading for c1 = c2++
        CustomTime operator++();             // operator overloading for c1 = ++c2
        CustomTime operator--(int);          // operator overloading for c1 = c2--
        CustomTime operator--();             // operator overloading for c1 = --c2

        // friend functions
        friend ostream &operator<<(ostream &out, CustomTime &t); // friend function for cout >> 
        friend istream &operator>>(istream &in, CustomTime &t);  // friend function for cin <<

        // destructor
        ~CustomTime();
};

#endif