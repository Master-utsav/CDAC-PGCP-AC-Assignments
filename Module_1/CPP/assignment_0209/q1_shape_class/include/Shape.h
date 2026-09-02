#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<cstring>
using namespace std;

class Shape{
    private:
      static int countShape;
      int id;
      char *color;

    protected:
      char *type;

    public:
        Shape(char* c);
        virtual ~Shape();

        // To save polymorphic objects (like shapes), 
        // each class must know how to write and read its own unique properties. 
        // The standard C++ way to handle this is by defining virtual write and read functions.
        virtual void serialize(ostream& os) const = 0;
        virtual void deserialize(istream& is) = 0;

        virtual double calculateArea() const = 0;

        int getId() const {
            return id;
        }
        const char* getColor() const {
            return color;
        }
        const char* getType() const {
            return type;
        }
        void setId(int newId){
            id = newId;
        }
        void setColor(const char* newColor){
            if(color) delete[] color; 
            color = new char[strlen(newColor) + 1];
            strcpy(color, newColor);
        }

        virtual void display();
        virtual double calculatePerimeter() const = 0;
};

#endif