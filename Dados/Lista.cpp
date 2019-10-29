#include "Lista.h"

Lista::Lista() //constroi
{
    top = 0; //inicia sem nodos
}

Lista::~Lista() //destroi
{
    while (top) //enquanto houverem nodos na lista
    {
        auxiliar = top->get_next(); //salva o endereço do próximo nodo
        delete top;                 //deleta o nodo atual
        top = auxiliar;             //atual = proximo
    }

    //zera todos os ponteiros
    top = 0;
    auxiliar = 0;
    mid = 0;
}

void Lista::push(string &r, int &t, int &o, int &k)
{
    /*  Funçao para inserir valores em um novo nodo da lista. 

    Argumentos:
    r: O refrigerante vendido.
    t: A data da venda.
    o: A hora da venda.
    k: O preco do refrigerante.
    
   */

    auxiliar = new Nodo(r, t, o, k, top); //auxiliar recebe endereço do proximo nodo criado com o comando new.
    top = auxiliar;                       //topo aponta para o mais novo nodo.
    mid = top;                            //mid aponta para o mais novo nodo.
}

Nodo *Lista::get_mid()
{
    return mid; //retorna valor do ponteiro mid.
}

Nodo *Lista::get_mid_next()
{
    return mid->get_next(); //retorna endereco do proximo nodo para o qual o mid aponta
}

void Lista::set_mid(Nodo *nxt)
{
    mid = nxt; //seta um valoar para o ponteiro mid.
}

void Lista::ler(string &r, int &t, int &o, int &k, Nodo *n)
{
    /*  Funçao para listar os valores salvos no nó n da lista. 

    Argumentos:
    r: O refrigerante vendido.
    t: A data da venda.
    o: A hora da venda.
    k: O preco do refrigerante.
    n: Ponteiro para um nodo.

   */

    if (n)
    {
        r = n->get_refri();
        t = n->get_data();
        o = n->get_hora();
        k = n->get_preco();
        n = n->get_next();
    }
}