#include "Shape.h"
#include <cstring>
#include <iostream>
using namespace std;

int Shape::countShape = 0;

Shape::Shape(char *c){
    // cout<< "In shape constructor..." << endl;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
    this->id = ++countShape;
}

void Shape::display(){
    cout << "id : " << id << " || "
         << "color : " << color << " || ";
}

Shape::~Shape(){
    cout << "in shape destructor...." << endl;
    delete[] color;
}
