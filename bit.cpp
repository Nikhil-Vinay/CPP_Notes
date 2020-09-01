#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// bitset has methods - set, reset, flip, count, size, test
// overloaded operator []
int main()
{
   std::bitset<4> num(string("0100"));   
   cout<<num<<endl;
   num.flip(2);   // flips 2nd bit 1 to 0
   cout<<num<<endl;
   num.flip();   // flips all bits
   cout<<num<<endl;

   std::bitset<4> num2;    // stores 0000
   cout<<num2<<endl;

   bitset<4> a;  // 0000
   cout<<"a is: "<<a<<endl;
   
   a.set();      // will set all the bits -> 1111
   cout<<"a is: "<<a<<endl;

   a.reset();    // will reset all the bits -> 0000
   cout<<"a is: "<<a<<endl;

   a.flip(0);    // flip the bit at 0th index -> 0001
   cout<<"a is: "<<a<<endl;

   a.reset(0);   // reset the bit at 0th index -> 0000
   cout<<"a is: "<<a<<endl;

   a.set(2);   // reset the bit at 2nd index -> 0100
   cout<<"a is: "<<a<<endl;

   a.set(2, 0); // set bit at 2nd index as 0; alternate of clear -> 0000
   cout<<"a is: "<<a<<endl;

   a[2] = 1;    // 0100
   cout<<"a is: "<<a<<endl;

   cout<<"set bits count: "<<a.count()<<endl;  // 1
   
   cout<<"Number of bits in a: "<<a.size()<<endl;  // 4

   // set function takes index as argument and return 1 if bit is set at index else returns 0
   cout<<"Bit val at index 1 is: "<<a.test(1)<<endl;  // 0
   cout<<"Bit val at index 2 is: "<<a.test(2)<<endl;  // 1

   // any() function returns true if atleast one bit is set
   if(a.any()) {
     cout<<"At leat one bit is set in a "<<endl;
   }

   // none() function returns true if no bit is set
   if(a.none()) {
     cout<<"no bit is set in a "<<endl;
   }

   // All bitwise operators are overloaded in bitset.
   // All bitwise operations can be performed without any typecasting.

   bitset<4> bset1(9); // bset1 contains 1001 
    bitset<4> bset2(3); // bset2 contains 0011 
  
    // comparison operator 
    cout << (bset1 == bset2) << endl; // false 0 
    cout << (bset1 != bset2) << endl; // true  1 
  
    // bitwise operation and assignment 
    cout << (bset1 ^= bset2) << endl; // 1010 
    cout << (bset1 &= bset2) << endl; // 0010 
    cout << (bset1 |= bset2) << endl; // 0011 
  
    // left and right shifting 
    cout << (bset1 <<= 2) << endl; // 1100 
    cout << (bset1 >>= 1) << endl; // 0110 
  
    // not operator 
    cout << (~bset2) << endl; // 1100 
  
    // bitwise operator 
    cout << (bset1 & bset2) << endl; // 0010 
    cout << (bset1 | bset2) << endl; // 0111 
    cout << (bset1 ^ bset2) << endl; // 0101

   return 0;
}
