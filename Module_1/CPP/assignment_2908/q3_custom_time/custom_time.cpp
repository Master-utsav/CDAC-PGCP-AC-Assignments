#include <iostream>
#include "custom_time.h"
#include "formatter.h"

using namespace std;

int CustomTime::idCounter = 1;

// definition of default costructor
CustomTime::CustomTime(){
    id = idCounter++;
    hours = 0;
    minutes = 0;
}

// definition of parameterize constructor 
CustomTime::CustomTime(int hours, int minutes){
    id = idCounter++;
    this->hours = hours;
    this->minutes = minutes;
}

// definition of copy constructors
CustomTime::CustomTime(const CustomTime &t){
    cout << "Copy constructor called... for id : " << t.id << endl;
    id = idCounter++;
    this->hours = t.hours;
    this->minutes = t.minutes;
}

// setter
void CustomTime::setHours(int hours) {
    this->hours = hours;
}
void CustomTime::setMinutes(int minutes) {
    this->minutes = minutes;
}

// getter
int CustomTime::getId(){
    return this->id;
}
int CustomTime::gethours(){
    return this->hours;
}
int CustomTime::getMinutes(){
    return this->minutes;
}

// operator overloading (+)
CustomTime CustomTime::operator+(const CustomTime &t) const {
    // TODO : write the + function
    CustomTime temp;
    int totalMinutes = (this->hours * 60 + this->minutes) + (t.hours * 60 + t.minutes);
    temp.hours = Formatter::formateHours(totalMinutes);
    temp.minutes = Formatter::formateMinutes(totalMinutes);
    return temp;
}
// operator overloading (-)
CustomTime CustomTime::operator-(const CustomTime &t) const {
    // TODO : write the - function
    CustomTime temp;
    int totalMinutes = (this->hours * 60 + this->minutes) - (t.hours * 60 + t.minutes);
    if(totalMinutes < 0){
        temp.hours = 0;
        temp.minutes = 0;
        return temp;
    }
    temp.hours = Formatter::formateHours(totalMinutes);
    temp.minutes = Formatter::formateMinutes(totalMinutes);
    return temp;
}
// operator overloading (=)
CustomTime CustomTime::operator=(const CustomTime &t) {
    // TODO : write the = function
    cout << "operator (=) constructor called... for id : " << t.id << endl;
    this->hours = t.hours;
    this->minutes = t.minutes;
    return *this;
}

// operator overloading (++)(int)
CustomTime CustomTime::operator++(int){
    // TODO : write the ++ as postfix function
    CustomTime temp = *this;
    minutes++;
    if (minutes >= 60){
        minutes = 0;
        hours++;
    }
    return temp;
}
// operator overloading (++)()
CustomTime CustomTime::operator++(){
    // TODO : write the ++ as prefix function
    minutes++;
    if (minutes >= 60){
        minutes = 0;
        hours++;
    }
    return *this;
}
// operator overloading (--)(int)
CustomTime CustomTime::operator--(int){
    // TODO : write the -- postfix function
    CustomTime temp = *this;
    minutes--;
    if (minutes < 0) {
        minutes = 59;
        hours--;
    }
    return temp;
}
// operator overloading (++)()
CustomTime CustomTime::operator--(){
    // TODO : write the -- as prefix function
    minutes--;
    if (minutes < 0) {
        minutes = 59;
        hours--;
    }
    return *this;
}

// friend function opertor overload <<
ostream& operator<<(ostream& out, CustomTime &t){
    // TODO : write the proper display with formatter
    out << "Time Object : " << t.getId() << endl
        << "Hours : " << t.gethours() << endl
        << "Minutes : " << t.getMinutes() << endl
        << "---------------------------------------------" << endl;

    return out;
}

// friend function opertor overload >>
istream &operator>>(istream &in, CustomTime &t){
    // TODO : write the proper in with formatter
    int hours, minutes;
    cout << "Set time to Time Object : " << t.getId() << endl;
    cout << "Enter the hours : ";
    in >> hours;
    cout << "Enter the minutes : ";
    in >> minutes;

    t.setHours(hours);
    t.setMinutes(minutes);

    cout << "--------------------------------" << endl;
    return in;
}

// destructor
CustomTime::~CustomTime(){
    // cout << "Calling the destructor for obj id : " << this->id << endl;
}
