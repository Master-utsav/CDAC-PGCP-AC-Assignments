#include <iostream>
#include <cstring>
#include "ShapeService.h"

using namespace std;

Shape *ShapeService::shapeArr[100];
int ShapeService::count = 0;

extern bool readData(const char* fileName, Shape **sh, int &count);
extern bool writeData(const char* fileName, Shape **sh, int count);

bool ShapeService::addNewShape(){
    char color[50]; 
    char *c;
    int choice;
    double len, br, radius, side1, side2, side3;
    
    cout << " 1. Add Rectangle\n 2. Add Circle\n 3. Add Triangle\n 0. Back to MENU\n";
    cin >> choice;

    cout << "enter color : " ;
    cin >> color;
    c = new char[strlen(color) + 1];
    strcpy(c, color);
 
    
    switch (choice){
        case 1:
            cout << "enter len : ";
            cin >> len;
            cout << "enter breadth : ";
            cin >> br;
            shapeArr[count++] = new Rectangle(c, len, br);
            break;
        case 2:
            cout << "enter radius : ";
            cin >> radius;
            shapeArr[count++] = new Circle(c, radius);
            break;
        case 3:
            cout << "enter side 1 : ";
            cin >> side1;
            cout << "enter side 2 : ";
            cin >> side2;
            cout << "enter side 3 : ";
            cin >> side3;
            shapeArr[count++] = new Triangle(c, side1, side2, side3);
            break;
        case 4:
            cout << "Backing to the menu..." << endl;
            break;
        default:
            cout << "Entered the wrong choice..." << endl;
    }
    if(count > 0 && shapeArr[count - 1] != nullptr) return true;
    else return false;
    return true;
}

void ShapeService::displayAll() {
    for(int i = 0; i < count; ++i){
        shapeArr[i]->display();
    }
}

int ShapeService::searchById(int id) {
    for(int i = 0; i <count; ++i){
        if(shapeArr[i]->getId() == id){
            return i;
        }
    }
    return -1;
}

double ShapeService::findAreaById(int id){
    int pos = searchById(id);
    if(pos == -1) return 0;
    return shapeArr[pos]->calculateArea();
}

double ShapeService::findPerimeterById(int id){
    int pos = searchById(id);
    if(pos == -1) return 0;
    return shapeArr[pos]->calculatePerimeter();
}

void ShapeService::countByType(){
    int choice, tCount =0, rCount=0, cCount=0;
    cout << " 1. Rectangle Count\n 2. Triangle Count\n 3. Circle Count\n 0. Back to MENU\n";
    cin >> choice;
  
    switch (choice){
        case 1:
            for(int i = 0; i < count; ++i){
                if(dynamic_cast<Rectangle* >(shapeArr[i])) rCount++;
            }
            cout << "Total Number of Rectangles are : " << rCount << endl;
            break;
        case 2:
            for(int i = 0; i < count; ++i){
                if(dynamic_cast<Triangle* >(shapeArr[i])) tCount++;
            }
            cout << "Total Number of Triangles are : " << rCount << endl;
            break;
        case 3:
            for(int i = 0; i < count; ++i){
                if(dynamic_cast<Circle* >(shapeArr[i])) cCount++;
            }
            cout << "Total Number of Circles are : " << rCount << endl;
            break;
        case 4:
            cout << "Backing to the menu..." << endl;
            break;
        default:
            cout << "Entered the wrong choice..." << endl;
    }

}

void ShapeService::countAll(){
    int tCount =0, rCount=0, cCount=0;
    for(int i =0; i < count; ++i){
        if(dynamic_cast<Rectangle* >(shapeArr[i])) rCount++;
        else if(dynamic_cast<Circle* >(shapeArr[i])) cCount++;
        else tCount++;
    }
    cout << "Triangle count: " << tCount << endl;
    cout << "Rectangle count: " << rCount << endl;
    cout << "Circle count: " << cCount << endl;
    cout << "----------------------------" << endl;
}

bool ShapeService::loadPreviousShapeData(){
    return readData("./storage/shape.txt", shapeArr, count);
}

bool ShapeService::saveShapeData(){
    return writeData("./storage/shape.txt", shapeArr, count);
}