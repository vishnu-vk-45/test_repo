#include <iostream>
#include <string_view>
#include <string>
#include<array>

using namespace std;

class Animal
{
protected:
    std::string m_name;
    string m_speak;

    Animal(std::string_view name,const string& speak)
        : m_name{ name },m_speak{speak}{}

    // To prevent slicing (covered later)
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    std::string_view getName(const Animal* animal) const { return animal->m_name; }
    std::string_view getSpeak(const Animal* animal) const { return animal->m_speak;}
};

class Cat: public Animal
{
public:
    Cat(std::string_view name, const string& speak = "Meow")
        : Animal{name,speak } {}

    // std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name, const string& speak = "Woof")
        : Animal{ name,speak } {}

    // std::string_view speak() const { return "Woof"; }
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    // const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    const Animal* animal[] {&fred,&misty};

    for (const auto animal : animals)
    {
        std::cout << animal->getName(animal) << " says " << animal->getSpeak(animal) << '\n';
    }

    return 0;
}