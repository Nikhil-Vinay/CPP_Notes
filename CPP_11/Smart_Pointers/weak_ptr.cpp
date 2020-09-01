/* weak_ptr:
 *
 * If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then weak_ptr if for non-
 * ownership.
 * It actually reference to an object which is managed by shared pointer.
 *
 * A weak pointer is created as a copy of shared pointer.
 *
 * We have to convert weak_ptr in shared_ptr in order to use the managed object.
 * It is used to remove cyclic dependency between shared_ptr.
 *
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
   std::weak_ptr<Foo> w1(p1);

  cout<<p1.use_count()<<endl;  // 1
  cout<<w1.use_count()<<endl;  // 1
  cout<<w1.expired()<<endl;    // 0

  if(shared_ptr<Foo> p = w1.lock()){
     cout<<p.use_count()<<endl;
     cout<<p->getX()<<endl;
  }else{
     cout<<"Didn't get the resource"<<endl;
  }

  w1.reset();
  if(shared_ptr<Foo> p = w1.lock()){  // we'll not get anything here.
     cout<<p.use_count()<<endl;
     cout<<p->getX()<<endl;
  }else{
     cout<<"Didn't get the resource"<<endl;
  }

  

  

   cout<<p1->getX()<<" "<<(*p1).getX()<<endl;

   shared_ptr<Foo> p2;
   p2 = p1;
   cout<<p2.use_count()<<endl;  // 2

   shared_ptr<Foo> p3(p2);
   cout<<p3.use_count()<<endl;  // 3

   shared_ptr<Foo> *p4 = &p2;  // It will not increment the reference count.

   thread t1(fun, p1), t2(fun, p2), t3(fun, p3);
   t1.join(); 
   t2.join(); 
   t3.join(); 
   return 0;
}
