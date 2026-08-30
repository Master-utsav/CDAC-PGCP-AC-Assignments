#include<iostream>

using namespace std;

//returns true if the number is prime otherwise return false
bool isPrime(int num){
    
    for(int i=2;i<num;i++){
       if(num%i==0){
         return false;
       }  
    }
    return true;
}

//returns addition of digits of a number
int findDigitAddition(int num){
   int sum=0;
   while(num>0){
     int d=num%10;
     sum+=d;
     num=num/10;
   } 
   return sum;
}

int factorial(int num){
   int fact=1;
   for(int i=1;i <=num; i++){
      fact=fact*i;
   }
   return fact;
}

void printTable(int num){
	for(int i = 1; i <= 10; i++){
		cout << num << "*" << i << "=" << num*i << "\t";
	}
	cout << endl;
}

int main(){
   int choice=0,num,result;
   bool status;
//    extern int factorial(int);
   do{
   cout<<"1. Check prime\n2.Factorial\n3. print table\n 4. find addition of digits of a number\n5. exit\nchoice:";
   cin>>choice;
   switch(choice){
   case 1:
         cout<<"enter number"<<endl;
         cin>>num;
         status=isPrime(num);
         if(status){
             cout<<num <<" is prime"<<endl;
         }else{
             cout<<num<<" is not prime"<<endl;
         }
         break;
   case 2:     
         // done factorial function	 
         cout<<"enter number"<<endl;
         cin>>num;
	 cout << "factorial of num : " << num << " is : " << factorial(num) << endl;
         break;
   case 3:
         //done print table function //output is 5*1=5  5*2=10 ... 5*10=50
         cout << "enter the number for table : " << endl;
	 cin >> num;
	 printTable(num);
         break;
   case 4:
         cout<<"enter number"<<endl;
         cin>>num;
         result=findDigitAddition(num);
         break;
   case 5: 
        cout<<"Thank you for using our code"<<endl;
   default:
         break;
   }  
   }while(choice!=5); 
   return 0;
}
