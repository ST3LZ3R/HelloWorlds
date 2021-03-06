#include <ncurses.h> //Incluiremos a biblioteca ao nosso sistema
#include <stdio.h>
#include <stdlib.h>

void sair (void);  //Esta função fará com que o programa seja fechado

int main(void)
{
    initscr();   /*Esta função  inicializa a ncurses. Para todos os programas  
                   devemos sempre inicializar a ncurses e depois finalizar, como
                  veremos adiante. */

    start_color(); //Esta função torna possível o uso das cores

//Abaixo estamos definindo os pares de cores que serão utilizados no programa
    init_pair(1,COLOR_WHITE,COLOR_BLUE); //Texto(Branco) | Fundo(Azul)
    init_pair(2,COLOR_BLUE,COLOR_WHITE); //Texto(Azul) | Fundo(Branco)
    init_pair(3,COLOR_RED,COLOR_WHITE);  //Texto(Vermelho) | Fundo(Branco)

    bkgd(COLOR_PAIR(1));  /*Aqui nós definiremos que a cor de fundo do nosso
                                      programa será azul e a cor dos textos será branca.*/

    attron(COLOR_PAIR(3)); /*Estamos alterando o par de cores para 3 em vez
                                          de utilizar o par de cor por omissão(1).*/

    move(2,1);  //Aqui estamos movendo o cursor para a linha 2 coluna 1.
    printw("Olá mundo!!!");  //Imprimimos um texto na tela na posição acima.
    attroff(COLOR_PAIR(3));  /*Estamos alterando o par com a cor por omissão,
                             ou seja, retornando para o par de cor 1. */
    attron(COLOR_PAIR(2));  
    move(3,1);
    printw("Qualquer tecla para sair."); /*Imprimimos um texto na tela na
                                                        posição acima. */
    attroff(COLOR_PAIR(2));
    refresh();    //Atualiza a tela
    getch();      //Fica esperando que o usuário aperte alguma tecla

    sair();    // Sai do programa
}

void sair()
{
    endwin(); /*Sempre que finalizarmos um programa com a biblioteca curses,
                     devemos executar este comando.*/
    exit(0);  
} 
