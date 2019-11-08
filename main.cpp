#include <iostream>
#include <string>
#include <stdlib.h>

#define ATL

#include "Machine/Machine.cpp"
#include "Dados/BancoDados.cpp"
#include "Escalonador/ListaEsc.cpp"

int main()
{
    string sell;
    int money;
    int repo = 0;
    int venda = 0;

    Machine Venda;
    BancoDados Dados;

    ListaEsc Listax;

    Listax.push(1, 2, 3, 4, 5, &Venda.teste2);
    Listax.teste();

    /* while (1)
    {
        Venda.venda(sell, money, repo, venda);

        if (venda)
        {
            Dados.registra(sell, money);
            venda = 0;
        }
        if (repo)
        {
            Dados.reporta(Venda);
            //Dados.read_all_list(Venda);
            repo = 0;
        }
    } */
}
