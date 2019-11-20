#ifndef CLOCK_H
#define CLOCK_H
using namespace std;

class Clock
{
protected:
    int hr, min, sec, is_pm;

public:
    Clock();

    Clock(int h, int s, int m, int pm);

    void setClock(int h, int s, int m, int pm);

    void readClock(int &h, int &s, int &m, int &pm);

    void advance();

    friend ostream& operator<<(ostream& out, Clock &c);
};

#endif