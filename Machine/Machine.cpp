#include "Machine.h"
#include "../common.h"

Machine::Machine() //inicializa a maquina
{
    entrada = "nada";
    saida = "d025";
    estado = 0;
    event = 0;

#ifdef PC
    inter = new InterfacePc;
#endif

#ifdef ATL
    inter = new InterfaceAtl;
#endif

    inter->abertura();
}

int Machine::venda(string &r, int &p, int &repo, int &venda)
{
    /*  Funçao para inserir valores em um novo nodo da lista. 

    Argumentos:
    r: O refrigerante vendido.
    p: O preco do refrigerante.
    repo: Caso a entrada seja report seta repo para '1'.
    venda: Caso ocorra uma venda seta venda para '1'.
    
   */
    cout << "Sua entrada: ";
    entrada = inter->get_entrada(); //chama objeto interface para obter entrada

    if (entrada == "reporta")
        repo = 1;

    if (entrada == "reportatudo")
        repo1 = 1;

    switch (estado)
    {
    case 0:
        if (entrada == "m025")
            estado = 25;

        else if (entrada == "m050")
            estado = 50;

        else if (entrada == "m100")
            estado = 100;

        entrada = "nada";
        break;

    case 25:
        if (entrada == "m025")
            estado = 50;

        else if (entrada == "m050")
            estado = 75;

        else if (entrada == "m100")
            estado = 125;

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d025";
            event = 1;
        }
        entrada = "nada";
        break;

    case 50:
        if (entrada == "m025")
            estado = 75;

        else if (entrada == "m050")
            estado = 100;

        else if (entrada == "m100")
            estado = 150;

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d050";
            event = 1;
        }
        entrada = "nada";
        break;

    case 75:
        if (entrada == "m025")
            estado = 100;

        else if (entrada == "m050")
            estado = 125;

        else if (entrada == "m100")
        {
            estado = 150;
            saida = "d025";
            event = 1;
        }

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d075";
            event = 1;
        }
        entrada = "nada";
        break;

    case 100:
        if (entrada == "m025")
            estado = 125;

        else if (entrada == "m050")
            estado = 150;

        else if (entrada == "m100")
        {
            estado = 150;
            saida = "d050";
            event = 1;
        }

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d100";
            event = 1;
        }
        entrada = "nada";
        break;

    case 125:
        if (entrada == "m025")
            estado = 150;

        else if (entrada == "m050")
        {
            estado = 150;
            saida = "d025";
            event = 1;
        }

        else if (entrada == "m100")
        {
            estado = 150;
            saida = "d075";
            event = 1;
        }

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d125";
            event = 1;
        }
        entrada = "nada";
        break;

    case 150:
        if (entrada == "m025")
        {
            saida = "d025";
            event = 1;
        }

        else if (entrada == "m050")
        {
            saida = "d050";
            event = 1;
        }

        else if (entrada == "m100")
        {
            saida = "d100";
            event = 1;
        }

        else if (entrada == "dev")
        {
            estado = 0;
            saida = "d150";
            event = 1;
        }
        else if (entrada == "meet")
        {
            estado = 0;
            saida = "meet";
            event = 1;
            venda = 1;
        }
        else if (entrada == "etirps")
        {
            estado = 0;
            saida = "etirps";
            event = 1;
            venda = 1;
        }
        entrada = "nada";
        break;

    default:
        break;
    }

    if (event == 1)             //se houver uma saida
        inter->processa(saida); //chama interface e mostra a saida

    if (venda) //se houver uma venda
    {
        //repassa dados da venda
        r = saida; //refrigerante
        p = 150;   //preco
    }

    event = 0;
    entrada = "nada";
    return 0;
}

void Machine::teste2()
{
    cout << "funcionou" << endl;
}
