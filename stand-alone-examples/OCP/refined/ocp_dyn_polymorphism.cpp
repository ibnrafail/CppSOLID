#include <iostream>

class Animal
{
public:
    virtual void speak() const = 0;
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Bark...\n";
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Meow...\n";
    }
};

void speak(Animal const &animal)
{
    animal.speak();
}

int main()
{
    Dog dog;
    Cat cat;
    speak(dog);
    speak(cat);
}
