#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Pet {
protected:
    string name;
    int age;
    double price;
public:
    Pet(string name, int age, double price) : name(name), age(age), price(price) {}
    virtual void makeSound() = 0;
    virtual void displayInfo() = 0;
    virtual ~Pet() {}
};

// Format số double 1 chữ số thập phân
string double_to_string(double number) {
    stringstream ss;
    ss << fixed << setprecision(1) << number;
    return ss.str();
};

class Dog : public Pet {
private:
    string breed;
public:
    Dog(string name, int age, double price, string breed) : Pet(name, age, price), breed(breed) {}
    void makeSound() override {
        cout << "Woof!\n" << endl;
    }
    void displayInfo() override {
        cout << left << setw(10) << "Dog" << " | "
             << setw(16) << name << " | "
             << setw(6) << age << " | "
             << setw(12) << double_to_string(price) << " | "
             << setw(16) << breed << endl;
    }
};

class Cat : public Pet {
private:
    string color;
public:
    Cat(string name, int age, double price, string color) : Pet(name, age, price), color(color) {}
    void makeSound() override {
        cout << "Meow!\n" << endl;
    }
    void displayInfo() override {
        cout << left << setw(10) << "Cat" << " | "
             << setw(16) << name << " | "
             << setw(6) << age << " | "
             << setw(12) << double_to_string(price) << " | "
             << setw(16) << color << endl;
    }
};

class Bird : public Pet {
private:
    double wingSpan;
public:
    Bird(string name, int age, double price, double wingSpan) : Pet(name, age, price), wingSpan(wingSpan) {}
    void makeSound() override {
        cout << "Chirp!\n" << endl;
    }
    void displayInfo() override {
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
    void addPet(Pet* a) {
        stock.push_back(a);
    }
    void display() {
        cout << left << setw(10) << "Type" << " | "
             << setw(16) << "Name" << " | "
             << setw(16) << "Age" << " | "
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
        string name, breed;
        int age;
        double price;
        ss >> name >> age >> price >> breed;
        return new Dog(name, age, price, breed);
    }
};

class CatParser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string name, color;
        int age;
        double price;
        ss >> name >> age >> price >> color;
        return new Cat(name, age, price, color);
    }
};

class BirdParser {
public:
    static Pet* parsePet(string data) {
        stringstream ss(data);
        string name;
        int age;
        double price, wing;
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
        if (type == "Dog") return DogParser::parsePet(data.substr(4));
        if (type == "Cat") return CatParser::parsePet(data.substr(4));
        return BirdParser::parsePet(data.substr(5));
    }
};

// #include "main.h"