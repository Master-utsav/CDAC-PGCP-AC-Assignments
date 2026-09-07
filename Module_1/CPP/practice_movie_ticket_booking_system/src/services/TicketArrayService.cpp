#include "TicketArrayService.h"
#include <iostream>
#include <algorithm>
#include<string>
#include <vector>
#include <memory>
#include <typeinfo>

using namespace std;

vector<shared_ptr<Ticket>> TicketArrayService::tk;

extern bool readFile(string filename, vector<shared_ptr<Ticket>> &tk);
extern bool writeFile(string filename, const vector<shared_ptr<Ticket>> &tk);

void TicketArrayService::LoadTheHistory(){
    bool status = readFile("./storage/mydata.txt", tk);
    if(status){
        cout << "Readed data successfully" << endl;
    }
    else{
        cout << "failed to fetch the data" << endl;
    }
}
void TicketArrayService::addNewTicket() {
    int choice;

    do {
        cout << "\n1. Regular Ticket\n"
             << "2. Premium Ticket\n"
             << "0. Exit\n"
             << "Enter your choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Exiting this menu..." << endl;
            return;
        }

        // Validate menu choice
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        string movieName;
        int year, noOfSeats;
        double price;
        vector<int> seatNumber;

        cout << "Enter the movie name: ";
        getline(cin, movieName);

        cout << "Enter the year: ";
        cin >> year;

        cout << "Movie Price: ";
        cin >> price;

        cout << "How many seats you want to book: ";
        cin >> noOfSeats;

        cout << "Enter the seat numbers you want to book: ";

        for (int i = 0; i < noOfSeats; i++) {
            int seatNo;
            cin >> seatNo;
            seatNumber.push_back(seatNo);
        }

        shared_ptr<Ticket> temp;

        if (choice == 1) {
            temp = make_shared<RegularTicket>(
                seatNumber,
                movieName,
                year,
                price
            );
        }
        else if (choice == 2) {
            char yesOrNo;

            cout << "Want the Recliner (Y/N): ";
            cin >> yesOrNo;

            bool hasRecliner = (yesOrNo == 'Y' || yesOrNo == 'y');

            temp = make_shared<PremiumTicket>(
                hasRecliner,
                seatNumber,
                movieName,
                year,
                price
            );
        }

        tk.push_back(temp);

        cout << "Ticket added successfully!" << endl;

    } while (true);
}

void TicketArrayService::displayAllTickets(){
    for (int i = 0; i < tk.size(); ++i){
        tk[i]->display();
    }
}

bool TicketArrayService::cancelBooking(){
    int id;
    cout << "Enter the Id of the booking : ";
    cin >> id;
    for (auto it = tk.begin(); it != tk.end(); ++it) {
        if ((*it)->getBookingId() == id) {
            tk.erase(it);
            return true;
        }
    }
    return false;
}

bool TicketArrayService::updateBookingSeatNumber(){
    vector<int> temp;
    int id, noOfSeats;
    cout << "Enter the Id of the booking : ";
    cin >> id;
    for (auto it = tk.begin(); it != tk.end(); ++it) {
        if ((*it)->getBookingId() == id) {
           cout << "How many seats you want to book : ";
            cin >> noOfSeats;
            cout << "Enter the seat numbers you want to book : ";
            for (int i = 0; i < noOfSeats; i++){
                int seatNo;
                cin >> seatNo;
                temp.push_back(seatNo);
            }
            (*it)->setSeatNumber(temp);
            cout << endl;
            return true;
        }
    }

    return false;
}

void TicketArrayService::SaveAndExit(){
    bool status = writeFile("./storage/mydata.txt", tk);
       if(status){
        cout << "Readed write successfully" << endl;
    }
    else{
        cout << "failed to write the data" << endl;
    }
}