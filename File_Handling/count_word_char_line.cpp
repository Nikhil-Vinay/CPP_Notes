#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

// Method-1, read char by char from a file by get method and count word, line and char 
// Method-2, read the file line by line by getline and the parse the line by strtok(char* str, char del) method
// Method-3, use the class istringstream to extract the word seperated by space
// We are exploring here Method-3
//

int word_count = 0;
int line_count = 0;

void splitLine(string str)
{
  istringstream ss(str);
  while(ss) {
    string word;
    ss >> word;
    if(ss) {
      word_count++;
      cout<<word<<endl;
    }
  }
}

int main()
{
   ifstream file("nik.txt", ios::in);
   if(!file.is_open()){
      cout<<"error in opening the file"<<endl;
   } else {
      string str;
      while(file) {
         getline(file, str);
         if(file) {
           line_count++;
           splitLine(str);
         }
      }
      file.close();
      cout<<"Total line count: "<<line_count<<endl;     
      cout<<"Total word count: "<<word_count<<endl;     
   }

   return 0;
}
