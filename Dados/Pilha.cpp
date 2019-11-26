#include "Pilha.h"
#include "../common.h"

#include <exception>
using std::bad_alloc;

Pilha::Pilha() //controi a Pilha.
{
    topo = 0; //inicia com zero nodos.
}

Pilha::~Pilha() //destroi a Pilha.
{
    while (topo) //enquanto houver um nodo.
    {
        aux = topo->get_next(); //salva o endereço para o proximo nodo.
        delete topo;            //deleta o nodo atual.
        topo = aux;             //atual = proximo.
    }

    //zera todos os ponteiros.
    topo = 0;
    aux = 0;
}

void Pilha::push(string refri, int preco)
{
    /*  Funçao para inserir valores em um novo nodo da Pilha. 

    Argumentos:
    refri: O refrigerante vendido.
    g_data: A data da venda.
    g_hora: A hora da venda.
    precp: O preco do refrigerante.
    
   */
    try
    {
        aux = new Nodo(refri, g_data, g_hora, preco, topo); //aux recebe o endereco do novo nodo criado com o comando new.
        topo = aux;                                         //topo passa a apontar para o novo nodo.
    }
    catch (bad_alloc E)
    {
        cout << "Faltou Memoria...\n"
             << endl;
    }
}

void Pilha::pop(string &r, int &t, int &o, int &k)
{
    /*  Funçao para ler os valores no nodo do topo da pilha.

    Argumentos:
    r: O refrigerante vendido.
    t: A data da venda.
    o: A hora da venda.
    k: O preco do refrigerante.

   */

    aux = topo;

    if (aux) //se houver um nodo.
    {
        topo = aux->get_next(); //faz topo apontar para o proximo nodo na pilha.

        //pega toos valores no nodo.
        r = aux->get_refri();
        t = aux->get_data();
        o = aux->get_hora();
        k = aux->get_preco();

        delete (aux); //deleta o nodo.
    }
}

int Pilha::pilha_vazia()
{
    /* Função para verificar se a pilha esta vazia. */

    if (topo)
        return 0;
    else
        return 1;
}