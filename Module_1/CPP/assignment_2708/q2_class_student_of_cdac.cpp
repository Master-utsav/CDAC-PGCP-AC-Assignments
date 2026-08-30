#include <iostream>
#include <cstring>

using namespace std;

class StudentOfCdac {
	static int nextSNo; // just for creating a autoIncrement Serial no of student
	// because static int will retain the value 
        
	int sNo;
	long int prn; 
	char *name;
	int formNo;
	char *course;
	const char *batch = "Aug 2026"; // it is constant value for all students of cdac
        
	// declaration of three subject
	int sub1;
	int sub2;
	int sub3;

    public:
	// default constructor 
	StudentOfCdac() {
	    sNo = nextSNo++;
	    prn = 260840120000;
	    name = new char[1];
	    name[0] = '\0';
	    formNo = 00000000;
	    course = new char[1];
	    course[0] = '\0';
	    sub1 = 0;
	    sub2 = 0;
	    sub3 = 0;
	}

	// parametrized constructor
	StudentOfCdac(long int prn, char *name, int formNo, char *course){
		sNo = nextSNo++; // incrementing the static variable for each object creation by using static var
	        this->prn = prn;
	        this->name = new char[strlen(name) + 1];
	        strcpy(this->name, name);

	        this->formNo = formNo;

	        this->course = new char[strlen(course) + 1];
	        strcpy(this->course,course);

		sub1 = 0;
		sub2 = 0;
		sub3 = 0;	
	}

	// getter
	int getSNo() const {
		return sNo;
	}
	long int getPrn() const {
		return prn;
	}
	char *getName() const {
		return name;
	}
	int getFormNo() const {
		return formNo;
	}
	char *getCourse() const {
		return course;
	}
	const char *getBatch() const {
		return batch;
	}
	int getSubject1(){
		return sub1;
	}
	int getSubject2(){
		return sub2;
	}
	int getSubject3(){
		return sub3;
	}
	double getAvgOfAllThreeSubjects(){
		return ((sub1 + sub2 + sub3) / 3);
	}

	// setter
	void updateName(char *name){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);
	}
	void updateFormNo(int formNo){
		this->formNo = formNo;
	}
	void updateCourse(char *course){
		delete[] this->course; // deleting the old course name
		this->course = new char[strlen(course) + 1];
		strcpy(this->course,course);
	}
	void updateSubjectMarks(int sub1, int sub2, int sub3){
		this->sub1 = sub1;
		this->sub2 = sub2;
		this->sub3 = sub3;
	}

	//displayDataOfObject
	void displayData(){
		cout << "Student no. : " << sNo << endl;
		cout << "Student prn no. : " << prn << endl;
		cout << "Student name : " << name << endl;
		cout << "Form Number : " << formNo << endl;
		cout << "Course : " << course << endl;
		cout << "Batch : " << batch << endl;
		cout << "Subject 1 marks : " << sub1 << endl;
		cout << "Subject 2 marks : " << sub2 << endl;
		cout << "Subject 3 marks : " << sub3 << endl;
		cout << "Avg of all three subjects : " << this->getAvgOfAllThreeSubjects() << endl;
	}
    
	// destructor it will be caall automatically when object goes out of scope or deleted
	~StudentOfCdac(){
		cout << "destructor called....." << endl;
		delete[] name;
		delete[] course;
	}
};

int StudentOfCdac::nextSNo = 1; // initializing the static variable with 1 because we want to start the serial number from 1

// function to accept student data in array of objects
void acceptStudentDataInArray(StudentOfCdac *arr[], int size){
	for(int i = 0; i < size; i++){
	    long int prn;
	    int formNo;
	    char name[50];
	    char course[50];
            
	    cout << "enter the prn number for student " << i+1 << " : ";
	    cin >> prn;

	    cout << "enter the form number for student " << i+1 << " : ";
	    cin >> formNo;
	    cin.ignore(); // to ignore the newline char (when we type enter or '\n') it was left in the input buffer after reading formNo

	    cout << "enter the name for student " << i+1 << " : ";
	    cin.getline(name, 50);

	    cout << "enter the course name for student " << i+1 << " : ";
	    cin.getline(course, 50);

	    arr[i] = new StudentOfCdac(prn, name, formNo, course);
	}
}

// function to update marks of students in array of objects
void updateMarksOfStudents(StudentOfCdac *arr[], int size){
	for(int i =0; i < size; i++){
	     int sub1, sub2, sub3;
	     cout << "Enter all Three Subjects Marks for student pnr : " << arr[i]->getPrn() << endl;
	     cin >> sub1 >> sub2 >> sub3;
             arr[i]->updateSubjectMarks(sub1, sub2, sub3);
	}
}

// function to display data of students in array of objects
void displayDataOfStudents(StudentOfCdac *arr[], int size){
	cout << "sno\t prn\t name\t formNo.\t course\t batch\t subject1\t subject2\t subject3\t average\t" << endl;
	cout << "---------------------------------------------" << endl;
	for(int i = 0; i < size; i++){
	    cout << arr[i]->getSNo() << '\t'
		 << arr[i]->getPrn() << '\t'
		 << arr[i]->getName() << '\t'
		 << arr[i]->getFormNo() << '\t'
		 << arr[i]->getCourse() << '\t'
		 << arr[i]->getBatch() << '\t'
		 << arr[i]->getSubject1() << '\t'
		 << arr[i]->getSubject2() << '\t'
		 << arr[i]->getSubject3() << '\t'
		 << arr[i]->getAvgOfAllThreeSubjects() << endl;
	}
	cout << "---------------------------------------------" << endl;
}

int main(){
	int SIZE = 3;
	
	StudentOfCdac *arr[SIZE];
	acceptStudentDataInArray(arr , SIZE);
	displayDataOfStudents(arr, SIZE);
	updateMarksOfStudents(arr, SIZE);
	displayDataOfStudents(arr, SIZE);

	// delete the allocetd memory for eaech obj in the array of objects
	for (int i = 0; i < SIZE; i++) {
        	delete arr[i];
   	}

	return 0;

}

