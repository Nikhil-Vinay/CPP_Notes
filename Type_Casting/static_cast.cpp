// static_cast 
/* It is used at compile time.
 * It performs implicit conversion between types.
 */

#include<iostream>

using namespace std;

class Int
{
   int x;
   public:

   Int(int in = 0):x(in) { }

   // conversion operator
   operator string() {
      return to_string(x);
   }
};

class Base {};
class Derived1 : public Base { };
class Derived2 : public Base { };

int main()
{
   // visibility in code
   float f = 3.5
   int a;
   a = f;   // correct
   a = static_cast<int>(f);   // correct and better visibility

   // conversion operator and conversion constructor also makes implicit typecasting
   Int obj(3);
   String str1 = obj;
   obj=20;

   String str2 = static_cast<string>(obj);  // conversion operator is required for it
   obj = static_cast<Int>(20);              // conversion constructor is required for it

  
   // static cast is more restrictive than c style casting
   char a = 'd';
   char* c = &a;
   int* p = (int*)(c);  // its allowed but very dangerous
   
   int* p = static_cast<int*>(c);   // FAIL, It will not compile and tghrow error at compile time. 
   int* p = static_cast<int*>(&a);  // FAIL, It will not compile and tghrow error at compile time. 

   // static_cast doesn't work in downcsting in cse of Base and Derived
   // we need dynamic_casting

   Derived1 d1;
   Derived2 d2;

   Base* bp1 = static_cast<Base*>(&d1);  // ok
   Base* bp2 = static_cast<Base*>(&d2);  // ok

   Derived1* dp1 = static_cast<Derived1*>(bp2);  // compiles, but not ok dngerous
   Derived2* dp2 = static_cast<Derived2*>(bp1);  // compiles, but not ok dangerous

   // We can use static pointer for vid pointer conversion as well to increase readability
   int* p = new int(10);
   void* vp = static_cast<void*>(p);
   int* q = static_cast<int*>(vp);

   return 0;
}
