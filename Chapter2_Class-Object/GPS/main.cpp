#include <iostream>
#include "GPS.h"
using namespace std;

int main() {
    GPS location(10.762622, 106.660172);  // Tọa độ TP.HCM

    location.displayCoordinates();

    location.setLatitude(21.028511);
    location.setLongitude(105.804817);    // Tọa độ Hà Nội

    std::cout << "Updated Coordinates:" << std::endl;
    location.displayCoordinates();

    return 0;
}