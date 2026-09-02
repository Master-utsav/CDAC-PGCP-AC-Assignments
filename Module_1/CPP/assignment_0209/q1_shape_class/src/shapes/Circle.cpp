#include "Circle.h"
#include <iostream>
#include <cstring>

using namespace std;
Circle::Circle(char*c,  double r): Shape(c), radius(r) {
    // cout << "In Circle constructor...." << endl;
    char *shapeType = new char[strlen("Circle") + 1];
    type = new char(strlen("Circle") + 1);
    strcpy(type, "Circle");
}

double Circle::calculateArea() const {
  return (3.14 * this->radius * this->radius);
}
double Circle::calculatePerimeter() const {
  return (2 * 3.14 * this->radius);
}

void Circle::display(){
  Shape::display();
  cout << "Shape Type : " << type << " || "
       << "radius : " << radius << endl;
  cout << "------------------" << endl;
}

void Circle::serialize(ostream& os) const {
  // cout << "end of circle serialize" << endl;
    // int circleId = getId();
    // const char *circleColor = getColor();
    // const char *circleAsType = getType();
    // os << "Id : " << circleId << " || "
    //    << "Color : " << circleColor << " || "
    //    << "Type : " << circleAsType << " || "
    //    << "Radius : " << radius << endl;

    // os.write(reinterpret_cast<char*>(&circleId), sizeof(circleId));
    // os.write(reinterpret_cast<char*>(&circleColor), sizeof(circleColor));
    // os.write(reinterpret_cast<char*>(&circleAsType), sizeof(circleAsType));
    // os.write(reinterpret_cast<const char*>(&radius), sizeof(radius));

    // writing the length of the type string first, then the type string itself, and then the rest of the data.
    int len_type = strlen(type);
    os.write(reinterpret_cast<char *>(&len_type), sizeof(len_type));
    os.write(type, len_type);

    int circleId = getId();
    os.write(reinterpret_cast<char *>(&circleId), sizeof(circleId));
    
    // writing the length of the color string first, then the color string itself, and then the rest of the data.
    const char *c = getColor();
    int len_color = strlen(c);
    os.write(reinterpret_cast<char *>(&len_color), sizeof(len_color));
    os.write(c, len_color);

    os.write(reinterpret_cast<const char *>(&radius), sizeof(radius));
    // cout << "end of circle serialize" << endl;  
} 

void Circle::deserialize(istream& is) {
  // cout << "calling circle deserialize" << endl;
  // is.read(reinterpret_cast<char*>(&circleId), sizeof(circleId));
  // is.read(reinterpret_cast<char*>(&circleColor), sizeof(circleColor));
  // is.read(reinterpret_cast<char*>(&circleAsType), sizeof(circleAsType));
  // is.read(reinterpret_cast<char*>(&radius), sizeof(radius));

  int circleId;
  is.read(reinterpret_cast<char *>(&circleId), sizeof(circleId));
  setId(circleId); // assuming Shape exposes setId()
  
  // Read the color string
  int len_color;
  is.read(reinterpret_cast<char *>(&len_color), sizeof(len_color));
  char *colorBuf = new char[len_color + 1];
  is.read(colorBuf, len_color);
  colorBuf[len_color] = '\0';
  setColor(colorBuf);
  delete[] colorBuf;

  is.read(reinterpret_cast<char *>(&radius), sizeof(radius));
  // cout << "end of circle deserialize" << endl;
}

Circle::~Circle(){
    cout << "in Circle destructor...." << endl;
};