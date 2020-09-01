// std::bad_alloc, std::bad_cast, std::runtime_error, std::out_of_range, std::length_error  // these are classes

#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

int main()
{
   // throw keyword is used to throw exception
   int a = 10, b = 0;
   int c;
   try {
      if(b == 0) {
         throw runtime_error("devide by zero error");
      }
      c = a/b;
      cout<<"c :"<<c<<endl;
   }catch(runtime_error &error) {
      cout<<"exception occured: "<<error.what()<<endl;
   }
   return 0;
}
