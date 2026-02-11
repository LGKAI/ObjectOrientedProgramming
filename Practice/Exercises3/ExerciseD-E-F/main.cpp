#include "Employee.h"
#include "Office.h"
#include "Engineer.h"
#include "EmployeeList.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    EmployeeList list;
    list.add("Office,Alice,1001,3000,500");
    list.add("Engineer,Bob,1002,3200,10,50");
    list.add("Office,Carol,1003,2900,300");
    list.remove(1002);
    list.display();
    return 0;
}