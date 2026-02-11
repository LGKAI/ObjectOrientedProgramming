#ifndef DAILYEMPLOYEE_H
#define DAILYEMPLOYEE_H

#include "Employee.h"

class DailyEmployee : public Employee {
private:
    int _dayCount, _paymentPerDay;
public:
    DailyEmployee(int a, int b) : _dayCount(a), _paymentPerDay(b) {}
    int salary() override { return _dayCount * _paymentPerDay; }
    string toString() override { return "Daily employee"; }
};

#endif