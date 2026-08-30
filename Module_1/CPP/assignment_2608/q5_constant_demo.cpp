#include<iostream>
using namespace std;


int main(){
    int a = 5;
    int b = 10;

    const int* ptr1 = &a;  // pointer to const int — *ptr1 is read-only
    int* const ptr2 = &a;  // const pointer to int — ptr2 cannot point elsewhere
    const int* const ptr3 = &b; // here *ptr3 is const as well ptr3 is const 
    // trying to modify the value through ptr3 -> error 
    //   *ptr3 = 20; 
    
    // trying to modify ptr3 points somewhere else -> error
    //    ptr3 = &a; // assignment of read only variable
    // Trying to modify the value through ptr1 → ERROR!
    // *ptr1 = 20;  //  Error: cannot assign to *ptr1 because it is const

    // You can change ptr1 to point somewhere else though (pointer itself is non-const)
    ptr1 = &b;  //  OK: ptr1 can point to another int

    // Trying to change ptr2 to point somewhere else → ERROR!
    // ptr2 = &b;  //  Error: ptr2 is const pointer and cannot be reassigned

    // But you can change the value of what ptr2 points to
    *ptr2 = 30;  //  OK: modifying value through ptr2 is allowed

    cout << "a = " << a << endl;  // Output: a = 30
    cout << "b = " << b << endl;  // Output: b = 10

    return 0;

}
