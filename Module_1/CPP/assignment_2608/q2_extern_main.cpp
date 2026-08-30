#include <iostream>
// u can avoid this use extern 
// #include "./q2_extern_support.cpp" 
// if you want to avoid mentioning the q2_extern_support.cpp file name at the time of compilation -> you can just import that file and access there vars and function
using namespace std;

int main(){
	extern double PI; // using the external PI value from q2_extern_support.cpp
			  //
 	// calculating the area of the circle
	double radius;
	cout << "enter the radius : " << endl;
	cin >> radius;
	cout << "area of circle : " << PI * radius * radius << endl;

	// calculating the factorial of a number
	int num;
	extern int factorial(int); // using the external factorial function q2_external_suppport.cpp
	cout << "enter the number for factorial : " << endl;
	cin >> num;
	cout << "factorial of : " << num << " is : " << factorial(num) << endl;

	return 0;
}
