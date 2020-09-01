/* Points to be remembered:
 * 1. overloaded new and delete operators are default static (doesn't have this pointer as object still not
 *    created). Writing/not writing static in front of overloaded new and delete operators are same.
 * 2. We can have different signature of overloaded new and delete operators (in overloaded form)
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void* operator new(size_t sz)
{
  cout<<"Global overloaded new operator is called"<<endl;
  void* ptr = malloc(sz);
  return ptr;
}

void operator delete(void* ptr)
{
   cout<<"Global overloaded delete operator is called"<<endl;
   free(ptr);
}

void* operator new[](size_t sz)
{
  cout<<"Global array overloaded new operator is called"<<endl;
  cout<<"Creating total: "<<sz<<" bytes"<<endl;
  void* ptr = malloc(sz);
  return ptr;
}

void operator delete[](void* ptr)
{
   cout<<"Global array overloaded delete operator is called"<<endl;
   free(ptr);
}

void* operator new(size_t sz, int val)
{
  cout<<"Global overloaded new operator (with val) is called"<<endl;
  void* ptr = malloc(sz);
  if (val) {
    //*(static_cast<int*> ptr) = val;
  }
  return ptr;
}

class Obj
{
   public:
   Obj() { cout<<"Obj class constructor is called"<<endl; }
   void* operator new (size_t sz) {
       cout<<"Obj class new is called"<<endl; 
       void* ptr = malloc (sz);
       return ptr;
   }

   void operator delete (void* ptr) {
      cout<<"Obj class delete is called"<<endl; 
      free(ptr);
   }

   ~Obj() { cout<<"Obj class destructor is called"<<endl; }
};

int main()
{
   Obj* obj = new Obj();
   delete obj;  
  
   cout<<"***************"<<endl;
   int* ptr1 = new int;
   delete ptr1;

   cout<<"***************"<<endl;
   int* ptr2 = new int[2];
   delete[] ptr2;  
 
   cout<<"***************"<<endl;
   int* ptr3 = new(2) int();
   delete (ptr3);
   return 0;
}


