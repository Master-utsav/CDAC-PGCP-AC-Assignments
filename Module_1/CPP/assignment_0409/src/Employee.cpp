#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;

// 3. Write a program to save employees in map, id as key and object as a value
// Employee contains id and name
// 1. Add a new employee
// 2. Delete employee by id
// 3. Display all
// 4. Display by id
// 5. Display by name

class Employee{
    private:
        int id;
        string name;
        static int nextId; 
    public:
        Employee(): id(nextId++), name("Guest"){};
        Employee(string name): id(nextId++), name(name){};

        void display(){
            cout << "ID : " << id << " || " 
                 << "Name : " << name << endl;
            cout << "---------------------------" << endl; 
        }

        int getId(){ return id;}
        string getName(){ return name;}

        ~Employee(){};

};

int Employee::nextId = 1;

int main(){
    map<int, shared_ptr<Employee>> empmap;

    int choice , id;

    do{
        cout << "1. Add a new Employee\n2. Delete employee by id\n3. Display all\n4. Display by id\n5. Display by name\n0. Exit\n";
        cin >> choice;
        string empName;
        shared_ptr<Employee> emp;

        switch(choice){
            case 1:
                // add a new employee
                cout << "Enter the name of the employee : ";
                cin >> empName;
                emp = make_shared<Employee>(empName);
                empmap[emp.get()->getId()] = emp;
                cout << "Added to map successfully" << endl;
                cout << "----------------------------------" << endl;
                break;
            case 2:
                // delete employee by id
                cout << "Enter the id of the employee : ";
                cin >> id;
                if(empmap[id]){
                    empmap.erase(id);
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Failed to delete the employee of id " << id << endl;
                }
                cout << "----------------------------------" << endl;
                break;
            case 3:
                // Display all
                for(auto &it : empmap){
                    it.second.get()->display();
                }
                cout << "----------------------------------" << endl;
                break;
            case 4:
                // Display by id
                cout << "Enter the id of the employee : ";
                cin >> id;
                if(empmap.find(id) != empmap.end()){
                    empmap[id].get()->display();
                }
                else{
                    cout << "No employee have id : " << id << endl;
                }
                cout << "----------------------------------" << endl;
                break;
            case 5:
                // Display by name
                cout << "Enter the name of the employee : ";
                cin >> empName;
                for(auto &it : empmap){
                    if(it.second.get()->getName() == empName){
                        it.second.get()->display();
                    }
                }
                cout << "----------------------------------" << endl;
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "you entered the wrong choice..." << endl;
                cout << "Exiting the program..." << endl;

        }

    } while (choice != 0);

    return 0;
}