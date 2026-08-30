#ifndef STUDENT_ARRAY_SERVICE_H
#define STUDENT_ARRAY_SERVICE_H

#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

class StudentArray{
	static constexpr int MAX = 100;
	static int count;
	static Student *arr[MAX]; // this will throw constant value expression error so make MAX -> constexpr

public:
	  static bool acceptData(){
	       int id;
	       char name[100];
	       cout << "Enter the id : ";
	       cin >> id;
	       cin.ignore();
	       cout << "Enter the name : ";
	       cin >> name;
	    //    cout << "before inst" << endl;
	       arr[count] = new Student(id, name);
	    //    cout << "after inst" << endl;
	       count++;
	       return true;
	  }

	  static bool updateStudentMarks(int &id){
	       Student *s = searchById(id);
	       if(s == NULL) return false;
	       int m1, m2, m3;
	       cout << "Enter the marks of M1 : ";
	       cin >> m1;
	       cout << "Enter the marks of M2 : ";
	       cin >> m2;
	       cout << "Enter the marks of M3 : ";
	       cin >> m3;
	       s->setM1(m1);
	       s->setM2(m2);
	       s->setM3(m3);

	       if((s->getM1() != 0) && (s->getM2() != 0) && (s->getM3() != 0)) return true;
	       else return false;
	  }

	  static void displayAllStudent(){
		  for(int i = 0; i < count; i++){
			  arr[i]->display();
			  cout << "---------------------------" << endl;
		  }
	  }

	  static Student* searchById(int id){
                 for(int i = 0; i < count; i++){
			 if(arr[i]->getId() == id) return arr[i];
		 }
		 return NULL;
	  }

	  // DONE search by Name
	  static void searchByName(char *nm){
		 //  int nameCount = 0;
		  for(int i = 0; i < count; i++){
			  if(strcmp(arr[i]->getName() , nm) == 0) {
				 arr[i]->display();
				 cout << "------------------------------" << endl;
			  }
		  }
		  // return nameCount;
	  }


};

int StudentArray::count = 0;
Student *StudentArray::arr[MAX] = {NULL};

#endif
