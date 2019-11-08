#ifndef NODOESC_H
#define NODOESC_H
#include <iostream>
using namespace std;

typedef void (*VoidFn)();

class NodoEsc
{
    int periodo;
    int atraso;
    int pronta;
    int habilita;
    int bloqueada;
    void (*task)(void);
    NodoEsc *next;

public:
    NodoEsc(int p, int a, int r, int h, int b, void (*task)(void), NodoEsc *nxt);
    int get_periodo();
    int get_atraso();
    int get_pronta();
    int get_habilita();
    int get_bloqueada();
    VoidFn get_void();
    NodoEsc *get_next();

    void set_periodo(int p);
    void set_atraso(int a);
    void set_pronta(int r);
    void set_habilita(int h);
    void set_bloqueada(int b);
    void set_funcao(void (*task)(void));
    void set_next(NodoEsc *nxt);
};

#endif