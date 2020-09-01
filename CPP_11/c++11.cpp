#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   int x = 12;
   auto f = [x]()mutable->int{return ++x;};
   cout<<f()<<x<<endl;
   vector<int> vct { 5, 6, 10, 15 };
   //sort(vct.begin(), vct.end(), [](auto x1, auto x2){return x1 < x2;});  // use of auto in lambda function
   //only available in c++14 and above
   sort(vct.begin(), vct.end(), [](auto x1, auto x2){return x1 < x2;});
   for (auto& x: vct) {
        cout<<x<<endl;
   }
   
   return 0;
}
