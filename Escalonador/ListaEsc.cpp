#include "ListaEsc.h"

ListaEsc::ListaEsc()
{
    top = 0;
    n = 0;
}

ListaEsc::~ListaEsc()
{
    while (top) //enquanto houver nodos na lista
    {
        auxiliar = top->get_next();
        delete top;
        top = auxiliar;
    }
    top = 0;
    auxiliar = 0;
    mid = 0;
}

void ListaEsc::push(int p, int a, int r, int h, int b, void (*task)(void))
{
    /*  Funçao para inserir um novo nodo na lista. 

    Argumentos:
    p: período da tarefa.
    a: prioridade da tarefa.
    r: flag para tarefa pronta.
    h: flag para tarefa habilitada.
    b: flag para tarefa bloqueada.
    ponteiro para a função.
    nxt: ponteiro para o próximo nodo.
    
   */

    auxiliar = new NodoEsc(p, a, r, h, b, task, top);
    top = auxiliar;
    mid = top;
}

NodoEsc *ListaEsc::get_mid()
{
    return mid;
}

NodoEsc *ListaEsc::get_mid_next()
{
    return mid->get_next();
}

void ListaEsc::set_mid(NodoEsc *nxt)
{
    mid = nxt;
}

void ListaEsc::ler(int &p, int &a, int &r, int &h, int &b, void (*task)(void), NodoEsc *nxt)
{
    if (nxt)
    {
        cout << nxt->get_periodo() << endl;
        cout << nxt->get_prioridade() << endl;
        cout << nxt->get_pronta() << endl;
        cout << nxt->get_habilita() << endl;
        cout << nxt->get_bloqueada() << endl;
        cout << nxt->get_void() << endl;
        cout << nxt->get_next() << endl;
    }
}

void ListaEsc::decide(unsigned long int tempo)
{
    void (*ttt)(void);
    int exec = 0;
    int ptr = 0;

    //periodo, prioridade, pronta, habilitada, bloqueada, funçao

    if (top) //se existe nó na lista
    {

        //varre a fila para por na fila das prontas

        mid = top; //meio aponta para o topo da lista

        while (mid != 0) //enquanto meio não chega no fim da lista
        {
            if (mid->get_habilita() && !mid->get_bloqueada()) // se a tarefa esta habilitada
            {
                if ((tempo - mid->get_count()) == mid->get_periodo()) // se seu periodo já passou
                {
                    mid->set_count(tempo); // momento de execução = momento atual

                    ptr = mid->get_pronta(); // pega o valor de quantas vezes a tarefa ficou pronta para executar

                    ptr++; //incrementa esse valor

                    mid->set_pronta(ptr); // poe na fila das prontas

                    ptr = 0; // zera variavel auxiliar

                    if (mid->get_prioridade() > n) // se a prioridade dessa tarefa for maior que a prioridade teto
                    {
                        n = mid->get_prioridade(); // seta para ser a prioridade teto
                    }
                }
            }

            mid = mid->get_next(); // meio aponta para o proximo nodo
        }

        //varre a fila novamente para executar a de maior prioridade na fila das prontas

        while (exec == 0) // enquanto não executar algo varre a fila e diminui a prioridade teto
        {
            mid = top; //meio aponta para o topo da lista

            while (mid != 0) //enquanto meio não chega no fim da lista
            {
                if (mid->get_pronta() > 0) // entra as prontas
                {
                    if (mid->get_prioridade() == n && !mid->get_bloqueada()) // acha a que tem prioridade igual a prioridade mais alta entre as prontas
                    {
                        ptr = mid->get_pronta(); //pega o valor de pronta
                        ptr = ptr - 1;           // diminui
                        mid->set_pronta(ptr);    // seta
                        ptr = 0;                 //zera variavel auxiliar

                        ttt = mid->get_void(); // pega endereço da função
                        ttt();                 // executa
                        exec = 1;              //houve uma execução
                    }
                }

                mid = mid->get_next(); // meio aponta para o proximo nodo
            }

            n = n - 1; // diminui a lista da maior prioridade

            if (n < 0) // caso a prioridade teto desceu a zero e nada foi executado
            {
                mid = top; //meio aponta para o topo da lista

                while (mid != 0) //enquanto meio não chega no fim da lista
                {
                    if (mid->get_pronta() > 0 && !mid->get_bloqueada()) // entra as prontas
                    {

                        ptr = mid->get_pronta(); //pega o valor de pronta
                        ptr = ptr - 1;           // diminui
                        mid->set_pronta(ptr);    // seta
                        ptr = 0;                 //zera variavel auxiliar

                        ttt = mid->get_void(); // pega endereço da função
                        ttt();                 // executa
                        exec = 1;              //houve uma execução
                    }

                    mid = mid->get_next(); // meio aponta para o proximo nodo
                }
                exec = 1;
            }
        }
    }
}

void ListaEsc::bloqueia(void (*task)(void))
{
    mid = top; //meio aponta para o topo da lista

    while (mid != 0) //enquanto meio não chega no fim da lista
    {
        if (mid->get_void() == task) // encontra a tarefa a bloquear
        {
            mid->set_bloqueada(1);
        }
        mid = mid->get_next(); // meio aponta para o proximo nodo
    }
}