#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class student
{
  public:
  int age;
  int marks;
  student(const student& obj) {
    age = obj.age;
    marks = obj.marks;
  }
  void operator = (const student& obj) {
    age = obj.age;
    marks = obj.marks;
  }
  student(int inage, int inmarks): age(inage), marks(inmarks) { }
  bool operator == (const student& obj) const {
     return (age == obj.age);                  
  }                                           
};

bool myfind1(const student& obj1, const student& obj2) {
   return obj1.age == obj2.age;
}

class myfind2
{
  student obj;
  public:
  myfind2(student in_obj):obj(in_obj) {} 
  bool operator()(const student& inobj) {
     return inobj.age == obj.age; 
  }                              
};

int main()
{
  /****** Method - 1 *******/
  vector<student> myvect1;
  myvect1.push_back(student(10, 50));
  myvect1.push_back(student(20, 70));
  myvect1.push_back(student(15, 60));
  if(find(myvect1.begin(), myvect1.end(), student(10, 50/*dummy*/)) != myvect1.end()) {
    cout<<"Present"<<endl;
  }else {
    cout<<"Not Present"<<endl;
  }
  
  /****** Method - 2 *******/
#if 0   // this method doesn't work
  vector<student> myvect2;
  vector<student>::iterator it2;
  myvect2.push_back(student(10, 50));
  myvect2.push_back(student(20, 70));
  myvect2.push_back(student(15, 60));
  it2 = find((myvect2.begin(), myvect2.end(), myfind1(student(10,50)));
  if(it2 != myvect2.end()) {
    cout<<"Present"<<endl;
  } else {
    cout<<"Not Presenet"<<endl;
  }
#endif
  /****** Mehod - 3 ********/

  vector<student> myvect3;
  vector<student>::iterator it3;
  myvect3.push_back(student(10, 50));
  myvect3.push_back(student(20, 70));
  myvect3.push_back(student(15, 60));
  it3 = find_if(myvect3.begin(), myvect3.end(), myfind2(student(10,50)));
  if(it3 != myvect3.end()) {
    cout<<"Present"<<endl;
  } else {
    cout<<"Not Presenet"<<endl;
  } 
     
  return 0;
}

// Note: map/multimap, set/multiset has their own find method
// Study difference between, find, find_if, find_if_not
