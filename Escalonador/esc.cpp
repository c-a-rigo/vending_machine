#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#include "Escalonador.cpp"

void foo()
{
    cout << "     T2  P2";
}

void foo2()
{
    cout << "     T5  P4";
}

void foo3()
{
    cout << "     T10  P3";
}

void foo4()
{
    cout << "     T1  P1";
}

int main()
{
    Escalonador Escalonador;

    Escalonador.escalona(1, 1, 0, 1, 0, &foo4);
    Escalonador.escalona(2, 2, 0, 1, 0, &foo); //periodo, prioridade, pronta, habilitada, bloqueada, funçao
    Escalonador.escalona(5, 4, 0, 1, 0, &foo2);
    Escalonador.escalona(10, 3, 0, 1, 0, &foo3);

    int b = 0;

    while (b < 500)
    {
        Escalonador.executa();
        b++;

        if (b == 100)
            Escalonador.bloqueia(&foo4);

        usleep(1000); //1ms
    }
}
