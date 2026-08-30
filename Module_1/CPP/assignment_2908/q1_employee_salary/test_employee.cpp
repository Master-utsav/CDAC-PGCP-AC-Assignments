#include <iostream>
#include "employee.h"

using namespace std;

int main(){
    Employee e1, e2;
    cin >> e1 >> e2;
    cout << e1 << e2;
      
    //  double calculateSalary();
      double e1Salary = e1.calculateSalary();
      cout << "Basic salary of employee : " << endl
           << e1 << endl
           << "is : " << fixed << e1Salary << endl;

    //  double calculateSalary(double bonus);
      double bonus;
      cout << "Enter the bonus : ";
      cin >> bonus;
      double e1Salary2 = e1.calculateSalary(bonus);
      cout << "Basic salary + bonus salary of employee : " << endl
           << e1 << endl
           << "is : " << fixed << e1Salary2 << endl;
       
    //   double calculateSalary(double bonus, int overtimeAmount);
      int overtimeAmount = 0;
      cout << "Enter the over time amount : ";
      cin >> overtimeAmount;
      double e1Salary3 = e1.calculateSalary(bonus, overtimeAmount);
      cout << "Basic salary + bonus + overtime salary of employee : " << endl
           << e1 << endl
           << "is : " << fixed << e1Salary3 << endl;
      
    //  double calculateSalary(int hourlyRate, int noOfhours);
      int hourlyRate = 0;
      int noOfHours = 0;
      cout << "Enter the hourlyRate: ";
      cin >> hourlyRate;
      cout << "Enter the noOfHours: ";
      cin >> noOfHours;
      double e1Salary4 = e1.calculateSalary(hourlyRate, noOfHours);
      cout << "Basic salary + bonus salary of employee : " << endl
           << e1 << endl
           << "is : " << fixed << e1Salary4 << endl;
      
    return 0;
}