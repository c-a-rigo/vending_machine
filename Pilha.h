#ifndef PILHA_H
#define PILHA_H
#include <iostream>
using namespace std;
#include "Nodo.cpp"

class Pilha
{
private:
    Nodo *topo, *aux;

public:
    Pilha();
    ~Pilha();
    void push(string refri, int preco);
    void pop(string &r, int &t, int &o, int &k);
    int pilha_vazia();
};

#endif