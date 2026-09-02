#include "Triangle.h"
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
Triangle::Triangle(char*c,  double s1, double s2, double s3): Shape(c), side1(s1), side2(s2), side3(s3) {
    // cout << "In Triangle constructor...." << endl;
    type = new char[strlen("Triangle") + 1];
    strcpy(type, "Triangle");
}

double Triangle::calculateArea() const {
  double semiPerimeter = (side1 + side2 + side3) / 2;
  double dummyProduct = (semiPerimeter + side1)*(semiPerimeter + side2)*(semiPerimeter + side3);
  double area = pow(semiPerimeter*dummyProduct , 0.5);
  return area;
}

double Triangle::calculatePerimeter() const {
  return (side1 + side2 + side3);
}

void Triangle::display(){
  Shape::display();
  cout << "Shape Type : " << type << " || "
       << "side 1 : " << side1 << " || "
       << "side 2 : " << side2 << " || "
       << "side 3 : " << side3 << endl;
  cout << "------------------" << endl;
}

void Triangle::serialize(ostream& os) const {
    // cout << "calling triangle serialize" << endl;
    // int triangleId = getId();
    // const char *triangleColor = getColor();
    // const char *triangleAsType = getType();
    // os << "Id : " << triangleId << " || "
    //    << "Color : " << triangleColor << " || "
    //    << "Type : " << triangleAsType << " || "
    //    << "Side 1 : " << side1 << " || "
    //    << "Side 2 : " << side2 << " || "
    //    << "Side 3 : " << side3 << endl;

    // os.write(reinterpret_cast<char*>(&triangleId), sizeof(triangleId));
    // os.write(reinterpret_cast<char*>(&triangleColor), sizeof(triangleColor));
    // os.write(reinterpret_cast<char*>(&triangleAsType), sizeof(triangleAsType));
    // os.write(reinterpret_cast<const char*>(&side1), sizeof(side1));
    // os.write(reinterpret_cast<const char*>(&side2), sizeof(side2));
    // os.write(reinterpret_cast<const char*>(&side3), sizeof(side3));

    int len_type = strlen(type);
    os.write(reinterpret_cast<char *>(&len_type), sizeof(len_type));
    os.write(type, len_type);

    int triangleId = getId();
    os.write(reinterpret_cast<char *>(&triangleId), sizeof(triangleId));

    const char *c = getColor();
    int len_color = strlen(c);
    os.write(reinterpret_cast<char *>(&len_color), sizeof(len_color));
    os.write(c, len_color);

    os.write(reinterpret_cast<const char *>(&side1), sizeof(side1));
    os.write(reinterpret_cast<const char *>(&side2), sizeof(side2));
    os.write(reinterpret_cast<const char *>(&side3), sizeof(side3));

    // cout << "end of triangle serialize" << endl;
} 
void Triangle::deserialize(istream& is) {

  // cout << "calling triangle deserialize" << endl;
  // int triangleId = getId();
  // const char *triangleColor = getColor();
  // const char *triangleAsType = getType();
  // is.read(reinterpret_cast<char*>(&triangleId), sizeof(triangleId));
  // is.read(reinterpret_cast<char*>(&triangleColor), sizeof(triangleColor));
  // is.read(reinterpret_cast<char*>(&triangleAsType), sizeof(triangleAsType));
  // is.read(reinterpret_cast<char*>(&side1), sizeof(side1));
  // is.read(reinterpret_cast<char*>(&side2), sizeof(side2));
  // is.read(reinterpret_cast<char*>(&side3), sizeof(side3));
  
  // Read the triangle ID
  int triangleId;
  is.read(reinterpret_cast<char *>(&triangleId), sizeof(triangleId));
  setId(triangleId); 
   
  // Read the color string
  int len_color;
  is.read(reinterpret_cast<char *>(&len_color), sizeof(len_color));
  char *colorBuf = new char[len_color + 1];
  is.read(colorBuf, len_color);
  colorBuf[len_color] = '\0';
  setColor(colorBuf);
  delete[] colorBuf;

  is.read(reinterpret_cast<char *>(&side1), sizeof(side1));
  is.read(reinterpret_cast<char *>(&side2), sizeof(side2));
  is.read(reinterpret_cast<char *>(&side3), sizeof(side3));

  // cout << "end of triangle deserialize" << endl;
}


Triangle::~Triangle(){
    cout << "in Triangle destructor...." << endl;
};