#ifndef MACHINE_H
#define MACHINE_H
using namespace std;

#include "BancoDados.h"

class Machine : public BancoDados
{
protected:
    string entrada;
    string saida;
    int estado;
    int event;

public:
    Machine();
    int venda();
};
#endif
