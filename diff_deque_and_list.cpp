/* deque and list both allow to push and pop from front.
 * But still I see deque is better than list.
 * list is doubly linked list of nodes where each node stores one element.
 * deque is doubly linked list of memory blocks where each block stores more than one elements.
 *
 *So, deque allows accesing element by index ([]) in O(1) time.
 *But, list takes O(N) time for accesing the element.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   deque<int> dq;
   dq.push_back(2);  // 2
   dq.push_back(3);  // 2 3
   dq.push_front(1); // 1 2 3

   cout<<"First element of deque is: "<<dq[0]<<endl;  // 1
   dq.pop_back();   // 1 2
   dq.pop_front();  // 2

   cout<<"Size of deque is : "<<dq.size()<<" first element: "<<dq[0]<<endl;  // size: 1 first element: 2

   // Note: same push_back, pop_back, push_front, pop_front is applicable for list also but index based access
   // of element is not availabale
   return 0;
}
