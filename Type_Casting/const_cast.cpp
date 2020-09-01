// const_cast
//
// It is used to change const and volatile qualifiers of a pointer or reference.

#include<iostream>

using namespace std;

void thirdPartyLibrary(int* x) {
  int k = 10;
  cout<<(k+(*x));
}

int main()
{
  // when the actual referred object/variable is not const then only use const cast.

  const int a = 10;
  const int* b = &a;

  int* d = const_cast<int*>(b);
  *d = 15;  // invalid and undefined because underlying object is constant, it will compile successfully though.

  int a1 = 10;
  const int* b1 = &a1;
  int* d1 = const_cast<int*>(b1);
  *d1 = 20; // perfect, underlying object is not constant
  
  // third party library
  const int x = 10;
  const int* y = &x;
  thirtpartyLibrary(const_cast<int*>(y));
}
