#ifndef NODOESC_H
#define NODOESC_H
#include <iostream>
using namespace std;

class NodoEsc
{
    string refri;
    int data;
    int hora;
    int preco;
    NodoEsc *next;

public:
    NodoEsc(string &r, int &t, int &o, int &k, NodoEsc *nxt);
    string get_refri();
    int get_data();
    int get_hora();
    int get_preco();
    NodoEsc *get_next();
    void set_refri(string refri);
    void set_data(int data);
    void set_hora(int hora);
    void set_preco(int preco);
    void set_next(NodoEsc *nxt);
};

#endif