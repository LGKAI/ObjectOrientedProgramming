#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

int main() {
    Student s1("Messi", "M10", 38, "Argentina", 4.0);
    s1.displayInfo();
    cout << endl;

    Student s2;
    s2.setFullName("Ronaldo");
    s2.setStudentID("CR7");
    s2.setAge(40);
    s2.setAddress("Portugal");
    s2.setGPA(3.9);
    s2.displayInfo();

    return 0;
}
