#include <iostream>
using namespace std;

int global_num = 10;

// counter function -> counts the no. of times function call 
int counter(){
	static int num = 0;
	num++;
	return num;
}

int main(){
	{
		static int global_num = 15;
		cout << global_num << endl; // it out -> 15 because global_num is bounded in the scope.
	}
	cout << global_num << endl; // here it out -> 10 because in the scope there is no declaration of the global_num. 
	cout << "function counter calls  : "<< counter() << endl; // 1
	cout << "function counter calls  : "<< counter() << endl; // 2 
	cout << "function counter calls  : "<< counter() << endl; // 3
	cout << "function counter calls  : "<< counter() << endl; // 4 times it called 

	return 0;
}
