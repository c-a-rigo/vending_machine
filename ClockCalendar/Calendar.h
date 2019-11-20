#ifndef CALENDAR_H
#define CALENDAR_H
using namespace std;

class Calendar
{
protected:
    int mo, day, yr;

public:
    Calendar();

    Calendar(int m, int d, int y);

    void setCalendar(int m, int d, int y);

    void readCalendar(int &m, int &d, int &y);

    void advance();

    friend ostream &operator<<(ostream &out, Calendar &C);
};

#endif