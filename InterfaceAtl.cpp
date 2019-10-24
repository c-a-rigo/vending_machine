#include <iostream>
#include <string>
#include <stdlib.h>

#include "InterfaceAtl.h"

InterfaceAtl::InterfaceAtl()
{
    data = (volatile unsigned int *)0x80000a00;
    output = (volatile unsigned int *)0x80000a04;
    direction = (volatile unsigned int *)0x80000a08;

    *direction = 0xffffffff;
}

string InterfaceAtl::get_entrada()
{
    int i;

    *output = 0x00000000;

    while (*data == 0)
        ;

    if (*data == 65536)
        entrada1 = "report";

    if (*data == 524288)
        entrada1 = "m050";

    if (*data == 262144)
        entrada1 = "m100";

    if (*data == 131072)
        entrada1 = "dev";

    if (*data == 4096)
        entrada1 = "meet";

    if (*data == 1048576)
        entrada1 = "etirps";

    cout << entrada1;

    for (i = 0; i < 600000; i++)
        ;

    return entrada1;
}

void InterfaceAtl::processa(string saida)
{
    int i;

    *direction = 0xffffffff;
    cout << saida;

    if (saida == "meet")
    {
        *output = 0x00000010;
    }

    else if (saida == "etirps")
    {
        *output = 0x00000008;
    }

    else if (saida == "d025")
    {
        *output = 0x00000001;
    }

    else if (saida == "d050")
    {
        *output = 0x00000002;
    }

    else if (saida == "d075")
    {
        *output = 0x00000003;
    }

    else if (saida == "d100")
    {
        *output = 0x00000004;
    }

    for (i = 0; i < 1000000; i++)
        ;
}

void InterfaceAtl::report(string refri, int data, int hora, int preco)
{
    processa(refri);
}