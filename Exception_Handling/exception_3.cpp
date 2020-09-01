// std::bad_alloc,i std::bad_cast, std::runtime_error, std::out_of_range, std::length_error  // these are classes

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
         throw 20;
   }catch(runtime_error &error) {
      cout<<"exception occured: "<<error.what()<<endl;
   }catch (int error) {
     cout<<"int exception occured: "<<error<<endl;
   }catch(...) { // handle all kind of exception
     cout<<"some exception occured"<<endl;
   }
   return 0;
}
