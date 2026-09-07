#include<fstream>
#include<stdexcept>
#include<iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include "Ticket.h"
#include "RegularTicket.h"
#include "PremiumTicket.h"

using namespace std;

bool writeFile(string filename, const vector<shared_ptr<Ticket>> &vt){
    
    try{
        ofstream outfile(filename, ios::binary);
        if(!outfile){
            throw(runtime_error("error in writing the file or file might not exists..."));
            return false;
        }

        for(auto &it : vt){
        cout << "Writing in file" << endl;
            if (it != nullptr) {
                it->serialize(outfile);
            }
        }

        outfile.close();
        cout << "Write successfully inside the " << filename << endl;
        return true;  

    }
    catch(runtime_error &e){
        cout << "error : " << e.what() << endl;
    }

    return false;
}

bool readFile(string filename, vector<shared_ptr<Ticket>> &vt){
    
    try{
        ifstream infile(filename, ios::binary);
        if(!infile){
            throw(runtime_error("error in reading the file or file might not exists..."));
            return false;
        }

        BookingType type;
        while(infile.peek() != EOF){
            if(!infile.read(reinterpret_cast<char *>(&type), sizeof(type))){
                throw(runtime_error("no file left to read"));
                return false;
            }

            vector<int> st;
            if(type == BookingType::Regular){
                shared_ptr<Ticket> temp = make_shared<RegularTicket>(st, "", 0, 0);
                temp->deserialize(infile);
                vt.push_back(temp);
            }
            else if(type == BookingType::Premium){
                shared_ptr<Ticket> temp = make_shared<PremiumTicket>(false, st, "", 0, 0);
                temp->deserialize(infile);
                vt.push_back(temp);
            }
            else{
                throw("no such type found...");
            }
        }
        infile.close();
        cout << "Write successfully inside the " << filename << endl;

        int maxId = 0;
        for (auto &t : vt) {
            if (t->getBookingId() > maxId) maxId = t->getBookingId();
        }
        Ticket::setNextId(maxId + 1);
        return true;  

    }
    catch(runtime_error &e){
        cout << "error : " << e.what() << endl;
    }

    return false;
}