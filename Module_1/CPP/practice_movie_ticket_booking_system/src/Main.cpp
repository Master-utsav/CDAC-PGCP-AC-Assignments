#include <iostream>
#include <memory>
#include <vector>
#include "TicketArrayService.h"

using namespace std;

int main(){
    int choice;
    bool status = false;
    TicketArrayService::LoadTheHistory();
    
    do{
        cout << "1. add new booking\n2. display All booking\n3. cancel booking\n4. update seat number\n5. save and exit\n";
        cin >> choice;

        switch(choice){
            case 1:
                TicketArrayService::addNewTicket();
                break;
            case 2:
                TicketArrayService::displayAllTickets();
                break;
            case 3:
                status = TicketArrayService::cancelBooking();
                cout << (status ? "cacelling done successfully\n" : "Fail to cancel the booking\n");
                break;
            case 4:
                status = TicketArrayService::updateBookingSeatNumber();
                cout << (status ? "update done successfully\n" : "Fail to update the seat number\n");
                break;
            case 5:
                TicketArrayService::SaveAndExit();
                break;
            default:
                cout << "Thanking for using...." << endl;
        }
    } while (choice != 5);

    return 0;
}