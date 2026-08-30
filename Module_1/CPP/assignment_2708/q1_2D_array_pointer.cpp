#include<iostream>
using namespace std;


const int ROWS = 4;
const int COLS = 4;

// accept the data inside the array
void acceptData(int **arr){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			cout << "Enter the element at row : " << i << " at col : " << j << " -> ";
			cin >> arr[i][j];
		}
	}
}

// display the data of the array
void displayData(int **arr){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

// find the max number in the array
int maxNum(int **arr){
        int maxNum = arr[0][0];	
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(maxNum < arr[i][j]) maxNum = arr[i][j];
		}
	}

	return maxNum;
}

// find the min number in the array
int minNum(int **arr){
	int minNum = arr[0][0];
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(minNum > arr[i][j]) minNum = arr[i][j];
		}
	}

	return minNum;
}

// find the sum of all numbers in the array
int additionOfAllNums(int **arr){
	int sum = 0;
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			sum += arr[i][j];
		}
	}

	return sum;
}

// find the sum of each row
void findSumOfEachRow(int **arr){
	int rowSum = 0;
	for(int i = 0; i < ROWS; i++){
		rowSum = 0;
		for(int j = 0; j < COLS; j++){
			rowSum += arr[i][j];
		}
		cout << "Sum of row " << i << " is : " << rowSum << endl;
	}
}

// find the sum of each column
void findSumOfEachCol(int **arr){
	int colSum = 0;
	for(int i = 0; i < COLS; i++){
		colSum = 0;
		for(int j = 0; j < ROWS; j++){
			colSum += arr[j][i];
		}
		cout << "Sum of col " << i << " is : " << colSum << endl;
	}
}

// find the max of each row
void findRowWiseMax(int **arr){
	int rowMax = 0;
	for(int i = 0; i < ROWS; i++){
		rowMax = arr[i][0];
		for(int j = 0; j < COLS; j++){
			if(rowMax < arr[i][j]) rowMax = arr[i][j];
		}
		cout << "Max of row " << i << " is : " << rowMax << endl;
	}
}

// find the max of each column
void findColWiseMax(int **arr){
	int colMax = 0;
	for(int i = 0; i < COLS; i++){
		colMax = arr[0][i];
		for(int j = 0; j < ROWS; j++){
			if(colMax < arr[j][i]) colMax = arr[j][i];
		}
		cout << "Max of col " << i << " is : " << colMax << endl;
	}
}

int main(){
	int **arr = new int*[ROWS];
	for(int i = 0; i < ROWS ; i++){
		arr[i] = new int[COLS];
	}

	// now we have array of [ROWS][COLS]
        
	// accept the values inside the arr
	acceptData(arr);
	displayData(arr);

	cout << "Max number in the array is : " << maxNum(arr) << endl;
	cout << "Min number in the array is : " << minNum(arr) << endl;

	cout << "Addition of all numbers in the array is : " << additionOfAllNums(arr) << endl;

	findSumOfEachRow(arr);
	cout << endl;

	findSumOfEachCol(arr);
	cout << endl;

	findRowWiseMax(arr);
	cout << endl;

	findColWiseMax(arr);
	cout << endl;
	
	// free the memory allocated for the array since it is a dyanmic
	for(int i = 0; i < ROWS; i++){
		delete[] arr[i];
	}
	delete[] arr;
}
