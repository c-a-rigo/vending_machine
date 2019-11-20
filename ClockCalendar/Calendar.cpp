#include <iostream>
#include <string>
#include <stdlib.h>

#include "Clock.h"
#include "Calendar.h"
#include "ClockCalendar.h"

using namespace std;

Calendar::Calendar()
{
    mo = 0;
    day = 0;
    yr = 0;
}

Calendar::Calendar(int m, int d, int y)
{
    mo = m;
    day = d;
    yr = y;
}

void Calendar::setCalendar(int m, int d, int y)
{
    mo = m;
    day = d;
    yr = y;
}

void Calendar::readCalendar(int &m, int &d, int &y)
{
    m = mo;
    d = day;
    y = yr;
}

void Calendar::advance()
{
    day++;

    if (day > 30)
    {
        day = 1;
        mo++;
    }

    if (mo > 12)
    {
        mo = 1;
        yr++;
    }
}

ostream &operator<<(ostream &out, Calendar &C)
{
    out << C.day << "/";
    out << C.mo << "/";
    out << C.yr;
    return out;
}
