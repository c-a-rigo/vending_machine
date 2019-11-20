#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "ClockCalendar.cpp"

int main()
{
    string hora = "", data = "";
    ClockCalendar Calendario(9, 1, 2019, 17, 01, 55, 1);
    int m, d, y;
    int hr, mi, sec, is_pm;
    while (true)
    {

        usleep(1000000);

        ++Calendario;
        Calendario.readCalendar(m, d, y);
        Calendario.readClock(hr, sec, mi, is_pm);

        std::string str1 = std::to_string(m);
        std::string str2 = std::to_string(d);
        std::string str3 = std::to_string(y);
        std::string str4 = std::to_string(hr);
        std::string str6 = std::to_string(mi);

        if (is_pm == 0)
        {
            if (d < 10)
                data = "0" + str2 + str1 + str3;
            if (m < 10)
                data = str2 + "0" + str1 + str3;
            if (d < 10 && m < 10)
                data = "0" + str2 + "0" + str1 + str3;

            int i = std::stoi(data);
            cout << i << endl;

            if (mi < 9)
                hora = str4 + "0" + str6;
            else
            {
                hora = str4 + str6;
            }

            i = std::stoi(hora);
            cout << i << endl;
        }
        else
        {
            if (d < 10)
                data = "0" + str2 + str1 + str3;
            if (m < 10)
                data = str2 + "0" + str1 + str3;
            if (d < 10 && m < 10)
                data = "0" + str2 + "0" + str1 + str3;

            int i = std::stoi(data);
            cout << i << endl;

            std::string str4 = std::to_string(hr);

            if (mi < 9)
                hora = str4 + "0" + str6;
            else
            {
                hora = str4 + str6;
            }
            i = std::stoi(hora);
            cout << i << endl;
        }
    }
}