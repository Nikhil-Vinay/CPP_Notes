#include<iostream>
#include<fstream>

using namespace std;

int main()
{
   ofstream file("nik.txt", ios::out);  // opeing in write mode so if file wont be there, it will create new file
   if(!file.is_open()){
      cout<<"file opening error"<<endl;
   }else{
      file<<"Hello Nikhil!\nI am learning the file operation.";  // new line not inserted in last
      file<<"hi"<<endl;
      file.close();
      cout<<"successfully written into the file"<<endl;
   }

   // open the file in append mode
   file.open("nik.txt", ios::app);
   if(!file.is_open()) {
      cout<<"error in file opening in append mode"<<endl;
   } else {
      cout<<"appending in file"<<endl;
      file<<"This line is appended in file"<<endl;
      file.close();
   }

   // open the file in ate mode  // remove all data of file and move the cursor in the beginning
   file.open("nik.txt", ios::ate);
   if(!file.is_open()) {
      cout<<"error in file opening in append mode"<<endl;
   } else {
      cout<<"example of ios::ate mode in file writing"<<endl;
      file<<"example of is::ate mode in file writing"<<endl;
      file.close();
   }
   return 0;
}
