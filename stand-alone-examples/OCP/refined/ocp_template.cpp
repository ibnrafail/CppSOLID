#include <iostream>

template<typename Animal>
void speak(Animal const &animal)
{
    animal.speak();
}

class Dog
{
public:
    void speak() const
    {
        std::cout << "Bark...\n";
    }
};

class Cat
{
public:
    void speak() const
    {
        std::cout << "Meow...\n";
    }
};

int main()
{
    Dog dog;
    Cat cat;
    speak(cat);
    speak(dog);
    
    return 0;
}