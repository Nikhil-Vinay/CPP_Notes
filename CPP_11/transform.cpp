/**** std::transform is used to apply some operation in all data */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> vct1 = {1,2,3,4,5,6};
   
   // unary transform
   // applied the lambda operation from vct1.begin() to vct1.end()
   // and stored result for each operation starting from vct1.begin()
   std::transform(vct1.begin(), vct1.end(), vct1.begin(), [](int x)->int{ return x*2;});
   for(auto x: vct1){
       cout<<x<<" ";      // 2 4 6 8 10 12
   }
   cout<<endl;
   
   vector<int> vct2 = {1,2,3,4,5,6};
   
   // binary transform
   // applied the lambda to add two numbers from vct1.begin() to vct1.end()
   // so, added each element starting with vct2.begin()
   // and stored each iteration result starting from vct1.begin()
   std::transform(vct1.begin(), vct1.end(), vct2.begin(), vct1.begin(), plus<int>());
   
   // this is similar to above statement.
   //std::transform(vct1.begin(), vct1.end(), vct2.begin(), vct1.begin(), [](int x, int y)->int{return x+y;});
   
   for(auto x: vct1){
       cout<<x<<" ";     // 3 6 9 12 15 18
   }
   
   cout<<endl;
   
   for(auto x: vct2){
       cout<<x<<" ";  // 1 2 3 4 5 6
   }
   cout<<endl;
   return 0;
}
