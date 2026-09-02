#include<iostream>
#include<fstream>
#include<cstring>
#include <typeinfo>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

bool writeData(const char* fileName, Shape **sh, int count){
    ofstream outfile(fileName , ios::binary);

    if(!outfile){
        cerr << "File Not Found..." << endl;
        return false;
    }

    // binary insertion -> serialization

    // for(int i = 0; i < count; i++){
    //      outfile.write(reinterpret_cast<char *>(&sh[i]), sizeof(sh[i]));
    // }

    /* The provided code contains a critical bug: it is attempting to serialize and deserialize 
       raw memory addresses (pointers) instead of the    actual object data.
       When you write &sh[i] to a file, you are saving the memory address where the Shape object lives. 
       When the program restarts or runs on another computer, those memory addresses become invalid, 
       leading to crashes (segmentation faults) or corrupted data. 
       Furthermore, because Shape is likely a polymorphic base class, 
       standard binary dumping (sizeof(Shape)) will fail to capture derived class data and will corrupt the virtual table pointer (vptr).
       outfile.write(reinterpret_cast<char *>(&count), sizeof(count));
    */

    // Ask each object to write its own data
    for(int i = 0; i < count; i++){
        cout << "Writing in file" << endl;
        if (sh[i] != nullptr) {
            // cout << "inside writing file if statement" << endl;
            sh[i]->serialize(outfile);
        }
    }
    outfile.close();
    cout << "Write successfully inside the " << fileName << endl;
    return true;
}


bool readData(const char* fileName, Shape **sh, int &count){
    ifstream infile(fileName, ios::binary);

    if(!infile){
        cerr << "File Not Found..." << endl;
        return false;
    }

    // binary fetch-> deserialization
    // Shape* s = nullptr;
    // while (infile.read(reinterpret_cast<char *>(&s), sizeof(s))){
    //     if (s != nullptr){
    //         sh[count++] = s;
    //     }
    // }
    
    // bahut complicated hai -> CAUTION
    // in this we read the type first, then we create the appropriate object based on that type, and finally we call the deserialize method to read the rest of the object's data.
    int len_type;
    // read the type length first, then read the type string, and based on that.
    // while (infile.read(reinterpret_cast<char *>(&len_type), sizeof(len_type))){ //! if i did this only one object will be read
    while (infile.peek() != EOF) { // this will read all the objects
        if(!infile.read(reinterpret_cast<char *>(&len_type), sizeof(len_type))){
            cerr << "Error reading type length from file." << endl;
            return false;
        }

        // creating buffer string to read the tye
        char* typeStr = new char[len_type + 1];
        // reading the type string from the file
        infile.read(typeStr, len_type);
        // setting the null at end of buffer string (typeStr)
        typeStr[len_type] = '\0';
        // creating a Sahpe obj
        Shape* s = nullptr;
        // for dummy values for cinstructor beacuse in deserialize actual values will be set 
        char *colorBuf = new char[0];
        colorBuf[0] = '\0';
        
        // based on the type string, we create the appropriate derived class object
        // or we can use the default  constructro of the derived class -> but we need to pass only color 
        if (strcmp(typeStr, "Rectangle") == 0) s = new Rectangle(colorBuf, 0, 0);
        else if (strcmp(typeStr, "Circle") == 0) s = new Circle(colorBuf, 0);
        else if (strcmp(typeStr, "Triangle") == 0) s = new Triangle(colorBuf, 0, 0, 0);
        // deallocating the memory for typeStr and colorBuf after using it
        delete[] typeStr;
        delete[] colorBuf;
        
        // s != null
        if (s) {
            // calling it override descerialize
            s->deserialize(infile);
            sh[count++] = s;
        }
    }

        infile.close();
        cout << "Readed successfully from the " << fileName << endl;
        return true;
}
