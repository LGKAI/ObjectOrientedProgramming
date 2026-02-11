/*
#include <iostream>
#include <vector>

#include "ParserFactory.h"
#include "DailyEmployeeParser.h"
#include "ProductEmployeeParser.h"
#include "ManagerParser.h"
#include "IntegerToCurrencyConverter.h"
#include "Integer.h"

using namespace std;

int main() {
    ParserFactory factory;
    factory.registerWith(new DailyEmployeeParser());
    factory.registerWith(new ProductEmployeeParser());
    factory.registerWith(new ManagerParser());

    vector<string> lines = {
        "ProductEmployee productCount=790, paymentPerProduct=20000",
        "DailyEmployee dayCount=20, paymentPerPay=1000000",
        "ProductEmployee productCount=810, paymentPerProduct=19000",
        "ProductEmployee productCount=900, paymentPerProduct=18000",
        "Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
        "DailyEmployee dayCount=22, paymentPerPay=1100000",
        "Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
        "DailyEmployee dayCount=18, paymentPerPay=1500000",
        "Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"
    };

    vector<Employee*> employees;

    for (string line : lines) {
        int pos = line.find(" ");
        string type = line.substr(0, pos);
        IParsable* parser = factory.create(type);

        string data = line.substr(pos + 1);
        Employee* emp = dynamic_cast<Employee*>(parser->parse(data));
        employees.push_back(emp);
    }

    IntegerToCurrencyConverter converter;

    for (auto e : employees) {
        Integer value(e->salary());
        cout << e->toString() << ", salary: "
             << converter.convert(&value) << endl;
    }

    return 0;
}
*/

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <typeinfo>
#include <algorithm>
#include <regex>
using namespace std;

class Object {
public:
    virtual ~Object() = default;
    virtual string toString() = 0;
};

class Employee : public Object {
public:
    virtual ~Employee() = default;
    virtual int salary() = 0;
    virtual string toString() = 0;
};

class Manager : public Employee {
private:
    int _employeeCount, _paymentPerEmployee, _baseSalary;
public:
    Manager(int a, int b, int c) : _employeeCount(a), _paymentPerEmployee(b), _baseSalary(c) {}
    int salary() override {
        return _employeeCount * _paymentPerEmployee + _baseSalary;
    }
    string toString() override {
        return "Manager";
    }
};

class DailyEmployee : public Employee {
private:
    int _dayCount, _paymentPerDay;
public:
    DailyEmployee(int a, int b) : _dayCount(a), _paymentPerDay(b) {}
    int salary() override {
        return _dayCount * _paymentPerDay;
    }
    string toString() override {
        return "Daily employee";
    }
};

class ProductEmployee : public Employee {
private:
    int _productCount, _paymentPerProduct;
public:
    ProductEmployee(int a, int b) : _productCount(a), _paymentPerProduct(b) {}
    int salary() override {
        return _productCount * _paymentPerProduct;
    }
    string toString() override {
        return "Product employee";
    }
};

class IParsable {
public:
    virtual ~IParsable() = default;
    virtual Object* parse(string data) = 0;
    virtual string toString() = 0;
};

class ManagerParser : public IParsable {
public:
    Object* parse(string data) override {
        vector<string> res;
        string temp;
        stringstream dt(data);
        while (getline(dt, temp, ',')) {
            stringstream d(temp);
            string tmp;
            while (getline(d, tmp, '=')) res.push_back(tmp);
        }
        return new Manager(stoi(res[1]), stoi(res[3]), stoi(res[5]));
    }
    string toString() override {
        return "ManagerParser";
    }
};

class DailyEmployeeParser : public IParsable {
public:
    Object* parse(string data) override {
        vector<string> res;
        string temp;
        stringstream dt(data);
        while (getline(dt, temp, ',')) {
            stringstream d(temp);
            string tmp;
            while (getline(d, tmp, '=')) res.push_back(tmp);
        }
        return new DailyEmployee(stoi(res[1]), stoi(res[3]));
    }
    string toString() override {
        return "DailyEmployeeParser";
    }
};

class ProductEmployeeParser : public IParsable {
public:
    Object* parse(string data) override {
        vector<string> res;
        string temp;
        stringstream dt(data);
        while (getline(dt, temp, ',')) {
            stringstream d(temp);
            string tmp;
            while (getline(d, tmp, '=')) res.push_back(tmp);
        }
        return new ProductEmployee(stoi(res[1]), stoi(res[3]));
    }
    string toString() override {
        return "ProductEmployeeParser";
    }
};

class ParserFactory {
private:
    map<string, IParsable*> _container;
public:
    void registerWith(IParsable* parser) {
        string key;
        string name = typeid(*parser).name();
        if (name.find("DailyEmployeeParser") != string::npos)
            key = "DailyEmployee";
        else if (name.find("ProductEmployeeParser") != string::npos)
            key = "ProductEmployee";
        else if (name.find("ManagerParser") != string::npos)
            key = "Manager";
        _container[key] = parser;
    }
    IParsable* create(string type) {
        if (_container.count(type))
            return _container[type];
        return nullptr;
    }
};

class Integer : public Object {
private:
    int _value;
public:
    Integer(int value = 0) : _value(value) {}
    int value() {
        return _value;
    }
    string toString() override {
        return "Integer";
    }
};

class NumberFormatInfo : public Object {
private:
    string _currencyDecimalSeparator = ".";
    string _currencySymbol = "d";
    int _currencyPositive = 3;
    string _currencyPositiveFormat = "n $";
public:
    string currencyDecimalSeparator() {
        return _currencyDecimalSeparator;
    }
    string currencySymbol() {
        return _currencySymbol;
    }
    int currencyPositive() {
        return _currencyPositive;
    }
    string currencyPositiveFormat() {
        return _currencyPositiveFormat;
    }
    string toString() override {
        return "NumberFormatInfo";
    }
};

class IValueConverter {
public:
    virtual ~IValueConverter() = default;
    virtual string convert(Object* object) = 0;
    virtual string toString() = 0;
};

class IntegerToCurrencyConverter : public IValueConverter {
public:
    string convert(Object* object) override {
        auto number = dynamic_cast<Integer*>(object);
        int value = number->value();
        if (value == 0) return "0 d";
        stringstream builder;
        NumberFormatInfo info;
        int count = 0;
        while (value != 0) {
            int digit = value % 10;
            builder << digit;
            count++;
            if (count == 3 && value / 10 != 0) {
                builder << info.currencyDecimalSeparator();
                count = 0;
            }
            value /= 10;
        }
        string result = builder.str();
        reverse(result.begin(), result.end());
        string formatted = regex_replace(info.currencyPositiveFormat(), regex("n"), result);
        formatted = regex_replace(formatted, regex("\\$"), info.currencySymbol());
        return formatted;
    }
    string toString() override {
        return "IntegerToCurrencyConverter";
    }
};

// #include "main.h"