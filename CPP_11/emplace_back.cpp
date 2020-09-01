#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class A
{
    int a;
    public:
    A(int x):a(x) {cout<<"constructor is called"<<endl;}
    A(A&& rhs) {a = rhs.a; cout<<"move constructor is called"<<endl;}
};
int main()
{
   vector<int> vct{1,1};
   vct.push_back(1);
   vct.push_back(2);
   for(auto &x:vct) {
        cout<<x<<endl;
   }
   
   vector<A> a_vct;
   cout<<"push back"<<endl;
   a_vct.push_back(10);
   cout<<"emplace back"<<endl;
   a_vct.emplace_back(20);
   
   
   return 0;
}
