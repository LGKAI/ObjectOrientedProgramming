/*
#include <iostream>
#include "ParserFactory.h"

int main() {
    ParserFactory factory;

    IParsable* p1 = factory.create("Square");
    IShape* s1 = p1->parse("a=10");
    cout << s1->toString() << " area = " << s1->area() << "\n";

    IParsable* p2 = factory.create("Rectangle");
    IShape* s2 = p2->parse("w=3, h=4");
    cout << s2->toString() << " area = " << s2->area() << "\n";

    return 0;
}
*/

#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#define PI acos(-1)
using namespace std;

class IShape {
public:
    virtual ~IShape() = default;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string toString() = 0;
};

class Rectangle : public IShape {
private:
    double w, h;
public:
    Rectangle(double w = 0, double h = 0) : w(w), h(h) {}
    double area() override {
        return w * h;
    }
    double perimeter() override {
        return 2 * (w + h);
    }
    string toString() override {
        return "Rectangle";
    }
};

class Square : public IShape {
private:
    double a;
public:
    Square(double a = 0) : a(a) {}
    double area() override {
        return a * a;
    }
    double perimeter() override {
        return 4 * a;
    }
    string toString() override {
        return "Square";
    }
};

class Circle : public IShape {
private:
    double r;
public:
    Circle(double r = 0) : r(r) {}
    double area() override {
        return PI * r * r;
    }
    double perimeter() override {
        return 2 * PI * r;
    }
    string toString() override {
        return "Circle";
    }
};

class IParsable {
public:
    virtual ~IParsable() = default;
    virtual IShape* parse(string data) = 0;
    virtual string toString() = 0;
};

class RectangleParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t wPos = data.find('=');
        size_t commaPos = data.find(',');
        size_t hPos = data.find('=', commaPos);
        double w = stod(data.substr(wPos + 1, commaPos - wPos - 1));
        double h = stod(data.substr(hPos + 1));
        return new Rectangle(w, h);
    }
    string toString() override {
        return "RectangleParser";
    }
};

class SquareParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t pos = data.find('=');
        double a = stod(data.substr(pos + 1));
        return new Square(a);
    }
    string toString() override {
        return "SquareParser";
    }
};

class CircleParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t pos = data.find('=');
        double r = stod(data.substr(pos + 1));
        return new Circle(r);
    }
    string toString() override {
        return "CircleParser";
    }
};

class ParserFactory {
private:
    map<string, IParsable*> parsers;
public:
    ParserFactory() {
        parsers["Rectangle"] = new RectangleParser();
        parsers["Square"] = new SquareParser();
        parsers["Circle"] = new CircleParser();
    }
    ~ParserFactory() {
        for (auto& p : parsers)
            delete p.second;
    }
    IParsable* create(string type) {
        return parsers[type];
    }
};

namespace Utils {
    class String {
    public:
        static vector<string> split(string s, string delim) {
            vector<string> result;
            size_t start = 0;
            size_t pos = s.find(delim);
            while (pos != string::npos) {
                result.push_back(s.substr(start, pos - start));
                start = pos + delim.length();
                pos = s.find(delim, start);
            }
            result.push_back(s.substr(start));
            return result;
        }
    };
}

// #include "main.h"