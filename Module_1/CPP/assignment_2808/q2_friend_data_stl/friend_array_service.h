#ifndef FRIEND_ARRAY_SERVICE_H
#define FRIEND_ARRAY_SERVICE_H

#include "friend.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FriendArray {
private:
// Static member to hold the array of Friend pointers
    static vector<Friend*> friends;

public:
// Static methods to manage Friend objects
    static bool acceptData();
    static void displayData();
// Static methods to add hobbies, mobile numbers, and update addresses
    static bool addHobbies();
    static bool addMobileNumber();
    static bool updateAddress();
// Static methods to search for friends by ID and name
    static Friend* searchById();
    static vector<Friend*> searchByName();
// Static method to display all friends with a specific hobby
    static void displayAllFriendWithSearchByHobby(string hobby);
};

#endif
