#ifndef MACHINE_H
#define MACHINE_H
using namespace std;

#include "../Dados/BancoDados.h"

#include "../Interface/Interface.cpp"

#ifdef PC
#include "../Interface/InterfacePC.cpp"
#endif

#ifdef ATL
#include "../Interface/InterfaceAtl.cpp"
#endif

class Machine : public BancoDados
{
protected:
    string entrada;
    string saida;
    int estado;
    int event;
    Interface *inter;

public:
    Machine();
    int venda(string &r, int &p, int &repo, int &venda);
    friend class BancoDados;
};
#endif
