#include <iostream>
using namespace std;

double PI = 3.14;
int factorial(int num){
	if(num == 0) return 1;
	return factorial(num - 1) * num;
}


