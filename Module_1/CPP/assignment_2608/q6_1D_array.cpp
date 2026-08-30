#include <iostream>
using namespace std;

const int SIZE = 10;

// function accept data -> for insertion of an elemnts
void acceptData(double arr[]){
    for(int i = 0; i < SIZE; i++){
	   cout << "enter the number : " << i+1 << endl;
	   cin >> arr[i];
    }
}

// function displayData -> print values of array on terminal
void displayData(double arr[]){
    for(int i = 0; i < SIZE; i++){
	    cout << arr[i] << "\t";
    }
    cout << endl;
}

// function modifyNumAtGivenPos -> change the value in array at given position
void modifyNumAtGivenPos(double arr[] , int pos, double val){
	if(pos < 0 || pos >= SIZE){
		cout << "invalid index" << endl;
		return;
	}
	arr[pos] = val;
}

// function searchNumber -> search the number in array and return the index of that number
int searchNumber(double arr[], double val){
	for(int i = 0; i < SIZE; i++){
		if(arr[i] == val) return i;
	}
	return -1;
}

// function additionOfEvenNums -> return the sum of even numbers in the array
double additionOfEvenNums(double arr[]){
	double sum = 0;
	for(int i = 0; i < SIZE; i++){
		if((int)arr[i] % 2 == 0) { // modulo int works with int
			sum += arr[i];
		}
	}
	return sum;
}

// function isPrime -> check the number is prime or not
bool isPrime(double num){
	int intnum = (int) num; // for getting the integer part of the number
	if(intnum == 1) return true;
	if(intnum % 2 == 0) return false; // skip even numbers

	for(int i = 3; i * i < intnum; i+=2){ // check only odd numbers till the square root of the number
		if(intnum % i == 0) return false;
	}
	return true;
}

// function getAllPrimeNumberFromArray -> print all prime numbers from the array and the cont of it
void getAllPrimeNumberFromArray(double arr[]){
	int count = 0;
	for(int i = 0; i < SIZE; i++){
		if(isPrime(arr[i])){
			cout << arr[i] << "\t";
			count++;
		}
	}
	cout << endl;
	cout << "total primes are : " << count << endl;
}

// function maxOddNumber -> return the maximum odd number from the array
double maxOddNumber(double arr[]){
    double maxNum = arr[0];
	for(int i = 0; i < SIZE; i++){
		if((int)arr[i] % 2 != 0){
			if(arr[i] > maxNum) maxNum = arr[i];
		}
	}
	return maxNum;
}

// function maxNthElement -> return the maximum nth element from the array
double maxNthElement(double arr[], int n){
      int len = SIZE;
	  // sort the array in ascending order using bubble sort
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < len -i -1; j++) {
			if(arr[j] > arr[j+1]){
				double temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}	
      	}
      }
	  // return the maximum nth element from the array
      return arr[len - n];
}

// deleteNum -> delete the number from the array
void deleteNum(double arr[] , int val){
	int pos = searchNumber(arr, val);
	if(pos == -1) return;
	
    // shift the elements to the left from the position of the deleted number
	for(int i = pos; i < SIZE; i++){
		if(i == SIZE - 1) arr[i] = 0;
		else arr[i] = arr[i+1];
	}

}
int main(){

	double arr[SIZE];

	acceptData(arr);
	displayData(arr);

	modifyNumAtGivenPos(arr, 3, 11);
	displayData(arr);

	if(searchNumber(arr, 11) != -1) cout << "found\n";
	else cout << "not found\n";
        
    int delNum;
    cout << "Enter the number you want to delete : " << endl;
	cin >> delNum;	
	deleteNum(arr, delNum);
	displayData(arr);

	cout << "addition of Even nums is : " << additionOfEvenNums(arr) << endl;

	getAllPrimeNumberFromArray(arr);

	double res = maxOddNumber(arr);
	if((int)res % 2 == 0) cout << "no odd element in the array" << endl;
	else cout << "max odd element is : " << res << endl;

	displayData(arr);
	cout <<"Maximum 5th element in the array is " << maxNthElement(arr, 5) << endl;
	
    return 0;


}
