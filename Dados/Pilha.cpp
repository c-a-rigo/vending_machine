#include "Pilha.h"
#include "../common.h"

Pilha::Pilha()
{
    topo = 0;
}

Pilha::~Pilha()
{
    while (topo)
    {
        aux = topo->get_next();
        delete topo;
        topo = aux;
    }
    topo = 0;
    aux = 0;
}

void Pilha::push(string refri, int preco)
{
    aux = new Nodo(refri, g_data, g_hora, preco, topo);
    //aux->set_next(topo);

    topo = aux;
}

void Pilha::pop(string &r, int &t, int &o, int &k)
{

    aux = topo;

    if (aux)
    {
        topo = aux->get_next();
        r = aux->get_refri();
        t = aux->get_data();
        o = aux->get_hora();
        k = aux->get_preco();
        delete (aux);
    }
}

int Pilha::pilha_vazia()
{
    if (topo)
        return 0;
    else
        return 1;
}