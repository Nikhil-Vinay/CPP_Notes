#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

// Note: c++ sort algorithm internally uses intro sort.
// intro sort is combination os three sorting: quick sort, heap sort and insertion sort.
// sort algorithm select the right of sorting algorithm depending upon the data.
//

class student
{
   int rollnum;
   string name;
   public:
   student(int in_rollnum, string in_name) {
      rollnum = in_rollnum;
      name = in_name;
   }

   // overloaded < operator is used in different sort algorithm as sort, is_sorted, partial_sort etc
   // overloaded < operator is used to store user defined data in set, map etc without defining any comparator
   bool operator < (student& obj) {
      return this->rollnum < obj.rollnum;
   }
};

int main()
{
   vector<int> vct;
   vct.push_back(3);
   vct.push_back(10);
   vct.push_back(7);
   vct.push_back(20);
   vct.push_back(12);
   // default sorting order is ascending order.
   // we can sort in descending order by using greatre<int>
   sort(vct.begin(), vct.end());  // sort in ascending order
   sort(vct.begin(), vct.end(), greater<int>()); // sort in descending order
   sort(vct.begin(), vct.begin()+2);  // sort [)  // end index is not included
   sort(vct.begin(), vct.begin()+2, greater<int>());
   
   // is_sorted is in C++11 and above

   //is_sorted(vct.begin(), vct.end());  // returns true/false default checks for ascending order sorted
   //is_sorted(vct.begin(), vct.end(), greater<int>());  // returns true/false it hecks for descending order sorted
   //is_sorted(vct.begin(), vct.end()+2);

   // partial sort: parameters : (it1, it2, it3, cmp)
   // it considers data from it1 to it3 but places sorted elements only till it1 to it2

   partial_sort(vct.begin(), vct.begin()+3, vct.end());
   partial_sort(vct.begin(), vct.begin()+3, vct.end(), greater<int>());

   // Note: All above sconcepts are applicable for user defined data type as well.
   // We can use overloaded < operator in user defined class else we need to use comparator function or a class
   // object with overloaded operator () called predicates.
   //

   // Note: for set and map of user deined data, we use to have overloded < operator in class.
   // alternatively, we can use class cmp with overloaded operator (), ex: set<student, cmp> myset;
   // Note: comparator function doesn't work with user defined data type set/map declaration.  
   //
   // parallel and thread safe sorting is another sorting feature in c++.
   // these parallel sorting is done parallely by multiple threads.
   // these are feature of c++17
   //   sort(std::execution::par, vct.begin(), vct.end());  // parallel
   //   sort(std::execution::seq, vct.begin(), vct.end());  // sequential
}
