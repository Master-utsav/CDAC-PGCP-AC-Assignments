#include<iostream>
using namespace std;

int main (){
	cout << "size of char : " << sizeof(char) << endl;
	cout << "size of int : " << sizeof(int) << endl;
	cout << "size of double : " << sizeof(double) << endl;
	cout << "size of bool : " << sizeof(bool) << endl;
	cout << "size of long int : " << sizeof(long int) << endl;
	cout << "size of int[5] : " << sizeof(int[5]) << endl;
	char hello[] = "hello";
	cout << "size of char[] = hello  : " << sizeof(hello) << endl;
	cout << "size of wide_char_t : " << sizeof(wchar_t) << endl;
	return 0;
}
