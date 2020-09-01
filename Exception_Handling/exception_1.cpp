// devide by zero, database disconnection etc
//
// handled by try, catch throw

#include<iostream>
#include<exception>

using namespace std;

int main()
{
   // throw keyword is used to throw exception
   int a = 10, b = 0;
   int c;
   try {
      if(b == 0) {
         throw "devide by zero";
      }
      cout<<"exception is thrown"<<endl;
   }catch(const char* e) {
      cout<<"exception occured: "<<e<<endl;
   }
   return 0;
}
