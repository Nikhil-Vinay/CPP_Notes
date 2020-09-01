#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main()
{
   ifstream file;
   file.open("nik.txt");
   if(!file.is_open()) {
     cout<<"error while opwning the file."<<endl;
   } else {
     cout<<"file is opened successfully"<<endl;
     string str;
     while(file.good()) {
       getline(file, str);
       cout<<str<<endl;
     }
     file.close();
     
   }

   return 0;
}
