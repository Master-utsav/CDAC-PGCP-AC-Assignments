#include <iostream>
#include "friend.h"
#include "friend_array_service.h"
using namespace std;

int main() {
	int choice = 0;
    bool status;
    Friend *fr;
    vector<Friend *> friendsName;
    string hobby;
    do {
		cout << "\n1. Accept Data\n2. Display Data\n3. Add Hobbies"
			 << "\n4. Add Mobile Number\n5. Update Address\n6. Search By ID"
			 << "\n7. Search By Name\n8. Display All Friend With Search By Hobby"
			 << "\n9. Exit\nEnter choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
                status = FriendArray::acceptData();
                cout << (status ? "Data accepted successfully." : "Error while accepting data.") << endl;
                break;
			case 2: 
                FriendArray::displayData(); 
                break;
			case 3: 
                status = FriendArray::addHobbies(); 
                cout << (status ? "Hobbies added successfully." : "Error while adding hobbies.") << endl;
                break;
			case 4: 
                status = FriendArray::addMobileNumber(); 
                cout << (status ? "Mobile number added successfully." : "Error while adding mobile number.") << endl;
                break;
			case 5: 
                status = FriendArray::updateAddress(); 
                cout << (status ? "Address updated successfully." : "Error while updating address.") << endl;
                break;
			case 6: 
                fr = FriendArray::searchById();
                if (fr == NULL) {
                    cout << "Friend not found." << endl;
                } else {
                    fr->display();
                } 
                break;
			case 7:
                friendsName = FriendArray::searchByName();
                if (friendsName.empty()) {
                    cout << "Friend not found." << endl;
                } else {
                    for (auto f : friendsName) {
                        f->display();
                    }
                }
                break;
			case 8: 
                cout << "Enter hobby to search: ";
                cin >> hobby;
                FriendArray::displayAllFriendWithSearchByHobby(hobby); 
                break;
			case 9: 
                cout << "Exiting...\n"; 
                break;
			default: 
                cout << "Invalid choice.\n";
		}

	} while (choice != 9);
	return 0;
}
