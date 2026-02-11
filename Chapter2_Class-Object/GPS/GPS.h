#ifndef GPS_H
#define GPS_H

class GPS {
private:
    double latitude;
    double longitude;

public:
    GPS();                            // Constructor mặc định
    GPS(double lat, double lon);      // Constructor có tham số

    void setLatitude(double lat);     // Thiết lập vĩ độ
    void setLongitude(double lon);    // Thiết lập kinh độ

    double getLatitude() const;       // Lấy vĩ độ
    double getLongitude() const;      // Lấy kinh độ

    void displayCoordinates() const;  // Hiển thị tọa độ
};

#endif