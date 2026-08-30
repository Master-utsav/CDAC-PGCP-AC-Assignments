#include <iostream>
#include "custom_time.h"

using namespace std;

int main(){
    CustomTime t1, t2;
    cin >> t1 >> t2;
    cout << t1 << endl
         << t2 << endl;
    
    cout << "copying t1 to t3" << endl;
    CustomTime t3 = t1; // copy constructor
    cout << t3 << endl;

    cout << "assigning t1 to t4" << endl;
    CustomTime t4;
    t4 = t1; // operator (=) overload 
    cout << t4 << endl;
    
    cout << "performing arithmetic + operations on t1 and t2" << endl;
    CustomTime t5 = t1 + t2; // operator (+) called 
    cout << t5 << endl;
    
    cout << "performing arithmetic - operations on t1 and t2" << endl;
    t5 = t1 - t2; // operator (-) called then // operator (=) called
    cout << t5 << endl;
    
    cout << "performing post-increment operation on t2" << endl;
    t5 = t2++; // operator (++)(int) called
    cout << t5 << endl
         << t2 << endl;

    cout << "performing pre-increment operation on t2" << endl;
    t5 = ++t2; // operator (++)() called
    cout << t5 << endl
         << t2 << endl;

    cout << "performing post-decrement operation on t2" << endl;
    t5 = t2--; // operator (--)(int) called
    cout << t5 << endl
         << t2 << endl;

    cout << "performing pre-decrement operation on t2" << endl;
    t5 = --t2; // operator (--)() called
    cout << t5 << endl
         << t2 << endl;

    return 0;
}