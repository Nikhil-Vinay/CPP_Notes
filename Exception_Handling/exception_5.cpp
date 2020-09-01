// std::bad_alloc,i std::bad_cast, std::runtime_error, std::out_of_range, std::length_error  // these are classes

#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

int main()
{
   try {
         try{
            throw " a character exception";
         } catch(const char* e) {
            cout<<"character type in inner block--> "<<e<<endl;
            throw 2;
         }
   }catch(const char* e) {
      cout<<"character type in outer block--> "<<e<<endl;
   }catch (...) {
     cout<<"unexpected exception in outer block--> "<<endl;
   }
   return 0;
}
