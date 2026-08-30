#include<iostream>
#include<cstring>
#include "student.h"
using namespace std;

	
Student::Student(){
	id=0;
	name=new char[1];
	name[0]='\0';
	m1=0;
	m2=0;
	m3=0;
	
}

Student::Student(int id, char* nm){
	this->id=id;
	this->name=new char[strlen(nm)+1];
	// cout << "name is : " << this->name << endl;
	strcpy(this->name,nm);
	// cout << "name is copied : " << this->name << endl;
	m1=0;
	m2=0;
	m3=0;

}
	// Getters 
int Student::getId(){
	return id;
}
const char* Student::getName(){
	return name;
}
int Student::getM1(){
	return m1;
}
int Student::getM2(){
	return m2;
}
int Student::getM3(){
	return m3;
}
double Student::getGpa(){
	return ((1.0 / 3) * m1) + ((1.0 / 2) * m2) + ((1.0 / 4) * m3);
}

//setter
void Student::setName(char* nm){
	if(name){
		delete[] name;
	}
	this->name = new char[strlen(nm) + 1];
	strcpy(this->name , nm);
}

void Student::setM1(int m1){
	this->m1 = m1;
}
void Student::setM2(int m2){
	this->m2 = m2;
}
void Student::setM3(int m3){
	this->m3 = m3;
}

// method
void Student::display(){
	cout <<"ID : " << id << "\t"
	     <<"name : " << name << "\t"
	     <<"M1 : " << m1 << "\t"
	     <<"M2 : " << m2 << "\t"
	     <<"M3 : " << m3 << "\t"
	     << endl;
}

Student::~Student(){
	if(name) 
		delete[] name;
}
