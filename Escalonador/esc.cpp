#include <iostream>
#include <string>
#include <stdlib.h>

#include "ListaEsc.cpp"

#include "../Machine/Machine.cpp"
#include "../Dados/BancoDados.cpp"

void foo()
{
    cout << "I was here." << endl;
}

int main()
{
    Machine Venda;
    ListaEsc Listax;

    Listax.push(1, 2, 3, 4, 5, &Venda.venda);
    Listax.teste();
}
