#include <iostream>
#include <string>
#include <stdlib.h>

#include "Machine.cpp"

int main()
{

    int data = 12121999;
    int hora = 1900;

    Machine Venda;

    while (1)
    {
        Venda.venda(data, hora);
    }
}
