/* uniqu ptr is one of the smart pointer provided by c++11 to prevent memory leak.
 * It wraps a raw pointer which is deallocated when it goes out of scope.
 * When exception comes then also it deallocates the memory.
 * It has overloaded -> and * operator which makes to work similar to the raw pointer.
 * we can create array of unique_ptr also.
 *
 * operations:
 * release, reset, swap, get, get_deleter
 *
 * Note: we can check any smart pointer as below:
 * if(sp){
 *   cout<<"yes pointer exists"<<endl;
 * } else {
 *   cout<<"no"<<endl;
 * }
 *
 * custom deletor is explained in custom_deletor.cpp. Its applicable for all smart pointers.
 */

#include<iostream>
#include<memory>

class Foo
{
   int x;
   public:
   Foo(int in): x(in) { }
   int getX() { return x; }
   ~Foo() { cout<<"Destructor is called"<<endl;} 
};

int main()
{
   // std::unique_ptr<Foo> p1(new Foo(10));
   
   // Foo* p == new Foo(10);
   // std::unique_ptr<Foot> p1(p);

   std::unique_ptr<Foo> p1 = make_unique<Foo>(new Foo(10));   // best way exception/error/thread safe

   cout<<p1->getX()<<" "<<(*p1).getX()<<endl;

   // p1 = p2  , it fails because you cant copy ownership., copy constr
   unique_ptr<Foo> p3 = std::move(p1);  // ownership is moved, p1 becomes NULL

   Foo* p = p3.get();   // p gets the raw pointer, need to delete p explicitly now by delete operator

   Foo* p4 = p3.release();  // pe releases the ownership and p3 becomes NULL

   unique_ptr<Foo> p5 = make_unique<Foo>(new Foo(20));
   p5.reset(p4);      // old raw pointer object with val 20 is died, destructor gets called and p5 is set with
                      // new raw pointer object p4 
                     
   // swap is used to swap two unique_ptr objects with each other.
   return 0;
}
