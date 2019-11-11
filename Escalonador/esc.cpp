#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#include "Escalonador.cpp"

void foo()
{
    cout << "     T2  P1";
}

void foo2()
{
    cout << "     T5  P3";
}

void foo3()
{
    cout << "     T10  P2";
}

int main()
{
    Escalonador Escalonador;

    Escalonador.escalona(2, 1, 0, 1, 0, &foo); //periodo, prioridade, pronta, habilitada, bloqueada, funçao
    Escalonador.escalona(5, 3, 0, 1, 0, &foo2);
    Escalonador.escalona(10, 2, 0, 1, 0, &foo3);

    int b = 0;
    while (b < 1000)
    {
        Escalonador.executa();
        b++;
        //usleep(1000000);
        if (b == 100)
            Escalonador.bloqueia(&foo);
    }
}
