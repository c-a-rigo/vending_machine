#include "BancoDados.h"

BancoDados::BancoDados()
{
}

void BancoDados::registra(string refri, int preco)
{
    Pilhax.push(refri, preco);
}

void BancoDados::reporta(Machine M)
{
    int n_meet = 0;
    int n_etirps = 0;

    string periodo = "nenhum";

    int manha = 0;
    int tarde = 0;
    int noite = 0;

    string a;
    int b;
    int c;
    int d;

    while (!Pilhax.pilha_vazia())
    {

        Pilhax.pop(a, b, c, d);
        Listax.push(a, b, c, d);

        if (a == "meet")
            n_meet++;
        else if (a == "etirps")
            n_etirps++;

        if ((c >= 0) && (c < 1200))
            manha++;

        else if ((c >= 1200) && (c < 1900))
            tarde++;

        else if ((c >= 1900) && (c < 2359))
            noite++;

        //cout << n_meet << n_etirps << c << manha << tarde << noite << endl;
    }

    if ((manha >= tarde) && (tarde >= noite))
        periodo = "manha";
    else if ((tarde >= noite) && (noite >= manha))
        periodo = "tarde";
    else if ((noite >= manha) && (manha >= tarde))
        periodo = "noite";

    if (n_etirps > n_meet)
        M.inter->report_final("etirps", n_etirps, periodo);
    else
        M.inter->report_final("meet", n_meet, periodo);
}

void BancoDados::read_all_list(Machine M)
{
    string a;
    int b;
    int c;
    int d;
    Nodo *n;

    n = Listax.get_mid();

    while (n != 0)
    {
        Listax.ler(a, b, c, d, n);
        M.inter->report(a, b, c, d);
        n = Listax.get_mid_next();
        Listax.set_mid(n);
    }
}