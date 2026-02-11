#ifndef DATE_H_
#define DATE_H_

class Date {
private:
    int d, m, y;
    
public:
    Date();
    virtual ~Date();

    void input();
    void output();
};

#endif