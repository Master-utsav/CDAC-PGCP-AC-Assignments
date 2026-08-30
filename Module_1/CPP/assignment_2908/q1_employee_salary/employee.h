#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee{
    private:
        int empid;
        char* name;
        double salary;
        static int empidCounter;

    public:
        Employee();
        Employee(char *name, double salary);
        
        // getters
        const char* getName() const;
        int getEmpid() const;
        double getSalary() const;

        // setters
        void setName(char* nm);
        void setSalary(double salary);

        // methods
        double calculateSalary();
        double calculateSalary(double bonus);
        double calculateSalary(double bonus, int overtimeAmount);
        double calculateSalary(int hourlyRate, int noOfhours);
        
        //destructor
        ~Employee();

        friend ostream& operator<<(ostream& out, Employee &e);
        friend istream& operator>>(istream& in, Employee &e);
};

#endif