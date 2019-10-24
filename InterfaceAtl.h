#ifndef INTERFACEATL_H
#define INTERFACEATL_H
#include "Interface.h"

class InterfaceAtl : public Interface
{
protected:
    string entrada1;
    volatile unsigned int *data;
    volatile unsigned int *output;
    volatile unsigned int *direction;

public:
    InterfaceAtl();
    string get_entrada();
    void processa(string);
    void report(string refri, int data, int hora, int preco);
};
#endif
