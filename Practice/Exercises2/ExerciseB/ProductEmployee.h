#ifndef PRODUCTEMPLOYEE_H
#define PRODUCTEMPLOYEE_H

#include "Employee.h"

class ProductEmployee : public Employee {
private:
    int _productCount, _paymentPerProduct;
public:
    ProductEmployee(int a, int b) : _productCount(a), _paymentPerProduct(b) {}
    int salary() override { return _productCount * _paymentPerProduct; }
    string toString() override { return "Product employee"; }
};

#endif