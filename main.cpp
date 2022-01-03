#include <iostream>
#include <string>

class Animal{
public:
    virtual std::string getPassport() = 0;
    virtual void voice(Animal* a) = 0;
};

class Dog: virtual public Animal{
public:
    virtual std::string getPassport(){
        return "dog";
    }
    virtual void voice(Animal* a){
        if(a->getPassport() == "dog") {
            std::cout << "Woof! ";
        } else if(a->getPassport() == "cat"){
            std::cout << "Bark! ";
        }
    }
};



class Cat: virtual public Animal{
public:
    virtual std::string getPassport(){
        return "cat";
    }
    virtual void voice(Animal* a){
        if(a->getPassport() == "dog") {
            std::cout << "Meow! ";
        } else if(a->getPassport() == "cat"){
            std::cout << "Purr! ";
        }
    }
};

void meeting(Animal* a1, Animal* a2){
    a1->voice(a2);
    a2->voice(a1);
}

int main() {
    Animal* d1 = new Dog;
    Animal* d2 = new Dog;
    Animal* c1 = new Cat;
    Animal* c2 = new Cat;

    meeting(d1,c1);
    std::cout<<std::endl;
    meeting(c1,d1);
    std::cout<<std::endl;
    meeting(d1,d2);
    std::cout<<std::endl;
    meeting(c1,c2);

    return 0;
}
