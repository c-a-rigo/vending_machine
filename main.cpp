#include <iostream>
#include <string>
#include <stdlib.h>

#define PC

#include "Machine/Machine.cpp"
#include "Dados/BancoDados.cpp"
#include "Escalonador/Escalonador.cpp"

int main()
{
    string sell;
    int money;
    int repo = 0;
    int venda = 0;

    Machine Venda;
    BancoDados Dados;

    Escalonador Escalonador;

    Escalonador.escalona(1, 2, 0, 1, 0, &Machine::teste2); //periodo, prioridade, pronta, habilitada, bloqueada, funçao
    Escalonador.executa();

    while (1)
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
    }
}
