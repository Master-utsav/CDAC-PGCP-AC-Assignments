#ifndef SHAPE_SERVICE_H
#define SHAPE_SERVICE_H

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

class ShapeService{

    private:
        static Shape *shapeArr[100];
        static int count;

    public:
        static bool addNewShape();
        static void displayAll();

        static int searchById(int id);
        static double findAreaById(int id);
        static double findPerimeterById(int id);
        
        static void countByType();
        static void countAll();

        static bool loadPreviousShapeData();
        static bool saveShapeData();

};

#endif