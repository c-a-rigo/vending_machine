#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
    string refri;
    int data;
    int hora;
    int preco;
    Nodo *next;

public:
    Nodo(string &r, int &t, int &o, int &k, Nodo *nxt);
    string get_refri();
    int get_data();
    int get_hora();
    int get_preco();
    Nodo *get_next();
    void set_refri(string refri);
    void set_data(int data);
    void set_hora(int hora);
    void set_preco(int preco);
    void set_next(Nodo *nxt);
};

#endif