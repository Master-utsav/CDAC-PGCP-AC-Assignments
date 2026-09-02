// 1. Add new Person 2. Display All Person 3. Search by Id 5. Search by Name 6. Modify address;
// 7. find address by id of Person 8. display all Person stay in given city-- -- --> (accept city from user)9. Exit

#include <iostream>
#include <ArrayService.h>

using namespace std;

int main(){
    int choice;
    
    do{
        cout << "Welcome to Person Management System" << endl;
        cout << "1. Add new Person" << endl;
        cout << "2. Add address to Person as per Id" << endl;
        cout << "3. Display All Person" << endl;
        cout << "4. Search by Id" << endl;
        cout << "5. Search by Name" << endl;
        cout << "6. Modify address" << endl;
        cout << "7. Find address by id of Person" << endl;
        cout << "8. Display all Person stay in given city" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                ArrayService::addPerson();
                break;
            case 2:
                ArrayService::addAddressToPerson();
                break;
            case 3:
                ArrayService::displayAllPersons();
                break;
            case 4:
                ArrayService::searchById();
                break;
            case 5:
                ArrayService::searchByName();
                break;
            case 6:
                ArrayService::modifyAddress();
                break;
            case 7:
                ArrayService::findAddressById();
                break;
            case 8:
                ArrayService::displayPersonsInCity();
                break;
            case 9:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    }while(choice != 9);

    return 0;
}