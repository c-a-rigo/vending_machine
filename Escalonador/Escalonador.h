#ifndef ESCALONADOR_H
#define ESCALONADOR_H
using namespace std;

#include "ListaEsc.cpp"

class Escalonador
{
private:
    ListaEsc Lista;
    unsigned long int tempo;

public:
    Escalonador(/* args */);
    ~Escalonador();
    void escalona(int p, int a, int r, int h, int b, void (*task)(void));
    void executa();
    void bloqueia(void (*task)(void));
};

#endif