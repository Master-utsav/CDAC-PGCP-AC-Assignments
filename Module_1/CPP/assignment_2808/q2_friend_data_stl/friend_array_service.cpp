#include <iostream>
#include <string>
#include <vector>
#include "friend_array_service.h"

using namespace std;

// Static member initializ
vector<Friend*> FriendArray::friends;

// Accept data for a new friend
bool FriendArray::acceptData() {
    string name, address, bdate, email;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter Birthdate: ";
    cin >> bdate;
    cout << "Enter Email: ";
    cin >> email;
    
    // Create a new Friend object and add it to the friends vector
    Friend* fr = new Friend(name, address, bdate, email);

    friends.push_back(fr);

    return true;
}

// Display data for all friends
void FriendArray::displayData() {
    if (friends.empty()) {
        cout << "No friends available." << endl;
        return;
    }

    for (Friend* fr : friends) {
        fr->display();
        cout << "------------------------" << endl;
    }
}

// Add hobbies for a friend by ID
bool FriendArray::addHobbies() {
    int id;
    string hobby;

    cout << "Enter Friend ID: ";
    cin >> id;

    for (Friend* fr : friends) {
        if (fr->getId() == id) {
            // Get the current hobbies, add a new hobby, and update the Friend object
            vector<string> hobbies = fr->getHobbies();

            cout << "Enter Hobby: ";
            cin >> hobby;

            hobbies.push_back(hobby);
            fr->setHobbies(hobbies);
            return true;
        }
    }
    return false;
}

// Add mobile number for a friend by ID
bool FriendArray::addMobileNumber() {
    int id;
    string mobile;

    cout << "Enter Friend ID: ";
    cin >> id;

    for (Friend* fr : friends) {
        if (fr->getId() == id) {
            // Get the current mobile numbers, add a new mobile number, and update the Friend object
            vector<string> mobileNumbers = fr->getMobileNo();

            cout << "Enter Mobile Number: ";
            cin >> mobile;

            mobileNumbers.push_back(mobile);
            fr->setMobileNo(mobileNumbers);

            return true;
        }
    }

    return false;
}

// updating address 
bool FriendArray::updateAddress() {
    int id;
    string address;
    cout << "Enter Friend ID: ";
    cin >> id;

    for (Friend* fr : friends) {
        if (fr->getId() == id) {

            cout << "Enter New Address: ";
            cin >> address;

            fr->setAddress(address);

            return true;
        }
    }
    return false;
}

// Search for a friend by ID
Friend* FriendArray::searchById() {
    int id;

    cout << "Enter Friend ID: ";
    cin >> id;
    for (Friend* fr : friends) {
        if (fr->getId() == id) {
            return fr;
        }
    }
    return NULL;
}
// Search for friends by name
vector<Friend*> FriendArray::searchByName() {
    string name;
    vector<Friend*> result;

    cout << "Enter Friend Name: ";
    cin >> name;

    for (Friend* fr : friends) {
        if (fr->getName() == name) {
            result.push_back(fr);
        }
    }

    return result;
}

// Display all friends with a specific hobby
void FriendArray::displayAllFriendWithSearchByHobby(string hobby) {

    bool found = false;

    for (Friend* fr : friends) {

        vector<string> hobbies = fr->getHobbies();

        for (string h : hobbies) {
            if (h == hobby) {
                fr->display();
                cout << "------------------------" << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No friend found with hobby: " << hobby << endl;
    }
}
