#ifndef MACHINE_H
#define MACHINE_H
using namespace std;
#include "Pilha.cpp"

class Machine
{
protected:
    string entrada;
    string saida;
    int estado;
    int event;
    Pilha Pilhax;

public:
    Machine();
    void venda(int data, int hora);
};
#endif
