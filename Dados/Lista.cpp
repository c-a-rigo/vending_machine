#include "Lista.h"

Lista::Lista()
{
    top = 0;
}

Lista::~Lista()
{
    while (top)
    {
        auxiliar = top->get_next();
        delete top;
        top = auxiliar;
    }
    top = 0;
    auxiliar = 0;
    mid = 0;
}

void Lista::push(string &r, int &t, int &o, int &k)
{
    auxiliar = new Nodo(r, t, o, k, top);
    //aux->set_next(topo);
    top = auxiliar;
    mid = top;
}

Nodo *Lista::get_mid()
{
    return mid;
}

Nodo *Lista::get_mid_next()
{
    return mid->get_next();
}

void Lista::set_mid(Nodo *nxt)
{
    mid = nxt;
}

void Lista::ler(string &r, int &t, int &o, int &k, Nodo *n)
{
    if (n)
    {
        r = n->get_refri();
        t = n->get_data();
        o = n->get_hora();
        k = n->get_preco();
        n = n->get_next();
    }
}