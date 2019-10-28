#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

class Lista
{
private:
    Nodo *top, *mid, *auxiliar;

public:
    Lista();
    ~Lista();
    void push(string &r, int &t, int &o, int &k);
    void pop(string &r, int &t, int &o, int &k);
    Nodo *get_mid();
    Nodo *get_mid_next();
    void set_mid(Nodo *nxt);
    void ler(string &r, int &t, int &o, int &k, Nodo *nxt);
};
#endif