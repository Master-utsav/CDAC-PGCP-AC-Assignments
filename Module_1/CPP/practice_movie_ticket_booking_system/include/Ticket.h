#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <vector>

using namespace std;

enum class BookingType{
    Regular,
    Premium,
};

class Ticket{
    private:
        int bookingId;
        static int nextBookingId;
        
    protected:
        BookingType type;
        string movieName;
        double price;
        int showYear;
        vector<int> seatNumbers;

        virtual double getPrice() const = 0;
        virtual void setPrice(double newPrice) = 0;

    public:
        Ticket(const vector<int>& seatNumbers, string movieName, int showYear, double price);

        int getBookingId() const { return bookingId; }

        void setBookingId(int id) { bookingId = id; }

        void setSeatNumber(vector<int>& seatNum){
            seatNumbers = seatNum;
        }

        static void setNextId(int nexId){
            nextBookingId = nextBookingId;
        }

        virtual void serialize(ostream &os) const = 0;
        virtual void deserialize(istream &is) = 0;

        virtual void display();

        ~Ticket();
};

#endif