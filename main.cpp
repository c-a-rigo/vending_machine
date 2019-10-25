#include <iostream>
#include <string>
#include <stdlib.h>

#define ATL

extern int repo = 0;
extern int data = 12121999;
extern int hora = 1900;

#include "Machine.cpp"
#include "BancoDados.cpp"

int main()
{

    Machine Venda;
    BancoDados Dados;

    while (1)
    {
        if (Venda.venda())
        {
            //cout << data;
            Dados.reporta();
        }

        cout << repo;
    }
}
