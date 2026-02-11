#include <iostream>
#include <string>
#include "Warehouse.h"
#include "Device.h"
#include "Laptop.h"
#include "Smartphone.h"
using namespace std;

int main()
{
    /*
    Device *d = new Laptop("MacBookAir", "M2A123", 2022, 999.99, 120);
    d->display();
    d = new Smartphone("iPhone14", "IP14Pro", 2022, 1099.00, 150.5);
    d->display();
    */

    Warehouse wh;
    wh.add("Laptop,MacBookAir,M2A123,2022, 999.99, 120");
    wh.add("Smartphone,iPhone14,IP4Pro,2022,1099,150.5");
    wh.display();
    wh.remove("M2A123");
    wh.display();
    return 0;
}