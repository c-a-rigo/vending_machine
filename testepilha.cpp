#include <iostream>
#include <string>
#include <stdlib.h>

#include "Pilha.cpp"

int main()
{
    string refri;
    int data;
    int hora;
    int preco;

    Pilha vendas;

    vendas.push("meet", 12121999, 1900, 150);

    vendas.push("stirps", 12122000, 2900, 170);
    vendas.push("cezar", 12122000, 2900, 170);

    vendas.pop(refri, data, hora, preco);

    cout << refri << endl;
    cout << data << endl;
    cout << hora << endl;
    cout << preco << endl;
    cout << "\n";
    vendas.pop(refri, data, hora, preco);

    cout << refri << endl;
    cout << data << endl;
    cout << hora << endl;
    cout << preco << endl;
    cout << "\n";
    vendas.pop(refri, data, hora, preco);

    cout << refri << endl;
    cout << data << endl;
    cout << hora << endl;
    cout << preco << endl;
}
