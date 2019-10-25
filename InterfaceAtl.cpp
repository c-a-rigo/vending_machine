#include <iostream>
#include <string>
#include <stdlib.h>

#include "InterfaceAtl.h"
#include "Oled.cpp"

InterfaceAtl::InterfaceAtl()
{
    data_atl = (volatile unsigned int *)0x80000a00;
    output_atl = (volatile unsigned int *)0x80000a04;
    direction_atl = (volatile unsigned int *)0x80000a08;

    *direction_atl = 0xffffffff;
}

string InterfaceAtl::get_entrada()
{
    int i;

    *output_atl = 0x00000000;

    while (*data_atl == 0)
        ;

    if (*data_atl == 65536)
        entrada1 = "report";

    if (*data_atl == 524288)
        entrada1 = "m050";

    if (*data_atl == 262144)
        entrada1 = "m100";

    if (*data_atl == 131072)
        entrada1 = "dev";

    if (*data_atl == 4096)
        entrada1 = "meet";

    if (*data_atl == 1048576)
        entrada1 = "etirps";

    cout << entrada1;

    for (i = 0; i < 600000; i++)
        ;

    return entrada1;
}

void InterfaceAtl::processa(string saida)
{
    int i;

    *direction_atl = 0xffffffff;
    cout << saida;

    if (saida == "meet")
    {
        *output_atl = 0x00000010;
    }

    else if (saida == "etirps")
    {
        *output_atl = 0x00000008;
    }

    else if (saida == "d025")
    {
        *output_atl = 0x00000001;
    }

    else if (saida == "d050")
    {
        *output_atl = 0x00000002;
    }

    else if (saida == "d075")
    {
        *output_atl = 0x00000003;
    }

    else if (saida == "d100")
    {
        *output_atl = 0x00000004;
    }

    for (i = 0; i < 1000000; i++)
        ;
}

void InterfaceAtl::report(string refri, int data, int hora, int preco)
{

    char cstr[refri.size() + 1];
    refri.copy(cstr, refri.size() + 1);
    cstr[refri.size()] = '\0';

    oledInit();
    printString(cstr);
    delay(500);
}