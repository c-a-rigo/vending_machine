#include "Pilha.h"

Pilha::Pilha()
{
    topo = 0;
}

Pilha::~Pilha()
{
    /*  Node *cursor = topo;
        while (topo)
        {
            cursor = cursor->getNext();
            delete topo;
            topo = cursor;
        }
        topo = 0; // Officially empty */
}

void Pilha::push(string refri, int data, int hora, int preco)
{
    aux = new Nodo(refri, data, hora, preco, topo);
    //aux->set_next(topo);
    topo = aux;
}

void Pilha::pop(string &ref, int &dat, int &hr, int &prec)
{
    aux = topo;
    if (aux)
    {
        topo = aux->get_next();
        ref = aux->get_refri();
        dat = aux->get_data();
        hr = aux->get_hora();
        prec = aux->get_preco();
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