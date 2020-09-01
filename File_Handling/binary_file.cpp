#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
   //working with binary file by get and put

   char input[100];
   strcpy(input, "learning rocks");
   
   fstream file("nik.bin", ios::binary | ios::in | ios::out | ios::trunc);
   if(!file.is_open()) {
     cout<<"error while opening the file"<<endl;
   } else {
     // write byte by byte
     for(int i = 0; i < strlen(input); i++) {
        file.put(input[i]);   // put method is used to write one byte on file
     }

     file.seekg(0);
     char ch;
     while(file.good()) {
        ch = file.get();   // get method is used to read one byte from file
        cout<<ch<<endl;
     }
   }

   return 0;
}
