#include "GPS.h"
#include <iostream>

GPS::GPS() : latitude(0.0), longitude(0.0) {}

GPS::GPS(double lat, double lon) : latitude(lat), longitude(lon) {}

void GPS::setLatitude(double lat) {
    latitude = lat;
}

void GPS::setLongitude(double lon) {
    longitude = lon;
}

double GPS::getLatitude() const {
    return latitude;
}

double GPS::getLongitude() const {
    return longitude;
}

void GPS::displayCoordinates() const {
    std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
}