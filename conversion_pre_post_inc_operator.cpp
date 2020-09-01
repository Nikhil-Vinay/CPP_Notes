#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class A
{
  int a; 
  public:
  A(int in): a(in) { }
  // post increment overloaded operator
  void operator++() {
    a++;
  }
  // pre increment overloaded operator
  void operator++(int) {
    ++a;
  }
  // conversion operator 
  operator int() { return a; }
  int GetVal() { return a; }
};

int main()
{
   A obj(2);
   obj++;
   cout<<obj.GetVal()<<endl;
   obj++;
   cout<<obj.GetVal()<<endl;

   int x = (int)obj;
   cout<<x<<endl;
   return 0;
}
