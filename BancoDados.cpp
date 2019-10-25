#include "BancoDados.h"

BancoDados::BancoDados(/* args */)
{
}

void BancoDados::registra(string refri, int preco)
{
    Pilhax.push(refri, preco);
}

void BancoDados::reporta()
{
    Interface *in;

#ifdef PC
    in = new InterfacePc;
#endif

#ifdef ATL
    in = new InterfaceAtl;
#endif
    string a;
    int b;
    int c;
    int d;

    while (!Pilhax.pilha_vazia())
    {
        Pilhax.pop(a, b, c, d);

        in->report(a, b, c, d);
    }
}