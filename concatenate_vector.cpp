#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> a, b, c;
  a.push_back(1);
  a.push_back(2);

  b.push_back(1);
  b.push_back(2);

  // append b to a
  a.insert(a.end(), b.begin(), b.end());

  for(int i = 0; i < a.size(); i++) {
     cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
