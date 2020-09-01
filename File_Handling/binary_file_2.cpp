#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

// read and erite block of data

class Person
{
   char name[80];
   int age;
   public:
   Person() {
     strcpy(name, "no name"); 
     age = 0;
   }

   Person(char* name, int inage) {
     strcpy(this->name, name);
     age = inage;
   }

   void whoareyou() {
     cout<<"hi , I am "<<name<<" and my age: "<<age<<endl;
   }

};

int main()
{
   Person p1("nik", 30);
   // ios::trunc is used to craete a file if file file is not presenet
   // else if file is not present then file is not opened because we have ios::in also in open mode
   fstream file("person.bin", ios::binary | ios::in | ios::out | ios::trunc); 
   if(!file.is_open()) {
     cout<<"error while opening the file"<<endl;
   } else {
     file.write((char*)(&p1), sizeof(Person));
     file.seekg(0);
     
     Person p2;
     file.read((char*)(&p2), sizeof(Person));
     
     p1.whoareyou();
     p2.whoareyou();

     file.close();  
  }

  return 0;
}
