#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "Machine/Machine.cpp"
#include "Dados/BancoDados.cpp"
#include "ClockCalendar/ClockCalendar.cpp"

Machine Venda;
BancoDados Dados;
ClockCalendar Calendario(20, 11, 2019, 6, 07, 55, 1);

void *linha(void *)
{
    // cout << "SELL" << endl;

    string sell;
    int money;

    int venda = 0;

    Venda.venda(sell, money, repo, venda);

    if (venda)
    {
        Dados.registra(sell, money);
        venda = 0;
    }
}

void sell()
{
    pthread_t t1;
    //pthread_t *outsideMain = malloc(sizeof(pthread_t));

    pthread_create(&t1, NULL, &linha, NULL);
}

void repor()
{
    if (repo)
    {
        Dados.reporta(Venda);
        //Dados.read_all_list(Venda);
        repo = 0;
    }

    // cout << "REPO" << endl;
}

void atualiza_tempo()
{

    string aro = "", ata = "";

    int m, d, y;
    int hr, mi, sec, is_pm;

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
            ata = "0" + str2 + str1 + str3;
        if (m < 10)
            ata = str2 + "0" + str1 + str3;
        if (d < 10 && m < 10)
            ata = "0" + str2 + "0" + str1 + str3;
        else
        {
            ata = str2 + str1 + str3;
        }

        int i = atoi(ata.c_str());
        g_data = i;

        if (mi < 10)
            aro = str4 + "0" + str6;
        else
        {
            aro = str4 + str6;
        }

        i = atoi(aro.c_str());
        g_hora = i;
    }
    else
    {
        if (d < 10)
            ata = "0" + str2 + str1 + str3;
        if (m < 10)
            ata = str2 + "0" + str1 + str3;
        if (d < 10 && m < 10)
            ata = "0" + str2 + "0" + str1 + str3;
        else
        {
            ata = str2 + str1 + str3;
        }

        int i = atoi(ata.c_str());

        g_data = i;

        std::string str4 = std::to_string(hr);

        if (mi < 10)
            aro = str4 + "0" + str6;
        else
        {
            aro = str4 + str6;
        }
        i = atoi(aro.c_str());
        g_hora = i;
    }

#ifdef HR

    std::string str5 = std::to_string(sec);

    string aab = str1 + "/" + str2 + "/" + str3 + " " + str4 + ":" + str6 + ":" + str5;

    cout << aab << endl;

#endif
}