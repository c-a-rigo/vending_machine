#ifndef LISTAESC_H
#define LISTAESC_H
#include <iostream>
using namespace std;
#include "NodoEsc.h"

class ListaEsc
{
private:
    NodoEsc *top, *mid, *auxiliar;

public:
    ListaEsc();
    ~ListaEsc();
    void push(string &r, int &t, int &o, int &k);
    void pop(string &r, int &t, int &o, int &k);
    NodoEsc *get_mid();
    NodoEsc *get_mid_next();
    void set_mid(NodoEsc *nxt);
    void ler(string &r, int &t, int &o, int &k, NodoEsc *nxt);
};
#endif