#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char ch='a';
    char str[50],*name;
    cout<<"enter a string : ";
    cin >> str; // acept the string upto 1st space chracter ot \n character
    // cin.getline(str,'\n');   //to accept string with spaces
    int length=strlen(str);
    name=new char[length+1];
    strcpy(name,str);
    cout<<"Name : "<< name << endl;
    delete[] name;
    
    //try strcmp,stricompare  to compare string

    // strcmp(name,str);  //compare two string
    char str1[50], str2[50];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int result = strcmp(str1, str2); // it returns 0 if both strings are equal, < 0 if str1 is less than str2, ansd > 0 if str1 is greater than str2.

    if (result == 0){
        cout << "Both strings are equal" << endl;
    }
    else if (result < 0){
        cout << str1 << " comes before " << str2 << endl;
    }
    else{
        cout << str1 << " comes after " << str2 << endl;
    }

    // stricmp -> case-insensitive comparison it only exist in C
    // int res2 = strncmp("Utsav", "utsav");
    // if (res2 == 0){
    //     cout << "Both strings are equal" << endl;
    // }

    return 0;
}
