#include <iostream>
using namespace std;
#include <cstdlib>
#include "fstream"
#include <time.h>
#include <vector>
#include "Channel.h"
#include "Date.h"
#include "Box.h"
#include "menu.h"

// Randomly generates a valid day, hour and minute
Date currentDate(){
	
	srand((unsigned)time(NULL));
	//vector<string> vdays = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" };
	string vdays[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" }; //alterei de vector para array
	//int aleat = rand() % 7 + 1;
	int aleat = rand() % 7; //indice do array: numero aleatorio de 0-6
	string day1;
	//for (int j = 0; j < aleat; j++)
	//	day1 = vdays[j];
	day1 = vdays[aleat];
	//unsigned int hour1 = rand() % 24 + 1;
	unsigned int hour1 = rand() % 24; //numero aleatorio de 0-23
	//unsigned int minutes = rand() % 60 + 1;
	unsigned int minutes = rand() % 60;  //numero aleatorio de 0-59
	Date dat = {day1, hour1, minutes};
	return dat;
}

//CHANNEL ~69 
//MOVIES ~51
//PROGRAMS ~60

Box box = Box(getPassword(), currentDate());

/*apresenta no ecra o menu de opções entre os outros submenus para a possivel navegacao do utilizador*/
void menu_inicial(){

	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------\n\n";
	cout << "1. Channels" << endl;
	cout << "2. Movies" << endl;
	cout << "3. Programs" << endl;
	cout << "4. Exit\n\n";
	cout << "Choose a number: ";

}
/*apresenta no ecra osub menu com a interacao do utilizador/canais*/
void menu_channels(){
	system("CLS");
	cout << "--------------------------Welcome to the Channels menu--------------------------\n\n";
	int number;
	cout << "1. See all Channels" << endl;
	cout << "2. Name change" << endl;
	cout << "3. Add Channels" << endl;
	cout << "4. Remove Channels" << endl;
	cout << "5. Add programs" << endl;
	cout << "6. Return to main menu\n\n";
	cout << "Choose a number: ";
	cin >> number;
	
	if (number == 1)
	{
		system("cls");
		cout << "The Channels list:\n\n";
		//chamar lista de canais
		box.readChannelsVector();
		system("pause");
	}
		
	if (number == 2)
	{
		//chama a funcao que muda o nome do canal
		box.submenuNameChannels();
		system("pause");
	}

	if (number == 3)
	{
		//chama a funcao que adiciona um canal novo
		box.submenuNewChannel();
		system("pause");
	}

	if (number == 4)
	{
		//chama a funcao que remove um novo canal
		box.submenuRemoveChannel();
		system("pause");
	}

	/************************************************************falta fazer a funcao de adicionar um programa ao canal no box.cpp**************************/
	if (number == 5)
	{
		box.submenuAddProgramChannel();
	}

	if (number == 6)
	{
		system("cls");
		menu_inicial();
	}
}

/*apresenta no ecra o submenu com a interacao utilizador/programas*/
void menu_programs(){
	system("CLS");
	cout << "--------------------------Welcome to the Programs menu--------------------------\n\n";
	int number;
	cout << "1. See all Programs" << endl;
	cout << "2. Create a new Program" << endl;
	cout << "3. Name change" << endl;
	cout << "4. Type change" << endl;
	cout << "5. Date change" << endl;
	cout << "6. Duration change" << endl;
	cout << "7. Remove Program" << endl;
	cout << "8. Return to main menu\n\n";
	cout << "Choose a number: ";
	cin >> number;

	if (number == 1)
	{
		system("cls");
		cout << "The Programs list:\n\n";
		//chamar lista de progrmas
		box.readProgramsVector();
	}
	
	if (number == 2)
	{
		box.submenuAddProgramChannel();
	}

	if (number == 3)
	{
		box.submenuNamePrograms();
	}
	
	if (number == 4)
	{
		box.submenuChangeTypePrograms();
	}

	if (number == 5)
	{
		box.submenuChangeDatePrograms();
	}
	
	if (number == 6)
	{
		box.submenuChangeDurationPrograms();
	}

	if (number == 7)//remove
	{
		box.submenuRemovePrograms();
	}

	if (number == 8)// exit
	{
		system("cls");
		menu_inicial();
		system("pause");
	}
}

/*apresenta no ecra o submenu com a interacao utilizador/filmes*/
void menu_movies(){
	system("CLS");
	cout << "--------------------------Welcome to the Movies menu----------------------------\n\n";

	int number;
	cout << "1. See Movieclub" << endl;
	cout << "2. Title change" << endl;
	cout << "3. Cost change" << endl;
	cout << "4. Remove Movie" << endl;
	cout << "5. Return to main menu\n\n";
	cout << "Choose a number: ";
	cin >> number;

	if (number == 1)
	{
		system("cls");
		cout << "The movies list:\n\n";
		//chamar lista de filmes
		box.readMoviesVector();
		system("pause");
	}

	if (number == 2)
	{
		box.submenuNameMovies();
		system("pause");
	}
	
	if (number == 3)
	{
		box.submenuChangeCostMovies();
		system("pause");
	}
	
	if (number == 4)
	{
		box.submenuRemoveMovies();
		system("pause");
	}
}

/*apresenta no ecra o submenu da saida da aplicacao*/
void menu_exit(){

	system("CLS");
	cout << " \n\n\n----------------------------Thank You For Watching------------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       program by:";
	cout << "\n                                                                 Joel Carneiro";
	cout << "\n                                                               Filipe Cordeiro\n\n";
	system("pause");

}

/****************************************ainda por acabar as tres funcoes de verificacao de teclas carregadas******************************/
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

/*****************************************************************************************************************************************/

/*funcao que vai buscar a password do utilizador ao ficheiro password.txt*/
string getPassword()
{
	ifstream password;
	string pass;

	password.open("PASSWORD.txt");
	getline(password, pass);
	password.close();
	return pass;
}

/*onde é gerado o codigo para interagir com o utilizador para a escolha do que pretende no menu inicial*/
void menu_box(){

	int loop = 1, choice;

	while (loop == 1)
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
			cin.clear();
			cin.ignore(1000, '\n'); //problema do pisca pisca resolvido :)
			break;
		}
	}
	exit(0);
}

int main(){
	/***************************coloca em cada vector os programas, canais e filmes lidos dos respectivos ficheiros.txt*******************************/
	box.open_channels_file();
	box.open_movies_file();
	box.open_programs_file();

	/************************************************************************************************************************************************/

	box.openBox();//chama a funcao que tem o funcionamento da box em si
	
  //exit(0);
	
}


