// std::bad_alloc,i std::bad_cast, std::runtime_error, std::out_of_range, std::length_error  // these are classes

#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

void test() throw(int, char, runtime_error)  // this function can throw three types of exception
{
   //throw 20;
   throw 'c';
}

int main()
{
   try {
         test();
   }catch(runtime_error &error) {
      cout<<"exception occured: "<<error.what()<<endl;
   }catch (int error) {
     cout<<"int exception occured: "<<error<<endl;
   } catch (char error) {
     cout<<"char exception occured: "<<error<<endl;
   }catch(...) { // handle all kind of exception
     cout<<"some exception occured"<<endl;
   }
   return 0;
}
