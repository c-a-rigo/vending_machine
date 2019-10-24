#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
using namespace std;

class Interface
{

public:
    virtual string get_entrada() = 0;
    virtual void processa(string) = 0;
    virtual void report(string refri, int data, int hora, int preco) = 0;
};

#endif