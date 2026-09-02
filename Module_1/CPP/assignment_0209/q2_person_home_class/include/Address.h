#ifndef ADDRESS_H
#define ADDRESS_H

class Address {
    private:
        char *street;
        char *city;
        char *state;
        int pin;

    public:
        Address();
        Address(const char *street, const char *city, const char *state, int pin);
        ~Address();
        void setStreet(const char *street);
        void setCity(const char *city);
        void setState(const char *state);
        void setPin(int pin);
        const char* getStreet() const;
        const char* getCity() const;
        const char* getState() const;
        int getPin() const;
};

#endif