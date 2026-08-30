#include <iostream>
#include "employee.h"
#include <cstring>

using namespace std;

int Employee::empidCounter = 1;

// employee constructor we are defining
Employee::Employee(){
    empid = empidCounter++;
    name = new char[1];
    name[0] = '\0';
    salary = 0;
}

Employee::Employee(char *name, double salary){
    empid = empidCounter++;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name , name);
    this->salary = salary;   
}

// getters
const char* Employee::getName() const {
    return name;
}
int Employee::getEmpid() const {
    return empid;
}
double Employee::getSalary() const {
    return salary;
};

// setters
void Employee::setName(char* nm){
    if(name){
        delete[] name;
    }
    name = new char[strlen(nm) + 1];
    strcpy(name, nm);
}
void Employee::setSalary(double salary){
    this->salary = salary;
}

//methods
double Employee::calculateSalary(){
    return salary;
}
double Employee::calculateSalary(double bonus){
    return (salary + bonus);
}
double Employee::calculateSalary(double bonus, int overtimeAmount){
    return (salary + bonus + overtimeAmount);

}
double Employee::calculateSalary(int hourlyRate, int noOfhours){
    return (hourlyRate * noOfhours);
}

//desctructor
Employee::~Employee(){
    if(name){
        delete[] name;
    }
}

ostream& operator<<(ostream& out, Employee &e){
    out << "empid : " << e.getEmpid() << endl
        << "name : " << e.getName() << endl
        <<  "salary : " << fixed << e.getSalary() << endl
        << "------------------------------" << endl;
    return out;
}

istream& operator>>(istream& in, Employee &e){
    char name[100];
    double salary;

    cout << "Enter the name of employee : ";
    in >> name;
    cout << "Enter the salary : ";
    in >> salary;

    e.setName(name);
    e.setSalary(salary);
    
    return in;
}

