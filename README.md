# Implementação em C++ de um escalonador de tarefas, para utilização no controlador de uma máquina de venda de bebidas 

Este código é a implmeentação do controle de uma máquina de venda de refrigerantes (recebe moedas, devolve moedas, fornece produtos, fornece troco, fornece relatórios). 
Também foi implementado um escalonador de tarefas não preemptivo, objetivando a execução do sistema em uma plataforma computacional sem sistema operacional. 

Para mais detalhes acesse o Relatóiro Técnico.pdf

# Manual do usuário

Para compilar o código atual em um sistema Linux com o g++, basta definir PC (\#define PC) e digitar as linhas de comando abaixo: 

g++ -o exe main.cpp -pthread
./exe


caso deseje que o progrma mostre a hora a cada segundo basta definir HR também. 

Com o programa em execução, para usar a máquina de refrigerantes basta inserir moedas seguindo o padrão "m" + valor. Por exemplo, para inserir uma moeda de R\$ 1,00 basta digitar "m100" e pressionar enter. Para moedas abaixo de  R\$ 1,00 deve-se inserir um "0" entre "m" e o valor, como em "m050". Para pedir um refrigerante do tipo MEET basta digitar "meet" e pressionar enter e, similarmente, "etirps" para um refrigerante do tipo Sprite. As devoluções de valores ocorrem no padrão "d" + valor, sendo que para solicitar uma devolução de valores basta digitar "dev". 

Para solicitar o relatório com o período de mais vendas, o refrigerante mais vendido e o valor de vendas, basta digitar "reporta" e pressionar enter. Há, ainda, a função de listar cada uma das vendas já realizadas desde que a máquina iniciou funcionamento, através do comando "reportatudo".


Para usar a classe Escalonador no seu projeto basta criar um objeto tipo Escalonador e e chamar a função escalona() com os atributos período, prioridade (quanto maior o número mais prioritária), flag de pronta, flag de habilitada, flag de bloqueada, e o endereço para a funão a ser escalonada (do tipo void (void)), respectivamente. Em seguida, para que haja execução é necessário chamar a função executa(). Sempre a que esta função for chamada haverá um incremento do tempo mantido pelo escalonador, portanto, se executa() for chamada a cada milissegundo o período das tarefas (passado como argumento da função escalona()) será dado em milissegundos. 

