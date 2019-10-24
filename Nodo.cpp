#include "Nodo.h"

Nodo::Nodo(string refri, int data, int hora, int preco, Nodo *nxt)
{
    this->refri = refri;
    this->data = data;
    this->hora = hora;
    this->preco = preco;
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