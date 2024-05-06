#include <iostream>
#include <string>

using namespace std;

// Базовый класс "Pet"
class Pet {
protected:
    string name;

public:
    Pet(const string& _name) : name(_name) {}

    void introduce() {
        cout << "Hello, my name is " << name << endl;
    }
};

// Производный класс "Dog"
class Dog : public Pet {
private:
    string breed;

public:
    Dog(const string& _name, const string& _breed) : Pet(_name), breed(_breed) {}

    void getInfo() {
        cout << "I'm a dog called " << name << ". My breed is " << breed << endl;
    }
};

// Производный класс "Cat"
class Cat : public Pet {
private:
    string color;

public:
    Cat(const string& _name, const string& _color) : Pet(_name), color(_color) {}

    void getInfo() {
        cout << "I'm a cat called " << name << ". My color is " << color << endl;
    }
};

// Производный класс "Parrot"
class Parrot : public Pet {
private:
    string featherColor;

public:
    Parrot(const string& _name, const string& _featherColor) : Pet(_name), featherColor(_featherColor) {}

    void getInfo() {
        cout << "I'm a parrot named " << name << ". The color of my feathers is " << featherColor << endl;
    }
};

int main() {
    Dog rex("Rex", "Labrador");
    Cat fluffy("Fluffy", "Ginger");
    Parrot polly("Polly", "Green");

    rex.getInfo();
    fluffy.getInfo();
    polly.getInfo();

    return 0;
}