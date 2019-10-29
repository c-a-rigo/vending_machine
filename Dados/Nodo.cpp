#include "Nodo.h"

Nodo::Nodo(string &r, int &t, int &o, int &k, Nodo *nxt)
{
    /*  Construtor de um nodo. 

    Argumentos:
    r: O refrigerante vendido.
    t: A data da venda.
    o: A hora da venda.
    k: O preco do refrigerante.
    nxt: Ponteiro do nodo anterior.
    
   */

    this->refri = r;
    this->data = t;
    this->hora = o;
    this->preco = k;
    next = nxt;
}

string Nodo::get_refri()
{
    return refri;
}

int Nodo::get_data()
{
    return data;
}

int Nodo::get_hora()
{
    return hora;
}

int Nodo::get_preco()
{
    return preco;
}

Nodo *Nodo::get_next()
{
    return next;
}

void Nodo::set_refri(string refri)
{
    this->refri = refri;
}

void Nodo::set_data(int data)
{
    this->data = data;
}

void Nodo::set_hora(int hora)
{
    this->hora = hora;
}

void Nodo::set_preco(int preco)
{
    this->preco = preco;
}

void Nodo::set_next(Nodo *nxt)
{
    next = nxt;
}
