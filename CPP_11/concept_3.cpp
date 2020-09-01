#include <iostream>

using namespace std;

class A
{
   int x;
   public:
   // if we have a argument based constructor then c++ compiler
   // removes the default constructor
   // we can force compiler to provide default special meber function 
   // by using keyword default 
   // This is applicable only for special member function - constructor,
   // copy constructor, destructor, assignment operator etc.
   // Its not applicable for general function
   // We cannot write default outside of class as A::A() = default
   //A() = default;
   A(int i) { x = i; }
   //A(const A&) = default;
   
   // error for general function
   //void print()= default
   //{ cout<<"inside class A"<<endl; }
   
   // we mark a defined special function as deleted by delete keyword
   // we cant overload same special function with default and delete
   // comment A()= default to test A() = delete
   // Again A::A() = delete is not permitted
   A() = delete;
   // delete copy constructor
   A(const A&) = delete;
   
};

//A::A() = default; // error

int main()
{
   A obj(2);
  // A obj2 = obj; // error copy constructor is deleted
  
  // non-const lvalue reference cant be assigned directly with rvale
  //int &x = 2;  // error , assigning lvalue reference with rvalue
  int a = 5;
  int &y = a;  // ok, assigned non-const lvalue reference with lvalue
  const int& z = 2;  // ok, assigning const lvalue reference with rvalue
  
  // rvalue reference can be assigned directly with rvalue
  // rvalue is used in move constructor
  int &&k = 10;  // rvalue reference is assigned with rvalue
  //int &&m = a; // error, rvalue reference cant be assigned with lvalue
   return 0;
}
