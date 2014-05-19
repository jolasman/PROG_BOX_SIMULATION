#ifndef _MENU
#define _MENU

#include<iostream>

using namespace std;

int rand_int(int a, int b);
/*gera um numero aleatorio entre a e b*/
void menu_inicial(); 
/*apresenta no ecra o menu de opções entre os outros menus*/
void menu_box();
/*onde é gerado o codigo para interagir com o utilizador para a escolha do que pretende no menu inicial*/
void menu_channels();
/*apresenta no ecra o menu com os canais*/
void menu_programs();
/*apresenta no ecra o menu com os programas*/
void menu_movies();
/*apresenta no ecra o menu com os filmes */
void menu_exit();
/*apresenta no ecra o menu de saida*/

/*estas tres funções eram uma tentaiva para ser reconhecida a tecla que estava a ser carregada em cada menu*/
void pressed_key_channels();

void pressed_key_movies();

void pressed_key_programs();

/*vai buscar a passoword ao ficheiro password.txt*/
string getPassword();



#endif
