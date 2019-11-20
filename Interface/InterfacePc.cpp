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
        cout << "**MEET**" << endl;
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
        cout << "**ETIRPS**" << endl;
    }

    else
        cout << saida << endl;
}

void InterfacePc::report(string x, int y, int z, int f)
{
    /*  Funçao para mostrar os valores de uma venda. 

    Argumentos:
    x: O refrigerante vendido.
    y: A data da venda.
    z: A hora da venda.
    f: O preco do refrigerante.
    
   */

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << f << endl;
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

    cout << "O refrigerante mais vendido foi o " << x << ", com " << y << " unidades vendidas." << endl;
    cout << "O periodo do dia com mais vendas foi: " << f << "." << endl;
    cout << "Valor total de vendas: " << z << " reais." << endl;
}