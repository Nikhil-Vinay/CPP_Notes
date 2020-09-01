#include<iostream>
using namespace std;

int main()
{
   string data;
   cin >> data;   // seperates the input by space.
   cout<<data<<endl;

   string str;
   getline(cin, str); // it will read the entire line
   cout<<str<<endl;


   return 0;
}
