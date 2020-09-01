
/*
The ios::ate openmode is used to open the file with the writing cursor set at the end of the file (before the EOF character). It can only be used with files opened in write mode. This flag will only set the cursor to the end just after opening, unlike ios::app, which movces the cursor to the end before each write operation is to be performed. Thus, if you change the cursor position with seekp in ate mode, the position of writing is now the one assigned, however, in ios::app it remains to be the end of the file.
 
The ios::trunc mode is used to open the file and clear it by deleting all its data. Thus all characters present in the file are removed. After deletion, the cursor will be repositioned to the beginning.

The ios::ate mode preserves old data, while ios::trunc does not.
*/
#include<iostream> //Perform Standard I/O
#include<fstream>  //Perform File I/O
using namespace std;
int main()
{
    fstream fout, fin; //Files for writing and reading.

    cout<<"Opening File - file.txt. Will be created if it does not exist."<<endl;
    fout.open("file.txt",ios::out); //Opening the file in a normal way.
    cout<<"Initial Cursor Position - "<<fout.tellp()<<endl; 
    // tellp is used to get the writing cursor position.
    fout<<"Hello World"<<endl; // Writing 12 chars to the file. (including space and \n).
    int final = fout.tellp(); //Noting down final position.
    cout<<"Final   Cursor Position - "<<fout.tellp()<<endl; 
    fout.close(); cout<<"File Closed. "<<endl<<endl;
    
    fin.open("file.txt",ios::in); //opening file in read mode.
    while(fin)
    {
        char k = fin.get(); cout<<k;
    }
    fin.close(); cout<<endl<<endl;
    
    cout<<"Reopening File - file.txt, with ios::trunc flag."<<endl;
    fout.open("file.txt",ios::out|ios::trunc); //Opening file with trunc(truncate) flag.
    cout<<"Current Cursor Position - "<<fout.tellp()<<endl;
    fout<<"Bye World!"<<endl; //Writing Bye World to the file.
    fout.close(); cout<<"File Closed. "<<endl<<endl;
    
    cout<<"Data in the File Now - "<<endl;
    fin.open("file.txt",ios::in); //opening file in read mode.
    while(fin)
    {
        char k = fin.get(); cout<<k;
    }
    fin.close(); cout<<endl<<endl;
    
    cout<<"Reopening File - file.txt, with ios::ate flag."<<endl;
    fout.open("file.txt",ios::out|ios::ate); //Opening file with ate(At the End) flag.
    cout<<"Current Cursor Position - "<<fout.tellp()<<endl;
    fout<<"Hello World!"<<endl; //Writing Hello World to the file.
    fout.close(); cout<<"File Closed. "<<endl<<endl;
    
    cout<<"Data in the File Now - "<<endl;
    fin.open("file.txt",ios::in); //opening file in read mode.
    while(fin)
    {
        char k = fin.get(); cout<<k;
    }
    fin.close(); cout<<endl<<endl;
}
