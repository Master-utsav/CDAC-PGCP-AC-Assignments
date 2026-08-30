#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 4;

// function to accept data from user
void acceptData(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << "Enter the number for " << i + 1 << "," << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}

// function to display data of 2d aarray
void displayData(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to get maximum number -> getMaxNum
int getMaxNum(int arr[ROW][COL]) {
    int maxNum = arr[0][0];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maxNum < arr[i][j]) {
                maxNum = arr[i][j];
            }
        }
    }

    return maxNum;
}

// Function to get minimum number -> getMinNum
int getMinNum(int arr[ROW][COL]) {
    int minNum = arr[0][0];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (minNum > arr[i][j]) {
                minNum = arr[i][j];
            }
        }
    }

    return minNum;
}

// function to get sum of all numbers of the array
int getSumOfAllVals(int arr[ROW][COL]) {
    int sum = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

// Function to get sum of each row -> getSumOfEachRow
void getSumOfEachRow(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        int sum = 0;
        for (int j = 0; j < COL; j++) {
            sum += arr[i][j];
        }
		cout << "Row " << i + 1 << " sum : " << sum << endl;
    }
}

// Function to get sum of each column -> getSumOfEachCol
void getSumOfEachCol(int arr[ROW][COL]) {
    for (int j = 0; j < COL; j++) {
        int colSum = 0;
        for (int i = 0; i < ROW; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " sum : " << colSum << endl;
    }
}

// Function to find rowWise maximum -> findRowWiseMax
void findRowWiseMax(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        int rowMax = arr[i][0];

        for (int j = 1; j < COL; j++) {
            if (rowMax < arr[i][j]) {
                rowMax = arr[i][j];
            }
        }
        cout << "Row " << i + 1 << " max : " << rowMax << endl;
    }
}

// function to find columnWise maximum -> findColWiseMax
void findColWiseMax(int arr[ROW][COL]) {
    for (int j = 0; j < COL; j++) {
        int colMax = arr[0][j];

        for (int i = 1; i < ROW; i++) {
            if (colMax < arr[i][j]) {
                colMax	 = arr[i][j];
            }
        }
        cout << "Columon " << j + 1 << " max : " << colMax<< endl;
    }
}


int main() {

    int arr[ROW][COL];

    // Accept data from user
    acceptData(arr);

    // Display 2D array
    cout << "The 2D array is:" << endl;
    displayData(arr);

    // Maximum number
    cout << "The maximum number in the 2D array is: " << getMaxNum(arr) << endl;

    // Minimum number
    cout << "The minimum number in the 2D array is: "<< getMinNum(arr) << endl;

    // Sum of all numbers
    cout << "The sum of all numbers is: "<< getSumOfAllVals(arr) << endl;

    // Sum of each row
    cout << "The sum of each row is:" << endl;
    getSumOfEachRow(arr);

    // Sum of each column
    cout << "The sum of each column is:" << endl;
    getSumOfEachCol(arr);

    // Maximum number in each row
    cout << "The maximum number in each row is:" << endl;
    findRowWiseMax(arr);

    // Maximum number in each column
    cout << "The maximum number in each column is:" << endl;
    findColWiseMax(arr);
	
    return 0;
}