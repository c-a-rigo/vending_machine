#ifndef BANCODADOS_H
#define BANCODADOS_H
using namespace std;
#include "Pilha.cpp"

class BancoDados
{
protected:
    Pilha Pilhax;

public:
    BancoDados();
    void registra(string refri, int preco);
    void reporta();
};
#endif