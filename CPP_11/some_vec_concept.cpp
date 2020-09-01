#include <iostream>
#include<vector>
using namespace std;

class A
{
    int* p = nullptr;
    public:
    A() {
        p = new int(2);
        cout<<"Constructor"<<endl;
    }
    A(const A& obj) {
        cout<<"copy constructor"<<endl;
    }
    //#if 0
    A(const A&& obj) {
        cout<<"move constructor"<<endl;
    }
   //#endif
    ~A(){
        delete p;
        cout<<"Destructor"<<endl;
    }
};

using namespace std;

int main()
{
   vector<A> vct;
   cout<<"pushing 1st object"<<endl;
   vct.push_back(A());
   cout<<"Cpacity: "<<vct.capacity()<<" size: "<<vct.size()<<endl;
   cout<<"pushing second object"<<endl;
   vct.push_back(A());
   cout<<"Cpacity: "<<vct.capacity()<<" size: "<<vct.size()<<endl;
   cout<<"pushing third object"<<endl;
   // std::move is same as above
   vct.push_back(std::move(A()));
   cout<<"Cpacity: "<<vct.capacity()<<" size: "<<vct.size()<<endl;
   cout<<"pushing fourth object"<<endl;
   // static_cast to rvalue is same as above
   vct.push_back(static_cast<A&&>(A()));
   cout<<"Cpacity: "<<vct.capacity()<<" size: "<<vct.size()<<endl;
   cout<<"Going out of main"<<endl;
   return 0;
}
