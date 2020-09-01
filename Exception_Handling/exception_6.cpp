// std::bad_alloc,i std::bad_cast, std::runtime_error, std::out_of_range, std::length_error  // these are classes

#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

class OverSpeed: public exception
{
   int speed;
   public:
   const char* what() {  // overridded function
     return "check out your car speed\n you are in the car, not in aeroplane.";
   }

   void setSpeed(int s) {  // local function
     speed = s;
   }

   void getSpeed() {   // local function
     cout<<" your car speed is: "<<speed<<endl;
   }
};

class Car
{
   int speed;
   public:
   Car() {
     speed = 0;
     cout<<"speed is "<<speed<<endl;
   }
  
   void accelerate() {
     for(;;) {
        speed += 10;
        if(speed >= 200) {
           OverSpeed s;
           s.setSpeed(speed);
           throw s;
        }
     }
   }
};

int main()
{
   Car mycar;
   try{
     mycar.accelerate();
   }catch(OverSpeed s){
     cout<<s.what()<<endl;
     s.getSpeed();
   }
   return 0;
}
