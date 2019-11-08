#include "NodoEsc.h"

NodoEsc::NodoEsc(int p, int a, int r, int h, int b, void (*task)(void), NodoEsc *nxt)
{
    periodo = p;
    atraso = a;
    pronta = r;
    habilita = h;
    bloqueada = b;
    this->task = task;
    next = nxt;
}

VoidFn NodoEsc::get_void()
{
    return task;
}

int NodoEsc::get_periodo()
{
    return periodo;
}

int NodoEsc::get_atraso()
{
    return atraso;
}

int NodoEsc::get_pronta()
{
    return pronta;
}

int NodoEsc::get_habilita()
{
    return habilita;
}

int NodoEsc::get_bloqueada()
{
    return bloqueada;
}

NodoEsc *NodoEsc::get_next()
{
    return next;
}

void NodoEsc::set_periodo(int p)
{
    periodo = p;
}

void NodoEsc::set_atraso(int a)
{
    atraso = a;
}

void NodoEsc::set_pronta(int r)
{
    pronta = r;
}

void NodoEsc::set_habilita(int h)
{
    habilita = h;
}

void NodoEsc::set_bloqueada(int b)
{
    bloqueada = b;
}

void NodoEsc::set_funcao(void (*task)(void))
{
    this->task = task;
}

void NodoEsc::set_next(NodoEsc *nxt)
{
    next = nxt;
}
