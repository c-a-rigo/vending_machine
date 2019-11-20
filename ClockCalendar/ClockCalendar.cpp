#include "ClockCalendar.h"
#include "Clock.cpp"
#include "Calendar.cpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m,
                             int s, int pm) : Clock(h, s, m, pm), Calendar(mt, d, y)
{
}

void ClockCalendar::advance()
{                             // avançar o calendário, caso o clock
    int wasPm = Clock::is_pm; // mude de AM para PM.
    Clock::advance();
    if (wasPm && !Clock::is_pm)
        Calendar::advance();
}

void operator++(ClockCalendar &t)
{
    t.advance();
}

ostream &operator<<(ostream &out, ClockCalendar &cc)
{
}