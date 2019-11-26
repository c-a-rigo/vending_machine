#define PC
#define HR

#include "Escalonador/Escalonador.cpp"
#include "functions.cpp"

int main()
{
    Escalonador Escalonador;

    Escalonador.escalona(300, 1, 0, 1, 0, &vender);
    Escalonador.escalona(300, 2, 0, 1, 0, &reportar);
    Escalonador.escalona(1000, 3, 0, 1, 0, &atualiza_tempo);
    //                              ^
    //                              |
    //  periodo, prioridade, pronta, habilitada, bloqueada, &funçao

    while (true)
    {
        Escalonador.executa();
        usleep(1000); //1ms
    }
}

//g++ -o exe main.cpp -pthread
