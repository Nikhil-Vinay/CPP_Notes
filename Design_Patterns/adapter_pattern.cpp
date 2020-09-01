
#include<iostream>

using namespace std;


class Bird 
{ 
    // birds implement Bird interface that allows 
    // them to fly and make sounds adaptee interface 
    public:
    virtual void fly() = 0; 
    virtual void makeSound() = 0; 
}; 
  
class Sparrow : public Bird 
{ 
    public:
    // a concrete implementation of bird 
    void fly() 
    { 
        cout<<"Flying"<<endl; 
    } 
    void makeSound() 
    { 
        cout<<"Chirp Chirp"<<endl; 
    }
};

class ToyDuck 
{ 
    public:
    // target interface 
    // toyducks dont fly they just make 
    // squeaking sound 
    virtual void squeak() = 0; 
}; 
  
class PlasticToyDuck : public ToyDuck 
{ 
    public:
    void squeak() 
    { 
        cout<<"Squeak"<<endl;
    } 
};

class BirdAdapter : public ToyDuck 
{ 
    public:
    // You need to implement the interface your 
    // client expects to use. 
    Bird* bird; 
    BirdAdapter(Bird* bird) 
    { 
        // we need reference to the object we 
        // are adapting 
        this->bird = bird; 
    } 
  
    void squeak() 
    { 
        // translate the methods appropriately 
        bird->makeSound(); 
    } 
};
 
int main()
{
   Sparrow* sparrow = new Sparrow(); 
   ToyDuck* toyDuck = new PlasticToyDuck(); 
  
   // Wrap a bird in a birdAdapter so that it  
   // behaves like toy duck 
   ToyDuck* birdAdapter = new BirdAdapter(sparrow); 
  
   cout<<"Sparrow..."<<endl; 
   sparrow->fly(); 
   sparrow->makeSound(); 
  
   cout<<"ToyDuck..."<<endl; 
   toyDuck->squeak(); 
  
   // toy duck behaving like a bird  
   cout<<"BirdAdapter..."<<endl; 
   birdAdapter->squeak();

   return 0;
}
