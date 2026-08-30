#include<iostream>
using namespace std;

class MathUtils{
  private: 
     // done calculate factorial
     static int factorial(int num){
         int fact = 1;
         for(int i = num ; i >= 1; i--){
		 fact *= i;
	 }
	 return fact;
     }   
  public:
       //this function can be called by using classname::functionname
       //it doesnot receive this pointer
       //static function can use only static members, to use nonstatic member you need to create object and then use it
       static int addition(int n1,int n2){

             return n1+n2;
       } 
       
       static int combination(int n,int r){
         int result;
         result=factorial(n)/(factorial(r)*factorial(n-r));
         return result;
       }

};

int main(){
   int num1=20,num2=30,result;
   result=MathUtils::addition(num1,num2);
   cout<<"anaswer : "<<result<<endl;
   cout<<"answer: "<<MathUtils::addition(num1,num2)<<endl;
   // done  : call combination function here
   int n , r;
   cout << "enter the n and r : " << endl;
   cin >> n >> r;
   cout << "combination of n " << n << " and r " << r << " is : " << MathUtils::combination(n , r) << endl; 
   return 0;
}
