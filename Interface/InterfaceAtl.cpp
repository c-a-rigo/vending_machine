#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "Oled.cpp"
#include "InterfaceAtl.h"
using namespace std;

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

    *direction_atl = 0xffffffff;

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
    /*
    
    Funçao para mostrar uma saida da maquina. 

          Display 16x4
        1234567890123456  

    1   +Vendido: etirps
    2   Quantidade: 12
    3   Periodo: manha
    4   Valor total: 18  

    */

    cout << saida;
    oledClear();
    setLine(2);
    printString(saida);
    delay(1000000);
    oledClear();
}

void InterfaceAtl::report(string refri, int data, int hora, int preco)
{
}

void InterfaceAtl::report_final(string x, int y, string f, int z)
{
    /*
    
    Funçao para mostrar o report final de vendas. 

    Argumentos:
    x: O refrigerante mais vendido.
    y: A quantidade de unidades vendidas.
    f: Periodo com mais vendas.
    z: Valor total de vendas.

          Display 16x4
        1234567890123456  

    1   +Vendido: etirps
    2   Quantidade: 12
    3   Periodo: manha
    4   Valor total: 18  

    */
    string aux;

    oledClear();

    setLine(0);
    printString("+Vendido: ");
    printString(x);

    setLine(1);
    printString("Quantidade: ");

    /*  stringstream ss;
    ss << y;
    aux = ss.str(); */

    printString(aux);

    setLine(2);
    printString("Periodo: ");
    printString(f);

    setLine(3);
    printString("Valor total: ");
    /* 
    stringstream ss;
    ss << z;
    aux = ss.str(); */

    printString(aux);
}

void InterfaceAtl::abertura()
{
}