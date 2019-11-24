#include <iostream>
#include <string>
#include <stdlib.h>

#include "InterfacePc.h"

string InterfacePc::get_entrada()
{
    cin >> entrada1;
    // cout << entrada1 << endl;

    return entrada1;
}

void InterfacePc::processa(string saida)
{
    if (saida == "meet")
    {

        cout << "******************************* TEEM ***********************************" << endl;
        /*
        cout << R"(                 `-+osyhdmmmmddhyso/.                  
               :yNNdys+//:::::/oyhhdmds.               
              oMy/``:/+o++oossdd++yy-omN:              
             `mh`  sy-.`/d+:/+smysso  -Ny              
            -d:+hs/:ss+++sdo-.````.-+yy:oh`            
            ss  `./oyhhhyssooossyyso:.   m:            
            ym+.     ```.......```     -sN/            
            yo:os+:-`            `.-/oso-d/            
            yo  `.:+osoooo++ooyysms/:.`  d/            
            yo        ```````-m-oy       d/            
            yo               +h m:       d/            
            yo               -m`m-       d/            
            yo                yoyo       d/            
            yo                `dom`      d/            
            yo                 -mhs      d/            
            yo                  +dd/     d/            
            yo                   dod-    d/            
            yo                   :d:d`   d/            
            yo                    m-sy   d/            
            yo                    h/.N.  d/            
            yo                    y+ d:  d/            
            yo                    d/ m:  d/            
            yo                   -m`-N`  d/            
            ss                  `h+ ho  `m:            
            `ys.               .h+ sy``:yo             
              oNhs/-`        `oh:`yd+sdN:              
               :shyysssssssssmdsssyyhyo.               
                  -/ossssssssssssso/.                  
)"
             << '\n'; */
    }

    else if (saida == "etirps")
    {
        /*  cout << R"(                                                       
                                                       
                                                       
                   `.-:::::--::::--``                  
             `-////:-.``..----..``.-:///:.             
            :s-``---::-:--:-::/::::::-.`./s`           
            .h/+/.` :/:--+-.-:::    ``://:y`           
            -o.:++//+sssso+/:..``.-:://++-+`           
           :o`    ``..-:::://:/::--.```   `/-          
          +/                               `/.         
         /+                                 `o         
         y.                                  s         
         y`                                  s         
         h                                   s         
         h                                   s         
         d                                   y         
         d                                   y         
         h                                   y         
         h`                                  y         
         y.                                  y         
         y.                                  y         
         y.                                  y         
         y.                                  y         
         y-                                  y         
         y-                                  y         
         y.                                 `y         
         h`                                 `y         
         h`                                  h         
         y`                                  h         
         o:                                 -s         
         .y-                               -s`         
          `++/-```                   ``.:++/`          
             .yy+///++////:///////+////ss.             
               -///-.`````...`````.-://-               
                   .-::::::::::::--.                   
                                                       
                                                       
)"
             << '\n'; */
        cout << "****************************** SPRITE **********************************" << endl;
    }

    else
        cout << "Devolução: " << saida << endl;
}

void InterfacePc::report(string x, int c, int z, int f)
{
    /*  Funçao para mostrar os valores de uma venda. 

    Argumentos:
    x: O refrigerante vendido.
    c: A data da venda.
    z: A hora da venda.
    f: O preco do refrigerante.
    
   */

    int m, d, y;
    int hr, mi;

    string proc_hora = "", proc_data = "";

    //decifra a data
    y = c % 10000;
    c = c / 10000;
    m = c % 100;
    c = c / 100;
    d = c % 100;

    //decifra a hora
    mi = z % 100;
    z = z / 100;
    hr = z % 100;

    std::string s_mes = std::to_string(m);
    std::string s_dia = std::to_string(d);
    std::string s_ano = std::to_string(y);
    std::string s_hora = std::to_string(hr);
    std::string s_min = std::to_string(mi);

    proc_data = s_dia + "/" + s_mes + "/" + s_ano;

    if (d < 10)
        proc_data = "0" + s_dia + "/" + s_mes + "/" + s_ano;
    if (m < 10)
        proc_data = s_dia + "/" + "0" + s_mes + "/" + s_ano;
    if (d < 10 && m < 10)
        proc_data = "0" + s_dia + "/" + "0" + s_mes + "/" + s_ano;

    proc_hora = s_hora + ":" + s_min;
    if (mi < 10)
        proc_hora = s_hora + ":" + "0" + s_min;

    cout << "\n";
    if (x == "etirps")
        cout << "Um refrigerante Sprite foi vendido dia " << proc_data << " as " << proc_hora << "h por R$: 1.50" << endl;
    if (x == "meet")
        cout << "Um refrigerante Teem foi vendido dia " << proc_data << " as " << proc_hora << "h por R$: 1.50" << endl;
    cout << "\n";
}

void InterfacePc::report_final(string x, int y, string f, int z)
{
    /*  Funçao para mostrar o report de vendas. 

    Argumentos:
    x: O refrigerante mais vendido.
    y: A quantidade de unidades vendidas.
    f: Periodo com mais vendas.
    z: Valor total de vendas.

   */
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                        RELATORIO DE VENDAS                             " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "O refrigerante mais vendido foi o " << x << ", com " << y << " unidades vendidas." << endl;
    cout << "O periodo do dia com mais vendas foi: " << f << "." << endl;
    cout << "Valor total de vendas: " << z << " reais." << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl;
}

void InterfacePc::abertura()
{
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "            MAQUINA DE VENDA DE REFRIGERANTES ESCALONADA                " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Digite =>  'm100' para inserir R$ 1,00. " << endl;
    cout << "Digite =>  'm050' para inserir R$ 0,50. " << endl;
    cout << "Digite =>  'm025' para inserir R$ 0,25. " << endl;
    cout << "Digite =>  'dev' devolucao do seu dinheiro." << endl;
    cout << "Digite =>  'meet' para o refrigerante Teem (R$ 1,50)." << endl;
    cout << "Digite =>  'etirps' para o refrigerante Sprite (R$ 1,50)." << endl;
    cout << "Digite =>  'reporta' para o relatorio geral de vendas." << endl;
    cout << "Digite =>  'reportatudo' para lista de todas vendas já feitas." << endl;
    cout << endl;
}