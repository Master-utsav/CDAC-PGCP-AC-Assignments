#include <iostream>
#include "student_array_service.h"
#include "student.h"

using namespace std;

int main(){

        int choice = 0;
	Student *arr[100];

	do{
	  cout << " 1. Add Student Data\n 2. Update Student Mark\n 3. Display All Student\n 4. Search by Id\n 5. Search by Name\n 6. Calculate GPA of Student\n 7. exit" << endl;
	  cin >> choice;
          
	  int id;
	  bool status;
	  Student *sptr;
	  char name[100];
	  int sizeOfSptrArr;
	  double gpa;

	  switch(choice){
		  case 1:
			 status = StudentArray::acceptData();
			 cout << (status ? "added successfully" : "error while adding...") << endl;
			 break;
	          case 2:
			 cout << "Enter id of the student for marks update : ";
                         cin >> id;
			 status = StudentArray::updateStudentMarks(id);
			 cout << (status ? "update successfully" : "failed to update...") << endl;
			 break;
		  case 3:
			 StudentArray::displayAllStudent();
			 break;
	          case 4:
			cout << "Enter id of Student you want to search : ";
                        cin >> id;
			sptr = StudentArray::searchById(id); 
			if(sptr == NULL) cout << "Not Found" << endl;
			else sptr->display();
			break;
		  case 5:
			cout << "Enter name of the student : ";
		        cin >> name;
		        StudentArray::searchByName(name);
			break;
		  case 6:
			cout << "Enter id of student for GPA : ";
			cin >> id;
			sptr = StudentArray::searchById(id);
			if(sptr == NULL) cout << "NOT FOUND" << endl;
			else{
		            gpa = sptr->getGpa();
			    cout << "GPA for id : " << id << " is : " << gpa << endl;
			}
			break;
		  case 7:
			cout << "Thankyou for you support" << endl;
			cout << "This code is written by utsav and sumit (this is highly standardized)" << endl;
		        cout << "THIS IS NOT GPT -> A HUMAN WHO CODES LIKE GPT" << endl;
			break;	
		  default:
			cout<< "\nInvalid choice!";
	  }	  
	
	}while(choice != 7);

	return 0;
}
