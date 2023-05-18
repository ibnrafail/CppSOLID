#include <iostream>

template<typename T>
concept Speakable = requires(T t)
{
    t.speak();
};

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

template<Speakable T>
void speak(T const &animal)
{
    animal.speak();
}

int main()
{
    Dog dog;
    Cat cat;
    speak(cat);
    speak(dog);

    Animal &animal1 = dog;
    Animal &animal2 = cat;
    speak(animal1);
    speak(animal2);
    
    return 0;
}