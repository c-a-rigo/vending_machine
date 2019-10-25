#include "Pilha.h"

Pilha::Pilha()
{
    topo = 0;
}

Pilha::~Pilha()
{
    /*Node *cursor = topo;
        while (topo)
        {
            cursor = cursor->getNext();
            delete topo;
            topo = cursor;
        }
        topo = 0; // Officially empty */
}

void Pilha::push(string refri, int preco)
{
    aux = new Nodo(refri, preco, topo);
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