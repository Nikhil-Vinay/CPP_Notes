#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int Number = 123;       // number to be converted to a string

string Result;          // string which will contain the result

ostringstream convert;   // stream used for the conversion

convert << Number;      // insert the textual representation of 'Number' in the characters in the stream
convert <<" nikhil ";

Result = convert.str();
const char* ptr = Result.c_str();
cout<<ptr<<endl;
  return 0;
}
