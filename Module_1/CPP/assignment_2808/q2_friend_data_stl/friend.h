
#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend{
	// default -> private
    static int count;
	int id;
	string name;
    vector<string> hobbies;
    vector<string> mobileNo;
    string email;
    string address;
    string bdate;

public:
    // default constructor
    Friend();

    // parameterised constructor
    Friend(string nm, string addr, string bd, string mail);

    // getters
    int getId();
    const string getName();
    vector<string> getHobbies();
    vector<string> getMobileNo();
    string getBdate();
    string getAddress();

    // setters
    void setName(string nm);
    void setHobbies(vector<string> &hobbies);
    void setMobileNo(vector<string> &mobileNo);
    void setAddress(string address);
    void setEmail(string email);
    void setBdate(string bdate);

    // method
    void display();

    // destructor
    ~Friend();
};


#endif
