#include "ListaEsc.h"

ListaEsc::ListaEsc()
{
    top = 0;
}

ListaEsc::~ListaEsc()
{
    while (top) //enquanto houver nodos na lista
    {
        auxiliar = top->get_next();
        delete top;
        top = auxiliar;
    }
    top = 0;
    auxiliar = 0;
    mid = 0;
}

void ListaEsc::push(string &r, int &t, int &o, int &k)
{
    auxiliar = new NodoEsc(r, t, o, k, top);
    //aux->set_next(topo);
    top = auxiliar;
    mid = top;
}

NodoEsc *ListaEsc::get_mid()
{
    return mid;
}

NodoEsc *ListaEsc::get_mid_next()
{
    return mid->get_next();
}

void ListaEsc::set_mid(NodoEsc *nxt)
{
    mid = nxt;
}

void ListaEsc::ler(string &r, int &t, int &o, int &k, NodoEsc *n)
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