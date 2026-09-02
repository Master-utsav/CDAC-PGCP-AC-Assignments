#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle :public Shape{
    double radius;
    public:
        Circle(char* c, double radius);
        double calculateArea() const override;
        void serialize(ostream& os) const override;
        void deserialize(istream& is) override;
        double calculatePerimeter() const override;
        void display();
        ~Circle();
};

#endif