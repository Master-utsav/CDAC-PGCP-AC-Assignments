#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main(){
    Shape *s = nullptr;
    s = new Rectangle("red", 5, 3);
    s->calculateArea();

    Shape *s1 = new Circle("blue" , 3);
    s1->display();
    delete s;
    delete s1;
    return 0;
}