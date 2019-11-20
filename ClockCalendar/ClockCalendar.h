#ifndef CLOCKCALENDAR_H
#define CLOCKCALENDAR_H

using namespace std;

#include "Clock.h"
#include "Calendar.h"

class ClockCalendar : public Clock, public Calendar
{

public:
    ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm);
    void advance();
    friend void operator++(ClockCalendar &);
    friend ostream &operator<<(ostream &out, ClockCalendar &cc);
};

#endif