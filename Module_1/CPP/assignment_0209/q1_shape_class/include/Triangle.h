#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle :public Shape{
    double side1, side2, side3;
    public:
        Triangle(char* c, double side1, double side2, double side3);
        double calculateArea() const override;
        double calculatePerimeter() const override;
        void serialize(ostream& os) const override;
        void deserialize(istream& is) override;
        void display();
        ~Triangle();
};

#endif