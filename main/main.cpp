#include <iostream>

class Animal
{
public:
    virtual void Speak() = 0;
};

class Frog : public Animal
{
public:
    void Speak()
    {
        std::cout << "Ribbit Ribbit\n";
    }
};

class Dog : public Animal
{
public:
    void Speak()
    {
        std::cout << "Woof Woof\n";
    }
};

class Cat : public Animal
{
public:
    void Speak()
    {
        std::cout << "Meow Meow\n";
    }

    void Scratch(bool isHomeworkDone)
    {
        if (isHomeworkDone)
            std::cout << "The cat doesn't scratch\n";
        else
            std::cout << "The cat scratches\n";
    }

    void Purr()
    {
        std::cout << "The cat purrs\n";
    }
};

int main()
{
    Animal* animals[3];

    animals[0] = new Frog();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; i++)
        animals[i]->Speak();

    Cat* cat = dynamic_cast<Cat*>(animals[2]);

    cat->Scratch(false);
    cat->Purr();

    for (int i = 0; i < 3; i++)
        delete animals[i];
}
