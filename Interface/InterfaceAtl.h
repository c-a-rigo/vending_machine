#ifndef INTERFACEATL_H
#define INTERFACEATL_H
#include "Interface.h"

class InterfaceAtl : public Interface
{
protected:
    string entrada1;
    volatile unsigned int *data_atl;
    volatile unsigned int *output_atl;
    volatile unsigned int *direction_atl;

public:
    InterfaceAtl();
    string get_entrada();
    void processa(string);
    void report(string refri, int data, int hora, int preco);
    void report_final(string x, int y, string f);
};
#endif
