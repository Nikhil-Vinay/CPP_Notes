// top most class is ios_base
// ios is derived from ios_base
// ios::in (read mode)
// ios::out (write mode)
// ios::trunc (trunc mode)
// ios::app (append mode)
// ios::binary  (binary mode)
// ios::ate
// ios::trunc
// istream and ostream and iostream  are child of ios
// << (insertion operator) is a method of ostream
// >> (extraction operator) is a method of istream
// fstream is derived from iostream 
// ifstream is derived from istream
// ofstream is derived from ostream

#include<iostream>
#include<fstream>
using namespace std;


int main()
{
   fstream file;
   file.open("nik.txt");  // it will be opened in read an write mode  // file should be present as opened in read
                                                                      //   mode also
//   file.open("nik.txt", ios::in | ios::out);  // it is same as above
   if(!file.is_open()){
      cout<<"error while opening the file"<<endl;
   } else {
      cout<<"file opened successfully"<<endl;
      file.close();
   }

   return 0;
}
