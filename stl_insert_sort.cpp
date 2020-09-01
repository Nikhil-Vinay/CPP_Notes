#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class student
{
  public:
  int age;
  int marks;
  student(int inage, int inmarks): age(inage), marks(inmarks) { }
  bool operator<(const student& obj) const {   // < operator is mandatory for insertion/sorting as it is default
     return (age < obj.age);                   // > operator will throw error.
  }                                            // return age > obj.age for descending order sorting/insertion
  // When we don't have external comparator then insert/sort is done by default overloaded operator < only.
};

bool mycmp1(const student& obj1, const student& obj2) {
   return obj1.age < obj2.age;
}

class mycmp2
{
  public:
  bool operator()(const student& obj1, const student& obj2) {
     return obj1.age < obj2.age;   // for ascending order
  }                                // for descending order, obj1.age > obj2.age
};

int main()
{
  /****** Method - 1 *******/
  set<student> myset1;
  myset1.insert(student(10,50));
  myset1.insert(student(20, 70));
  myset1.insert(student(15, 60));
  set<student>::iterator it1;
  for(it1 = myset1.begin(); it1 != myset1.end(); it1++) {
     cout<<"Age: "<<it1->age<<" marks: "<<it1->marks<<endl;
  }
  vector<student> myvect1;
  myvect1.push_back(student(10, 50));
  myvect1.push_back(student(20, 70));
  myvect1.push_back(student(15, 60));
  sort(myvect1.begin(), myvect1.end());
  
  /****** Method - 2 *******/
  //set<student, mycmp1> myset2;   // ERROR: For insertion, comparator function doesn't work, instead use
 // myset2.insert(student(10, 50));//        functor class
 // myset2.insert(student(20, 70));
 // myset2.insert(student(15, 60));
 // set<student, mycmp1>::iterator it; 
 // for(it = myset2.begin(); it != myset2.end(); it++) {
 //   cout<<"Age: "<<it->age<<" Marks: "<<it->marks<<endl;
 // }
  vector<student> myvect2;
  myvect2.push_back(student(10, 50));
  myvect2.push_back(student(20, 70));
  myvect2.push_back(student(15, 60));
  sort(myvect2.begin(), myvect2.end(), mycmp1);
  sort(myvect2.begin(), myvect2.end(), mycmp2());

  /****** Mehod - 3 ********/
  set<student, mycmp2> myset3;
  myset3.insert(student(10, 50));
  myset3.insert(student(20, 70));
  myset3.insert(student(15, 60));
  set<student, mycmp2>::iterator it;
  for(it = myset3.begin(); it != myset3.end(); it++) {
    cout<<"Age: "<<it->age<<" Marks: "<<it->marks<<endl;
  }

  vector<student> myvect3;
  myvect3.push_back(student(10, 50));
  myvect3.push_back(student(20, 70));
  myvect3.push_back(student(15, 60));
  sort(myvect3.begin(), myvect3.end(), mycmp2());  // comparator class needs to be passed but mycmp2() instead of
                                                   // mycmp2
  return 0;
}
