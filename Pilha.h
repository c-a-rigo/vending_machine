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
    void push(string refri, int data, int hora, int preco);
    void pop(string &ref, int &dat, int &hr, int &prec);
    int pilha_vazia();
};

#endif