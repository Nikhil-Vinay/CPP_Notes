/* cyclic_dependency:
 *
 * The below program exhibits the cyclic dependency. If we execute the below program, it wont print anything.
 * Any one out of son or daughter shared_ptr inside the mother class will be converted to weak_ptr then it will work fine.
 *
 */

#include<iostream>
#include<memory>


class son;
class daughter;

class mother
{
   shared_ptr<son> mySon;
   shared_ptr<daughter> myDaughter;

   public:
   ~mother() { cout<<"mother gone"<<endl;}

   void setSon(shared_ptr<son> s){
       mySon = s;
   }

   void setDaughter(shared_ptr<daughter> d) {
       myDaughter = d;
   }
};

class son
{
   shared_ptr<mother> myMother;
   public:
   son(shared_ptr<mother> m){ myMother = m};
   ~son() { cout<<"sone gone"<<endl;
};

class daughter
{
   shared_ptr<mother> myMother;
   public:
   daughter(shared_ptr<mother> m){ myMother = m};
   ~daughter() { cout<<"daughter gone"<<endl;
};

int main()
{
   std::shared_ptr<mother> m = make_shared<mother>(new mother());
   std::shared_ptr<son> s = make_shared<son>(new son(m));
   std::shared_ptr<daughter> d = make_shared<daughter>(new daughter(m));

   m.setDaughter(d);
   m.setSon(s);

   return 0;
}

