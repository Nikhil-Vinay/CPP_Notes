/* custom_deletor:
 *
 * default deleter is operator delete on all c++11 smart pointers.
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

void fun(shared_ptr<Foo> p)
{
  // reference count will be increased by p and reference block is thread safe.
  cout<<"inside fun "<<p.use_count()<<endl;
  // reference count is decreased by p going out of scope
}

int main()
{
   // std::shared_ptr<Foo> p1(new Foo(10));
   
   // Foo* p == new Foo(10);
   // std::shared_ptr<Foot> p1(p);

   std::shared_ptr<Foo> p1 = make_shared<Foo>(new Foo(10));   // default deleter: operator delete
   // Now we will provide custom deletor as second argument in constructor of shared pointer.
   std::shared_ptr<Foo> p2 = make_shared<Foo>(new Foo(20), 
                            [](Foo* obj){ cout<<"Custom deletor"<<endl; delete obj; })

   // where do we need custom deletor ?
   // p3 is pointing to first object Foo[0] and managing this object only. Here if p3 will go out of scope
   // only Foo[0] will be deleted by cstom deletor, Foo[1] and Foo[2] will not be deleted.
   // It will cause memory leak. here we need to have custom deletor to delete the array of objects.

   //shared_ptr<Foo> p3(new Foo[3](10));
   
   shared_ptr<Foo> p3( new Foo[3](10), [](Foo* obj){delete[] obj} );

   return 0;
}
