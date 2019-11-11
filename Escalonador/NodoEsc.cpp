#include "NodoEsc.h"

NodoEsc::NodoEsc(int p, int a, int r, int h, int b, void (*task)(void), NodoEsc *nxt)
{
    /*  Funçao para inicializar um novo nodo de escalonamento. 

    Argumentos:
    p: período da tarefa.
    a: prioridade da tarefa.
    r: flag para tarefa pronta.
    h: flag para tarefa habilitada.
    b: flag para tarefa bloqueada.
    ponteiro para a função.
    nxt: ponteiro para o próximo nodo.
    
   */

    periodo = p;
    prioridade = a;
    pronta = r;
    habilita = h;
    bloqueada = b;
    this->task = task;
    count = 0;
    n_count = 0;
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

int NodoEsc::get_prioridade()
{
    return prioridade;
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

unsigned long int NodoEsc::get_count()
{
    return count;
}

unsigned long int NodoEsc::get_n_count()
{

    return n_count;
}

void NodoEsc::set_periodo(int p)
{
    periodo = p;
}

void NodoEsc::set_prioridade(int a)
{
    prioridade = a;
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

void NodoEsc::set_count(unsigned long int c)
{
    count = c;
}

void NodoEsc::set_n_count(unsigned long int nc)
{

    n_count = nc;
}

void NodoEsc::set_funcao(void (*task)(void))
{
    this->task = task;
}

void NodoEsc::set_next(NodoEsc *nxt)
{
    next = nxt;
}
