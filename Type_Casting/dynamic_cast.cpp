// dynamic_cast:
//
// It is explicitly used for polymorphic classes.
// It is not used for premitive data types.
// casting is decided at run time.
// dynamic_cast is applied with pointer or reference of polymorphic calss.
// Base class should be olymorphic menas, should have atleast one virtual function.
//
// If casting success, it returns value of new type
// If casting fails and new_type is pointer type then it returns null ptr to that type.
// If casting fails and new type is a reference type, it throes an exception that matches a handler of type std::bad_cast.
//
// It is used to decide wrong down casting.
//
// We can check type and name of any class usinf typeid(..).name() function.

#include<iostream>
#include<exception>

usin namespace std;

class Base 
{
   public:
   virtual void print() {
      cout<<"base class"<<endl;
   }
};

class Derived1 : public Base 
{
   public:
   virtual void print() {
      cout<<"derived-1"<<endl; 
   }
};

class Derived2 : public Base 
{
   public:
   virtual void print(){
      cout<<"derived-2"<<endl;
   }
};

int main()
{
   char a;
   int* ip = dynamic_cast<int*>(&a); // It will throw error at compile time, not because casting char* to int*
                                     // it s because we are applying dynamic cast on premitive data type.
                                     // Compile Error: dynamic_cast is used for * or & of a class.

  Derived1 d1;
  Base* bp = dynamic_cast<Base*> (d1);
  Derived2* d2 = dynamic_cast<Derived2*>(bp);

  if(d2 == nullptr) {
     cout<<"casting is not proper"<<endl;
  } else {
     cout<<"casting is proper"<<endl;
  }

  // for reference we need to use try and catch
  try{
     Derived2 d2 = dynamic_cast<Derived2&>(*bp);
  } catch (exception& e) {   // we can use some specific exception as exception::bad_cast& e
    cout<<e.what()<<endl;
  }
  
  return 0;
}
