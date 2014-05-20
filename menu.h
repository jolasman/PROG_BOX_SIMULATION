#include "Box.h"
#include "Channel.h"
#include "Movie.h"
#include "fstream"

#include <vector>
#include <string>
#include <time.h>

#include <iostream>
using namespace std;

void menu_inicial();
/*apresenta no ecra osub menu com a interacao do utilizador/canais*/
void menu_channels();
/*apresenta no ecra o submenu com a interacao utilizador/programas*/
void menu_programs();
/*apresenta no ecra o submenu com a interacao utilizador/filmes*/
void menu_movies();
/*apresenta no ecra o submenu da saida da aplicacao*/
void menu_exit();

/****************************************ainda por acabar as tres funcoes de verificacao de teclas carregadas******************************/
void pressed_key_channels();

void pressed_key_movies();

void pressed_key_programs();

/*funcao que vai buscar a password do utilizador ao ficheiro password.txt*/
string getPassword();

void menu_box();
