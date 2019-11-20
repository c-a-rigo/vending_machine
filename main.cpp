
#define PC
//#define HR

#include "Escalonador/Escalonador.cpp"
#include "functions.cpp"

//g++ -o exe main.cpp -pthread

int main()
{

    Escalonador Escalonador;

    Escalonador.escalona(3, 1, 0, 1, 0, &sell);  //periodo, prioridade, pronta, habilitada, bloqueada, funçao
    Escalonador.escalona(5, 2, 0, 1, 0, &repor); //periodo, prioridade, pronta, habilitada, bloqueada, funçao
    Escalonador.escalona(50, 3, 0, 1, 0, &atualiza_tempo);

    while (true)
    {
        Escalonador.executa();
        usleep(1000); //1ms
    }
}
