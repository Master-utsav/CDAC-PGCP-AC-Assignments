#ifndef PERSON_H
#define PERSON_H

#include "Address.h"

class Person {
    private:
        char *name;
        int age;
        Address *address[10]; // max limit 10
        static int addressCount;
        int id;
        static int nextId;

    public:
        Person();
        Person(const char *name, int age);
        ~Person();
        void setName(const char *name);
        void setAge(int age);
        void setAddress(Address **address);
        const char* getName() const;
        int getAge() const;
        Address* getAddress() const;
        int getId() const;
        void display() const;
};


#endif