
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
	// default -> private
	int id;
	char* name;
	int m1,m2,m3;
	
	public :
		// default constructor
		Student();

		// parameterised constructor
		Student(int id, char *name);
		
		// getters
		int getId();
		const char* getName();
		int getM1();
		int getM2();
		int getM3();
		double getGpa();

		// setters
		void setName(char *nm);
		void setM1(int m1);
		void setM2(int m2);
		void setM3(int m3);

		// method
		void display();

		// destructor
		~Student();
};

#endif
