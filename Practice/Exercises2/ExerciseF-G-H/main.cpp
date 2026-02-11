#include <bits/stdc++.h>
using namespace std;

class Book {
protected:
    string name, author;
    int year;
    double price;

public:
    Book() {}
    virtual string getType() = 0;
    virtual string getName() = 0;
    virtual string getAuthor() = 0;
    virtual int getYear() = 0;
    virtual double getPrice() = 0;
    virtual string getSpecial() = 0;
    virtual void display() = 0;
};

class Fiction : public Book {
protected:
    string award;

public:
    Fiction() {}

    Fiction(string _name, string _author, int _year, double _price, string _award) {
        name = _name;
        author = _author;
        year = _year;
        price = _price;
        award = _award;
    }

    virtual string getType() {
        return "Fiction";
    }

    virtual string getName() {
        return name;
    }

    virtual string getAuthor() {
        return author;
    }

    virtual int getYear() {
        return year;
    }

    virtual double getPrice() {
        return price;
    }

    virtual string getAward() {
        return award;
    }

    virtual string getSpecial() {
        return award;
    }

    virtual void display() {
    std::cout << std::left << std::setw(10) << getType() << " | "
              << std::setw(24) << getName() << " | "
              << std::setw(18) << getAuthor() << " | "
              << std::setw(6) << getYear() << " | "
              << std::setw(10) << setprecision(2) << fixed << getPrice() << " | "
              << getSpecial() << std::endl;
    }
};

class NonFiction : public Book {
protected:
    string genre;

public:
    NonFiction() {}

    NonFiction(string _name, string _author, int _year, double _price, string _genre) {
        name = _name;
        author = _author;
        year = _year;
        price = _price;
        genre = _genre;
    }

    virtual string getType() {
        return "NonFiction";
    }

    virtual string getName() {
        return name;
    }

    virtual string getAuthor() {
        return author;
    }

    virtual int getYear() {
        return year;
    }

    virtual double getPrice() {
        return price;
    }

    virtual string getGenre() {
        return genre;
    }

    virtual string getSpecial() {
        return genre;
    }

    virtual void display() {
    std::cout << std::left << std::setw(10) << getType() << " | "
              << std::setw(24) << getName() << " | "
              << std::setw(18) << getAuthor() << " | "
              << std::setw(6) << getYear() << " | "
              << std::setw(10) << setprecision(2) << fixed << getPrice() << " | "
              << getSpecial() << std::endl;
    }
};

class Comic : public Book {
protected:
    string series;

public:
    Comic() {}

    Comic(string _name, string _author, int _year, double _price, string _series) {
        name = _name;
        author = _author;
        year = _year;
        price = _price;
        series = _series;
    }

    virtual string getType() {
        return "Comic";
    }

    virtual string getName() {
        return name;
    }

    virtual string getAuthor() {
        return author;
    }

    virtual int getYear() {
        return year;
    }

    virtual double getPrice() {
        return price;
    }

    virtual string getSeries() {
        return series;
    }

    virtual string getSpecial() {
        return series;
    }

    virtual void display() {
    std::cout << std::left << std::setw(10) << getType() << " | "
              << std::setw(24) << getName() << " | "
              << std::setw(18) << getAuthor() << " | "
              << std::setw(6) << getYear() << " | "
              << std::setw(10) << setprecision(2) << fixed << getPrice() << " | "
              << getSpecial() << std::endl;
    }
};

class Library {
protected:
    vector<Book*> books;

public:
    Library() {
        books.clear();
    }

    void addBook(Book *book) {
        books.push_back(book);
    }

    void display() {
        std::cout << std::left << std::setw(10) << "Type" << " | "
                  << std::setw(24) << "Name" << " | "
                  << std::setw(18) << "Author" << " | "
                  << std::setw(6) << "Year" << " | "
                  << std::setw(10) << "Price" << " | "
                  << "Special" << std::endl;
        std::cout << std::string(100, '-') << std::endl;
        for (Book *book : books) {
            book->display();
        }
    }
};

class Parser {
public:
    static Book *parseBook(const string &s) {
        vector<string> a;
        string cur = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ',') {
                a.push_back(cur);
                cur = "";
            } else {
                cur += s[i];
            }
        }
        a.push_back(cur);
        if (a[0] == "Fiction") {
            // cout << "Fiction : " << a[1] << ' ' << a[2] << ' ' << stoi(a[3]) << ' ' << stod(a[4]) << ' ' << a[5] << '\n';
            return new Fiction(a[1], a[2], stoi(a[3]), stod(a[4]), a[5]);
        }
        else if (a[0] == "NonFiction") {
            // cout << "NonFiction : " << a[1] << ' ' << a[2] << ' ' << stoi(a[3]) << ' ' << stod(a[4]) << ' ' << a[5] << '\n';
            return new NonFiction(a[1], a[2], stoi(a[3]), stod(a[4]), a[5]);
        } else {
            // cout << "Comic : " << a[1] << ' ' << a[2] << ' ' << stoi(a[3]) << ' ' << stod(a[4]) << ' ' << a[5] << '\n';
            return new Comic(a[1], a[2], stoi(a[3]), stod(a[4]), a[5]);
        }
    }
};

// #include "main.h"