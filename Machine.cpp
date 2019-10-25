#include "Machine.h"
#include "Interface.cpp"

#ifdef PC
#include "InterfacePC.cpp"
#endif

#ifdef ATL
#include "InterfaceAtl.cpp"
#endif

Machine::Machine()
{
    entrada = "nada";
    saida = "d025";
    estado = 0;
    event = 0;
}

int Machine::venda()
{
    int venda = 0;
    string aux;
    int prec;

    Interface *inter;

#ifdef PC
    inter = new InterfacePc;
#endif

#ifdef ATL
    inter = new InterfaceAtl;
#endif

    entrada = inter->get_entrada();

    if (entrada == "report")
    {
        //return 1;
        repo = 1;
        BancoDados::reporta();
    }

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

    if (event == 1)
        inter->processa(saida);

    if (venda)
        BancoDados::registra(saida, 150);

    event = 0;
    entrada = "nada";
    return 0;
}
