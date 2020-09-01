/* shared_ptr:
 * shared_ptr shares the ownership of object (managed object).
 * Several shared_ptr can point to the same object. (managed object).
 * It keeps a reference counter to maintain how many shared pointers are pointing to the sam eobject.
 * Once last shared pointer goes out of scope the managed object gets deleted.
 *
 * Shared pointer is thread safe and not thread safe, what is this?
 *  a. control block is thread safe.
 *  b. managed object is not thred safe.
 *
 * There are three ways shared pointer destroyed managed objects.
 *  a. if last shared pointer goes out of scope.
 *  b. If you initialize shared pointer with another shared pointer.
 *  c. If you reset shared pointer.
 *
 * Reference count is controlled by control block. Shared object keeps one managed block (for managed object) and
 * a control block. Control block is thread safe but not managed object block.
 *
 * Reference count doesn't work when we use reference of pointer of shared pointer.
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

   std::shared_ptr<Foo> p1 = make_shared<Foo>(new Foo(10));   // best way exception/error safe

   cout<<p1->getX()<<" "<<(*p1).getX()<<endl;

   shared_ptr<Foo> p2 = make_shered<Foo>(new Foo(20));
   p2 = p1;                     // object with 10 will be deleted
   cout<<p2.use_count()<<endl;  // 2

   shared_ptr<Foo> p3(p2);
   cout<<p3.use_count()<<endl;  // 3

   p3 = nullptr;
   cout<<p2.use_count()<<endl;  // 2

   shared_ptr<Foo> p4 = make_shared<Foo>(new Foo(40));
   p4.reset();                 // object with 40 is deleted

   Foo* obj = p1.get();  // p1 is nullptr now, obj needs to get explicitly by delete operator

   

   shared_ptr<Foo> *p4 = &p2;  // It will not increment the reference count.

   thread t1(fun, p1), t2(fun, p2), t3(fun, p3);
   t1.join(); 
   t2.join(); 
   t3.join(); 
   return 0;
}
