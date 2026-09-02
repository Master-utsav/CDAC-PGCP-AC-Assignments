#include <iostream>
#include "ShapeService.h"

using namespace std;

int main(){
    int choice = 0, id;
    bool status = false;
    double area, perimeter;

    // readdata("shapedata.txt",sArr,count);
    // cout<<count;
    cout << "Loading Previous Shape data...." << endl;
    status = ShapeService::loadPreviousShapeData();
    cout << (status ? "Loaded Successfully" : "Error while loading") << endl;

    do{
      cout << " 1. add new shape\n 2.calculate area by id\n 3.calculate perimeter by id\n ";
      cout << "4. display count of given type\n 5. display all\n 6.count all types\n 0. save & exit data\n";
      cin >> choice;
      
      switch(choice){
        case 1:
            // add new shape
            status = ShapeService::addNewShape();
            cout << (status ? "Shape added..." : "Shape NOT added...") << endl;
            break;
        case 2:
            // 2.calculate area by id
            cout << "enter id : ";
            cin >> id;
            area = ShapeService::findAreaById(id);
            cout << "Area : " << (area > 0 ? area  : -1) << endl;
            break;
        case 3:
            // 3.calculate perimeter by id
            cout << "enter id : ";
            cin >> id;
            perimeter = ShapeService::findPerimeterById(id);
            cout << "Perimeter : " << (perimeter > 0 ? perimeter  : -1) << endl;
            break;
        case 4:
            // 4. display count of given type
            ShapeService::countByType();
            break;
        case 5:
            // display all shape
            ShapeService::displayAll();
            break;
        case 6:
            ShapeService::countAll();
            break;
        case 0:
            // add new shape
            // writedata("shapedata.txt",sArr)
            status =  ShapeService::saveShapeData();
            cout << (status ? "Saved Successfully" : "Error while saving") << endl;
            cout << "Thankyou...." << endl;
            break;
        default:
            cout << "Wrong choice\n";
      }
      
    }while(choice != 0);
    return 0;
}