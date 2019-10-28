#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "Oled.cpp"
#include "InterfaceAtl.h"

InterfaceAtl::InterfaceAtl()
{
    data_atl = (volatile unsigned int *)0x80000a00;
    output_atl = (volatile unsigned int *)0x80000a04;
    direction_atl = (volatile unsigned int *)0x80000a08;

    *direction_atl = 0xffffffff;

    oledInit();
    oledClear();
}

string InterfaceAtl::get_entrada()
{

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
    cout << "entrada1";

    delay(500000);

    return entrada1;
}

void InterfaceAtl::processa(string saida)
{
    cout << saida;
    oledClear();
    setLine(0);
    printString(saida);
    delay(1000000);
    oledClear();
}

void InterfaceAtl::report(string refri, int data, int hora, int preco)
{

    printString(refri);
}
