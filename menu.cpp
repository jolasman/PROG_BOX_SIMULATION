#include "menu.h"
#include "Channel.h"
#include "Movie.h"
#include "Program.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


void menu_inicial(){

	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------\n\n";
	cout << "1. Channels" << endl;
	cout << "2. Movies" << endl;
	cout << "3. Programs" << endl;
	cout << "4. Exit\n\n";
	cout << "Choose a number: ";
	
}

void menu_channels(){
	Channel ch;

	system("CLS");
	cout << "--------------------------Welcome to the Channels menu--------------------------\n\n";
	cout << "Please choose one Channel to see the programs:\n\n";
	
	//chamar lista de canais
	ch.open_channels_file();

	cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n\n\n\n";
	// qualquer tecla esta a fazer com que retorne ao menu devido ao break
	system("pause");
}

void menu_programs(){
	Program prog;

	system("CLS");
	cout << "--------------------------Welcome to the Programs menu--------------------------\n\n";
	cout << "Please choose your favorite Program:\n\n";

	//chamar lista de progrmas
	prog.open_programs_file();

	cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n";
	// qualquer tecla esta a fazer com que retorne ao menu devido ao break
	system("pause");

}

void menu_movies(){
	Movie mov;

	system("CLS");
	cout << "--------------------------Welcome to the Movies menu----------------------------\n\n";
	cout << "Please choose your favorite movie:\n\n";

	//chamar lista de filmes
	mov.open_movies_file();

	cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n";
	// qualquer tecla esta a fazer com que retorne ao menu devido ao break
	system("pause");

}

void menu_exit(){
	
	system("CLS");
	cout << " \n\n\n----------------------------Thank You For Watching------------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       program by:";
	cout << "\n                                                                 Joel Carneiro";
	cout << "\n                                                               Filipe Cordeiro\n\n";
	system("pause");

}

void pressed_key_channels(){

	char x;
	
	cin >> x;


	if (x == 'esc')
	{
		menu_inicial();
	}

	if (x != 'esc')
	{
		menu_channels();
	}
	
		
}

void pressed_key_movies(){

	char x;
	x = getchar();


	if (x == 0x27)
	{
		menu_inicial();
	}

	if (x != 0x27)
	{
		menu_movies();
	}


}

void pressed_key_programs(){

	char x;
	x = getchar();


	if (x == 0x27)
	{
		menu_inicial();
	}

	if (x != 0x27)
	{
		menu_programs();
	}


}

void menu_box(){

	int loop = 1;

	int choice;

	//falta fazer a verificação da password

	/*
	*
	[*] aqui está a ser feito o menu da box. tem a opcao de ver os canais, os filmes, os programas e de sair. ainda so esta estruturado. ja entra nas opcoes mas
	[*] ainda nao sai com a tecla esc. sai com qualquer uma.
	[*] tambem ainda não esta a sair bem, ou melhor esta a sair bem do loop mas pede duas vezes para carregar numa tecla para sair.
	*
	*/
	while (loop = 1)
	{

		menu_inicial();

		cin >> choice;


		switch (choice)
		{
		case 1:
			menu_channels();

			pressed_key_channels();

			break;

		case 2:
			menu_movies();

			pressed_key_movies();

			break;
		case 3:
			menu_programs();

			pressed_key_programs();

			break;
		case 4:
			menu_exit();

			loop = 0;

			break;

		default:

			break;
		}

	}
}
