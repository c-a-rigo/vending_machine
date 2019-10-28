#ifndef BANCODADOS_H
#define BANCODADOS_H
using namespace std;

class Machine;

#include "Nodo.cpp"
#include "Pilha.cpp"
#include "Lista.cpp"

class BancoDados
{
protected:
    Pilha Pilhax;
    Lista Listax;

public:
    BancoDados();
    void registra(string refri, int preco);
    void reporta(Machine M);
    void read_all_list(Machine M);
};
#endif