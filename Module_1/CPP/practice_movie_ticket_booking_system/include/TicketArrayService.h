#ifndef TICKET_ARRAY_SERVICE_H
#define TICKET_ARRAY_SERVICE_H

#include "Ticket.h"
#include "RegularTicket.h"
#include "PremiumTicket.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;

class TicketArrayService{
    private:
        static vector<shared_ptr<Ticket>> tk;
    
    public:
        static void addNewTicket();
        static void displayAllTickets();
        static bool cancelBooking();
        static bool updateBookingSeatNumber();
        static void LoadTheHistory();
        static void SaveAndExit();
};

#endif