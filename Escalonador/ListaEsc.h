#ifndef LISTAESC_H
#define LISTAESC_H
#include <iostream>
using namespace std;
#include "NodoEsc.cpp"

class ListaEsc
{
private:
    NodoEsc *top, *mid, *auxiliar;
    int n;

public:
    ListaEsc();
    ~ListaEsc();
    void push(int p, int a, int r, int h, int b, void (*task)(void));
    void pop(int &p, int &a, int &r, int &h, int &b, void (*task)(void));
    NodoEsc *get_mid();
    NodoEsc *get_mid_next();
    void set_mid(NodoEsc *nxt);
    void ler(int &p, int &a, int &r, int &h, int &b, void (*task)(void), NodoEsc *nxt);
    void decide(unsigned long int tempo);
    void bloqueia(void (*task)(void));
};
#endif