#ifndef INTERFACEPC_H
#define INTERFACEPC_H
#include "Interface.h"

class InterfacePc : public Interface
{
protected:
    string entrada1;

public:
    string get_entrada();
    void processa(string);
    void report(string refri, int data, int hora, int preco);
    void report_final(string x, int y, string f, int z);
};
#endif
