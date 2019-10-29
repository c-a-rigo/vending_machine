#include "BancoDados.h"

BancoDados::BancoDados()
{
}

void BancoDados::registra(string refri, int preco)
{
    Pilhax.push(refri, preco);
}

void BancoDados::reporta(Machine M)
{

    int n_meet = 0;   //numero de meet vendidos.
    int n_etirps = 0; //numero de etirps vendidos.

    string periodo = "nenhum"; //periodo em que ocorreram mais vendas.

    int manha = 0; //contador de vendas que ocorreram pela manha.
    int tarde = 0; //contador de vendas que ocorreram pela tarde.
    int noite = 0; //contador de vendas que ocorreram pela noite.

    string a; //refrigerante
    int b;    //data da venda
    int c;    //hora da venda
    int d;    //preco

    int valor_total = 0; //valor total de vendas

    while (!Pilhax.pilha_vazia()) //enquanto a pilha não estiver vazia
    {
        //retira dados da Pilha e salva na Lista.
        Pilhax.pop(a, b, c, d);
        Listax.push(a, b, c, d);

        //analisa qual refrigerante foi vendido e incrementa seu contador
        if (a == "meet")
            n_meet++;
        else if (a == "etirps")
            n_etirps++;

        //verifica em qual periodo ocorreu a venda e incrementa seu contador
        if ((c >= 0) && (c < 1200))
            manha++;

        else if ((c >= 1200) && (c < 1900))
            tarde++;

        else if ((c >= 1900) && (c < 2359))
            noite++;

        //soma valor da venda ao valor total
        valor_total += d;

        //cout << n_meet << n_etirps << c << manha << tarde << noite << endl;
    }

    //analisa os contadores de periodo de vendas e define o maior
    if ((manha >= tarde) && (tarde >= noite))
        periodo = "manha";
    else if ((tarde >= noite) && (noite >= manha))
        periodo = "tarde";
    else if ((noite >= manha) && (manha >= tarde))
        periodo = "noite";

    //analisa os contadores de refrigerante mais vendido e chama a interface para reportar
    if (n_etirps > n_meet)
        M.inter->report_final("etirps", n_etirps, periodo, valor_total / 100);
    else
        M.inter->report_final("meet", n_meet, periodo, valor_total / 100);
}

void BancoDados::read_all_list(Machine M)
{
    /*  Funçao para ler toda a Lista (historico) de vendas.  */

    string a; //O refrigerante vendido.
    int b;    //A data da venda.
    int c;    //A hora da venda.
    int d;    //O preco do refrigerante.
    Nodo *n;  //ponteiro para nodo na Lista

    n = Listax.get_mid(); //ponteiro recebe endereco de mid (ponteiro auxiliar para varrer a lista)

    while (n != 0)
    {
        Listax.ler(a, b, c, d, n);   //le os valores do nodo n.
        M.inter->report(a, b, c, d); //reporta os valores obtidos.
        n = Listax.get_mid_next();   //obtem o endereco do proximo nodo.
        Listax.set_mid(n);           //faz mid apontar para o proximo nodo
    }
}