#include<iostream>
#include<cstring>
#include "friend.h"
using namespace std;

int Friend::count = 0;

Friend::Friend(){
	id=Friend::count++;
	name = "";
    address = "";
    bdate = "";
    email = "";
    mobileNo.clear();
    hobbies.clear();
}

Friend::Friend(string nm, string addr, string bd, string mail){
	this->id=Friend::count++;
    this->name=nm;
    this->address=addr; 
    this->bdate=bd;
    this->email=mail;
    mobileNo.clear();
    hobbies.clear();

}
	// Getters 
int Friend::getId(){
	return id;
}
const string Friend::getName(){
	return name;
}
vector<string> Friend::getHobbies(){
    return hobbies;
}
vector<string> Friend::getMobileNo(){
    return mobileNo;
}
string Friend::getBdate(){
    return bdate;
}
string Friend::getAddress(){
    return address;
}


//setter
void Friend::setName(string nm){
    this->name = nm;
}
void Friend::setHobbies(vector<string> &hobbies){
    this->hobbies = hobbies;
}
void Friend::setMobileNo(vector<string> &mobileNo){
    this->mobileNo = mobileNo;
}
void Friend::setAddress(string address){
    this->address = address;
}
void Friend::setEmail(string email){
    this->email = email;
}
void Friend::setBdate(string bdate){
    this->bdate = bdate;
}

// method
void Friend::display(){
    cout << "Id : " << id << endl;
    cout << "Name : " << name << endl;
    cout << "Address : " << address << endl;
    cout << "Birthdate : " << bdate << endl;
    cout << "Email : " << email << endl;

    cout << "Mobile Numbers : ";
    for(int i = 0; i < mobileNo.size(); i++){
        cout << mobileNo[i] << ", ";
    }
    cout << endl;

    cout << "Hobbies : ";
    for(int i = 0; i < hobbies.size(); i++){
        cout << hobbies[i] << ", ";
    }
    cout << endl;
}

Friend::~Friend(){
	cout << "Destructor called for Friend with id : " << id << endl;
}
