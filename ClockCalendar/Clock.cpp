#include <iostream>
#include <string>
#include <stdlib.h>

#include "Clock.h"
#include "Calendar.h"
#include "ClockCalendar.h"

Clock::Clock()
{
    hr = 0;
    min = 0;
    sec = 0;
    is_pm = 0;
}

Clock::Clock(int h, int s, int m, int pm)
{
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::setClock(int h, int s, int m, int pm)
{
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::readClock(int &h, int &s, int &m, int &pm)
{
    h = hr;
    m = min;
    s = sec;
    pm = is_pm;
}

void Clock::advance()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        min++;
    }

    if (min > 59)
    {
        min = 0;
        hr++;
    }

    if (hr == 13)
    {
        hr = 1;
    }

    if (hr == 12 && min == 0 && sec == 0)
    {
        is_pm = !is_pm;
    }
}

ostream &operator<<(ostream &out, Clock &c)
{
    out << c.hr << ":";
    out << c.min << ":";
    out << c.sec;
    return out;
}
