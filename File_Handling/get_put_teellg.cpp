#include<iostream>
#include<fstream>

using namespace std;

// for seekg and seekp, default offset is ios::beg
// we can use ios::curr, ios::beg, ios::end as offset
// file.seekp(2, ios::curr);

int main()
{
   fstream file("nik.txt", ios::in | ios::out);
   if(!file.is_open()) {
      cout<<"Error in file opening"<<endl;
   } else {
      cout<<file.tellg()<<endl;  // give sthe cursor(get) position starting from index 0
      cout<<file.tellp()<<endl;  // give sthe cursor(put) position starting from index 0 
      string str;
      getline(file, str);
      cout<<str<<endl;
      file.seekg(2);  // move get position to 2nd index (0,1,2)
      getline(file, str);
      cout<<str<<endl;
      cout<<file.tellg()<<endl;  // give sthe cursor(get) position starting from index 0
      cout<<file.tellp()<<endl;  // give sthe cursor(put) position starting from index 0

      file.seekp(2);
      file<<"writing at seek position"<<endl;
      file.seekg(0);
      getline(file, str);
      cout<<str<<endl;
      
      file.close();
   }

   return 0;
}
