#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

#include "Machine/Machine.cpp"
#include "Dados/BancoDados.cpp"
#include "ClockCalendar/ClockCalendar.cpp"

Machine Venda;
BancoDados Dados;
ClockCalendar Calendario(2, 10, 2019, 6, 07, 55, 1);
//                                    ^
//                                    |
//                    mes, dia, ano, hora, min, seg, ispm

#ifdef PC

#include <pthread.h>

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
    th = 0;
}

void vender()
{
    if (!th) //se não há uma thread ativa então cria
    {
        th = 1;
        pthread_t t1;
        pthread_create(&t1, NULL, &linha, NULL);
    }
}

#endif

#ifdef ATL

void sell()
{
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

#endif
void reportar()
{

    if (repo1)
    {
        Dados.read_all_list(Venda);

        repo1 = 0;
    }

    if (repo)
    {
        Dados.reporta(Venda);

        repo = 0;
    }

    // cout << "REPO" << endl;
}

void atualiza_tempo()
{

    string proc_hora = "", proc_data = "";

    int m, d, y;
    int hr, mi, sec, is_pm;

    for (int l = 0; l < 610; l++)
    {
        ++Calendario;
    }

    ++Calendario;
    Calendario.readCalendar(m, d, y);
    Calendario.readClock(hr, sec, mi, is_pm);

    std::string s_mes = std::to_string(m);
    std::string s_dia = std::to_string(d);
    std::string s_ano = std::to_string(y);
    std::string s_hora = std::to_string(hr);
    std::string s_min = std::to_string(mi);
    std::string s_seg = std::to_string(sec);

    if (is_pm == 0)
    {
        proc_data = s_dia + s_mes + s_ano;

        if (d < 10)
            proc_data = "0" + s_dia + s_mes + s_ano;
        if (m < 10)
            proc_data = s_dia + "0" + s_mes + s_ano;
        if (d < 10 && m < 10)
            proc_data = "0" + s_dia + "0" + s_mes + s_ano;

        int i = atoi(proc_data.c_str());
        g_data = i;

        proc_hora = s_hora + s_min;
        if (mi < 10)
            proc_hora = s_hora + "0" + s_min;

        i = atoi(proc_hora.c_str());
        g_hora = i;
    }
    else
    {
        proc_data = s_dia + s_mes + s_ano;
        if (d < 10)
            proc_data = "0" + s_dia + s_mes + s_ano;
        if (m < 10)
            proc_data = s_dia + "0" + s_mes + s_ano;
        if (d < 10 && m < 10)
            proc_data = "0" + s_dia + "0" + s_mes + s_ano;

        int i = atoi(proc_data.c_str());

        g_data = i;

        hr = hr + 12;
        std::string s_hora = std::to_string(hr);

        proc_hora = s_hora + s_min;
        if (mi < 10)
            proc_hora = s_hora + "0" + s_min;

        i = atoi(proc_hora.c_str());
        g_hora = i;
    }

#ifdef HR

    if (is_pm == 0)
    {
        proc_data = s_dia + "/" + s_mes + "/" + s_ano;

        if (d < 10)
            proc_data = "0" + s_dia + "/" + s_mes + "/" + s_ano;
        if (m < 10)
            proc_data = s_dia + "/" + "0" + s_mes + "/" + s_ano;
        if (d < 10 && m < 10)
            proc_data = "0" + s_dia + "/" + "0" + s_mes + "/" + s_ano;

        proc_hora = s_hora + ":" + s_min + ":" + s_seg + " a.m.";
        if (mi < 10)
            proc_hora = s_hora + ":" + "0" + s_min + ":" + s_seg + " a.m.";
        if (sec < 10)
            proc_hora = s_hora + ":" + s_min + ":" + "0" + s_seg + " a.m.";
        if (mi < 10 && sec < 10)
            proc_hora = s_hora + ":" + "0" + s_min + ":" + "0" + s_seg + " a.m.";
    }
    else
    {
        hr = hr - 12;
        proc_data = s_dia + "/" + s_mes + "/" + s_ano;
        if (d < 10)
            proc_data = "0" + s_dia + "/" + s_mes + "/" + s_ano;
        if (m < 10)
            proc_data = s_dia + "/" + "0" + s_mes + "/" + s_ano;
        if (d < 10 && m < 10)
            proc_data = "0" + s_dia + "/" + "0" + s_mes + "/" + s_ano;

        proc_hora = s_hora + ":" + s_min + ":" + s_seg + " p.m.";
        if (mi < 10)
            proc_hora = s_hora + ":" + "0" + s_min + ":" + s_seg + " p.m.";
        if (sec < 10)
            proc_hora = s_hora + ":" + s_min + ":" + "0" + s_seg + " p.m.";
        if (mi < 10 && sec < 10)
            proc_hora = s_hora + ":" + "0" + s_min + ":" + "0" + s_seg + " p.m.";
    }

    //string aab = s_mes + "/" + s_dia + "/" + s_ano + " " + s_hora + ":" + s_min + ":" + s_seg;

    cout << endl;
    cout << proc_data << " " << proc_hora << endl;

#endif
}