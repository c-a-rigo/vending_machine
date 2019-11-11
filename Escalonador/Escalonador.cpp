#include "Escalonador.h"

Escalonador::Escalonador(/* args */)
{
    tempo = 0;
}
Escalonador::~Escalonador() {}

void Escalonador::escalona(int p, int a, int r, int h, int b, void (*task)(void))
{

    Lista.push(p, a, r, h, b, task);
}

void Escalonador::executa()
{
    tempo++;

    cout << endl
         << "t" << tempo << " ";

    Lista.decide(tempo);
}

void Escalonador::bloqueia(void (*task)(void))
{
    Lista.bloqueia(task);
}