#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// static_assert condition is checked at compile time and error is thrown
// at compile time.

// prior to c++11, this is how developer use to generate compile time error

//#if !defined(__static_assert) 
//#error "static_assert hasn't been defined yet". 
//#endif 

// example of constexpr
constexpr int GetSize()
{
    return 5;
}

int main()
{
   // static_assert needs const i
   // const int i = 1; will also work
   constexpr int i = 1;
   static_assert(i==1, "i is not zero");  // i==0 will throw assert
   
   int arr[GetSize()];   
   
   cout<<sizeof(arr)/sizeof(*arr)<<endl;
   return 0;
}
