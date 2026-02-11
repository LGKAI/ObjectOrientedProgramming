#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Pet {
protected:
    string name;
    int age;
    double price;
public:
    Pet() {}
    virtual void makeSound() = 0;
    virtual void displayInfo() = 0;
};

string double_to_string(double number) {
    stringstream ss;
    ss << fixed << setprecision(1) << number;
    return ss.str();
}

class Dog : public Pet {
protected:
    string breed;
public:
    Dog() {}
    Dog(string _name, int _age, double _price, string _breed) {
        name = _name;
        age = _age;
        price = _price;
        breed = _breed;
    }
    void makeSound() { cout << "Woof!\n"; }
    void displayInfo() {
        cout << left << setw(10) << "Dog" << " | "
             << setw(16) << name << " | "
             << setw(6) << age << " | "
             << setw(12) << double_to_string(price) << " | "
             << setw(16) << breed << endl;
    }
};

class Cat : public Pet {
protected:
    string color;
public:
    Cat() {}
    Cat(string _name, int _age, double _price, string _color) {
        name = _name;
        age = _age;
        price = _price;
        color = _color;
    }
    void makeSound() { cout << "Meow!\n"; }
    void displayInfo() {
        cout << left << setw(10) << "Cat" << " | "
             << setw(16) << name << " | "
             << setw(6) << age << " | "
             << setw(12) << double_to_string(price) << " | "
             << setw(16) << color << endl;
    }
};

class Bird : public Pet {
protected:
    double wingSpan;
public:
    Bird() {}
    Bird(string _name, int _age, double _price, double _wingSpan) {
        name = _name;
        age = _age;
        price = _price;
        wingSpan = _wingSpan;
    }
    void makeSound() { cout << "Chirp!\n"; }
    void displayInfo() {
        cout << left << setw(10) << "Bird" << " | "
             << setw(16) << name << " | "
             << setw(6) << age << " | "
             << setw(12) << double_to_string(price) << " | "
             << setw(16) << double_to_string(wingSpan) << endl;
    }
};

class PetStore {
private:
    vector<Pet*> stock;
public:
    void addPet(Pet* a) { stock.push_back(a); }

    void display() {
        cout << left << setw(10) << "Type" << " | "
             << setw(16) << "Name" << " | "
             << setw(6) << "Age" << " | "
             << setw(12) << "Price" << " | "
             << setw(16) << "Special" << endl;
        cout << string(70, '-') << endl;

        for (auto p : stock) p->displayInfo();
    }
};

class DogParser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string name, breed; int age; double price;
        ss >> name >> age >> price >> breed;
        return new Dog(name, age, price, breed);
    }
};

class CatParser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string name, color; int age; double price;
        ss >> name >> age >> price >> color;
        return new Cat(name, age, price, color);
    }
};

class BirdParser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string name; int age; double price, wing;
        ss >> name >> age >> price >> wing;
        return new Bird(name, age, price, wing);
    }
};

class Parser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string type;
        ss >> type;

        if (type == "Dog")   return DogParser::parsePet(data.substr(4));
        if (type == "Cat")   return CatParser::parsePet(data.substr(4));
        return BirdParser::parsePet(data.substr(5));
    }
};

// #include "main.h"