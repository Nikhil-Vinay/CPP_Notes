#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// auto is not able to deduce the type of return as whether int ot int&
// decltype is helping auto to deduce the type as int&
auto getval(vector<int> &vct)->decltype(vct[0])
{
   return vct[0];
}

int main()
{

   vector<int> vct = {10, 20, 30};
   getval(vct) = 5;  // now vct = {5, 20, 30}
   
   // multily all values of vct by x(inpu user value) with help of lambda
   int x=2;  // this local value is captured in lambda by capture list
   //cout<<"input the multiplier: "<<endl;
   //cin>>x;
   
   // act on all elements of vector with help of for_each
   // we need to access the element as reference (int &a) for modifying
   // the value inplace in vector
   // return type (->void) is not mandatory to keep
   for_each(vct.begin(), vct.end(), [x](int &a)->void {a = a*x; });
   
   // print the vector
   // for printing the value of vector reference of element is not must
   // so keeping argument os lambda is: (int a)
   for_each(vct.begin(), vct.end(), [](int a)->void{ cout<<a<<" ";});
   
   return 0;
}
