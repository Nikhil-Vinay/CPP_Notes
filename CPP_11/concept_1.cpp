// decltype is used where auto fails to deduce the exact type and many more places as well

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// here auto fails to deduce the type of return value, whether it is int or int& type, decltype help auto for
auto  modify(vector<int> &x)->decltype(x[0])
{
    return x[0];
}

auto  modify2(vector<int> &x)->int&
{
    return x[0];
}

#if 0
auto  modify3(vector<int> &x) // auto deduce as int type not int&
{
    return x[0];  // return is reference type but auto convert it to int
}
#endif

int&  modify4(vector<int> &x) // works fine
{
    return x[0];
}

int main()
{
   vector<int> a = {10, 20, 30 };  // std::intializer_list<int>
   sort(a.begin(), a.end());
   cout<<typeid(a).name()<<endl;
   const int &x = 2;  // if rvalue is direct int then const is must
   const int &y = x;
   cout<<typeid(x).name()<<endl;
   
   int c = 10;
   int d = 20;
   int &p = c;
   p = d;  // reference can be changed
   //auto z;  // auto cant be unassigned
   auto z = p;

   decltype(c) m = 10;   // m is declared as deduced type of c (int)
   decltype(10) n = 20;  // n is declared with deduced type of 10 (int)

   cout<<typeid(p).name()<<" "<<typeid(z).name()<<endl;
   
   for(auto x:a) {
        cout<<x<< " ";
   }
   cout<<endl;
   sort(a.begin(), a.end(), [](int& a, int& b)->bool { return a > b; });
   for(auto x:a) {
       cout<<x << " ";
   }
   
   cout<<endl;
   modify(a) = 5;
   for(auto x:a) {
       cout<<x << " ";
   }
   
   cout<<endl;
   modify2(a) = 6;
   for(auto x:a) {
       cout<<x << " ";
   }
   
   //modify3(a) = 7; // error
   return 0;
}
