#include "NodoEsc.h"

NodoEsc::NodoEsc(string &r, int &t, int &o, int &k, NodoEsc *nxt)
{
    this->refri = r;
    this->data = t;
    this->hora = o;
    this->preco = k;
    next = nxt;
}

string NodoEsc::get_refri()
{
    return refri;
}

int NodoEsc::get_data()
{
    return data;
}

int NodoEsc::get_hora()
{
    return hora;
}

int NodoEsc::get_preco()
{
    return preco;
}

NodoEsc *NodoEsc::get_next()
{
    return next;
}

void NodoEsc::set_refri(string refri)
{
    this->refri = refri;
}

void NodoEsc::set_data(int data)
{
    this->data = data;
}

void NodoEsc::set_hora(int hora)
{
    this->hora = hora;
}

void NodoEsc::set_preco(int preco)
{
    this->preco = preco;
}

void NodoEsc::set_next(NodoEsc *nxt)
{
    next = nxt;
}
