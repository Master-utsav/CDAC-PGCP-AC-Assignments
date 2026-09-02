#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle :public Shape{
    double len, br;
    public:
        Rectangle(char* c, double len, double br);
        double calculateArea() const override;
        double calculatePerimeter() const override;
        void serialize(ostream& os) const override;
        void deserialize(istream& is) override;
        void display();
        ~Rectangle();
};

#endif