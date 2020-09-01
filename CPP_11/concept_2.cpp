#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printvct(vector<int> &vct)
{
    //for_each(auto &x: vct) {  // not supported in c++11, supported in c++14
    for(int &x: vct) {
         cout<<x<<" ";
    }
    cout<<endl;
}

class A
{
   // inititialize with default value
   int x = 0;
   int y{0};
   //int z(0);  // error inside a class, outside class it is fine
   
   public:
   A() {
        cout<<"default constructor is called inside A"<<endl;
   }
   
   A(int x) {
       cout<<"Constructor with one argument is called inside A"<<endl;
   }
   
   A(const A& obj) {
       cout<<"Copy constructor is called inside A"<<endl;
   }
   
   A(std::initializer_list<int> x) {
       cout<<"Contrictor with initializer_lis is called inside A"<<endl;
   }
};

int main()
{
   // here we are taking example of vector, same is applied for all data
   // types - premitive data type and user defined data type
   
   // constructor is called.
   // here 5 objects will be called with same value- 10
   vector<int> vct1 (5,10);
   // constructor accepting initializer_list<int> is called
   // initializer list inializes all arguments in a list then calls constructor
   vector<int> vct2 {5, 10};
   // copy constructor is called
   vector<int> vct3 = {5, 10};
   // constructor accepting initializer_list<int> as argument is called
   vector<int> vct4 {{5,10}};
   vector<int> vct5 ({5,10});
   
   printvct(vct1);
   printvct(vct2);
   printvct(vct3);
   printvct(vct4);
   printvct(vct5);
   
   int x = 0;  // initializer with equal to
   int y(0);   // inititalizer with paramthesis, it doesn't work inside class
   int z{0};   // initializer with braces
   cout<<x<<" "<<y<<" "<<z<<endl;
   
   A obj();  // it is not printing default constructor message,
             // it gets treated as a function call
   A obj2{}; // default constructor is called
   A obj3(4); // constructor with one argument
   A obj4{5}; // constructor with initializer list
   
   // vector.size() return type is vector<T>::size_type
   vector<int>::size_type sz = vct1.size();
   cout<<"size of vector is: "<<sz<<endl;
   // size_t (unsigned integer size can vary machine to machine 32/64 bit)
   // so better ro ask vector size by size_type
   // best approach is ask vector size to auto. auto is perfectly type deduced based on machine 
   auto sz2 = vct2.size();
   cout<<"vector size is: "<<sz2<<endl;
   return 0;
}
