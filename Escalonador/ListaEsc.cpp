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

void ListaEsc::push(int p, int a, int r, int h, int b, void (*task)(void))
{
    auxiliar = new NodoEsc(p, a, r, h, b, task, top);
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

void ListaEsc::ler(int &p, int &a, int &r, int &h, int &b, void (*task)(void), NodoEsc *nxt)
{
    if (nxt)
    {
        cout << nxt->get_periodo() << endl;
        cout << nxt->get_atraso() << endl;
        cout << nxt->get_pronta() << endl;
        cout << nxt->get_habilita() << endl;
        cout << nxt->get_bloqueada() << endl;
        cout << nxt->get_void() << endl;
        cout << nxt->get_next() << endl;
    }
}

void ListaEsc::teste()
{

    cout << top->get_periodo() << endl;
    cout << top->get_atraso() << endl;
    cout << top->get_pronta() << endl;
    cout << top->get_habilita() << endl;
    cout << top->get_bloqueada() << endl;
    cout << top->get_next() << endl;

    void (*ttt)(void);
    ttt = top->get_void();
    ttt();
}