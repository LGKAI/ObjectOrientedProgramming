#include <bits/stdc++.h>
#include "StudentProvider.h"
#include "StudentsToTableConverter.h"
using namespace std;

int main() {
    auto students = StudentProvider::getAll();

    std::vector<std::string> headers = {"So TT", "Ma SV", "Ho ten", "mail"};
    std::vector<int> columnSizes = {8, 11, 21, 22};
    StudentsToTableConverter table(headers, columnSizes);

    auto info = table.convert(students);
    std::cout << info;

    return 0;
}