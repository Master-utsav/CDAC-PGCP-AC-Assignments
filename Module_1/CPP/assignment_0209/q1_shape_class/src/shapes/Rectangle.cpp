#include "Rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;
Rectangle::Rectangle(char*c , double l, double b): Shape(c), len(l), br(b){
    // cout << "In Rectangle constructor...." << endl;
    type = new char[strlen("Rectangle") + 1];
    strcpy(type, "Rectangle");
}

double Rectangle::calculateArea() const {
    // cout << "in rect. calculate area" << endl;
  return this->len * this->br;
}
double Rectangle::calculatePerimeter() const  {
  return 2*(this->len + this->br);
}

void Rectangle::display(){
  Shape::display();
  cout << "Shape Type : " << type << " || "
       << "length : " << len << " || "
       << "breadth : " << br << endl;
  cout << "------------------" << endl;
}

void Rectangle::serialize(ostream& os) const {
  // cout << "calling rectangle serialize" << endl;
  // int rectangleId = getId();
  // const char *rectangleColor = getColor();
  // const char *rectangleAsType = getType();
  // os << "Id : " << rectangleId << " || "
  //    << "Color : " << rectangleColor << " || "
  //    << "type : " << type << " || "
  //    << "Length : " << len << " || "
  //    << "Breadth : " << br << endl;

  // os.write(reinterpret_cast<char *>(&rectangleId), sizeof(rectangleId));
  // os.write(reinterpret_cast<char *>(&rectangleColor), sizeof(rectangleColor));
  // os.write(reinterpret_cast<char *>(&rectangleAsType), sizeof(rectangleAsType));
  // os.write(reinterpret_cast<const char *>(&len), sizeof(len));
  // os.write(reinterpret_cast<const char *>(&br), sizeof(br));
  
  // writing the length of the type string first, then the type string itself, and then the rest of the data.
  int len_type = strlen(type);
  os.write(reinterpret_cast<char *>(&len_type), sizeof(len_type));
  os.write(type, len_type);
  
  int rectangleId = getId();
  os.write(reinterpret_cast<char *>(&rectangleId), sizeof(rectangleId));
  
  // writing the length of the color string first, then the color string itself, and then the rest of the data.
  const char *c = getColor();
  int len_color = strlen(c);
  os.write(reinterpret_cast<char *>(&len_color), sizeof(len_color));
  os.write(c, len_color);

  os.write(reinterpret_cast<const char *>(&len), sizeof(len));
  os.write(reinterpret_cast<const char *>(&br), sizeof(br));

  // cout << "end of rectangle serialize" << endl;

  delete[] c;
} 

void Rectangle::deserialize(istream& is) {
  // cout << "calling rectangle deserialize" << endl;
  
  // is.read(reinterpret_cast<char*>(&rectangleId), sizeof(rectangleId));
  // is.read(reinterpret_cast<char*>(&rectangleColor), sizeof(rectangleColor));
  // is.read(reinterpret_cast<char*>(&rectangleAsType), sizeof(rectangleAsType));
  // is.read(reinterpret_cast<char*>(&len), sizeof(len));
  // is.read(reinterpret_cast<char*>(&br), sizeof(br));
  
  // Read the rectangle ID
  int rectangleId;
  is.read(reinterpret_cast<char *>(&rectangleId), sizeof(rectangleId));
  setId(rectangleId); // assuming Shape exposes setId()
  
  // Read the color string
  int len_color;
  is.read(reinterpret_cast<char *>(&len_color), sizeof(len_color));
  char *colorBuf = new char[len_color + 1];
  is.read(colorBuf, len_color);
  colorBuf[len_color] = '\0';
  setColor(colorBuf);
  delete[] colorBuf; 

  is.read(reinterpret_cast<char *>(&len), sizeof(len));
  is.read(reinterpret_cast<char *>(&br), sizeof(br));

  // cout << "end of rectangle deserialize" << endl;
}

Rectangle::~Rectangle(){
    cout << "in rectangle destructor...." << endl;
}