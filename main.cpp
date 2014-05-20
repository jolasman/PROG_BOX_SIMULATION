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

	vector<string> vdays = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" };
	
	int aleat = rand() % 7 + 1;
	string day1;
	
	for (int j = 0; j < aleat; j++)
		day1 = vdays[j];
	
	unsigned int hour1 = rand() % 24 + 1;
	unsigned int minutes = rand() % 60 + 1;
	
	Date dat = { day1, hour1, minutes };
	return dat;
}

/*
[*]
[*]foi criado o ficheiro channels com aproximadamente 69 canais 
[*]foi criado o ficheiro movies com aproximadamente 51 FILMES
[*]foi criado o ficheiro programs com aproximadamente 60 programas de televisao com: nome,canal,horaDeExibicao,duracao 
[*]


[*]e preciso depois no codigo criar um ficheiro que guarde os filmes ja vistos do video club
[*]e outro para guardae os programas ja gravados pelo utilizador
[*]
*/
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

	/************************************************************falta fazer a funca de adicionar um programa ao canal no box.cpp**************************/
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
	Box prog;

	system("CLS");
	cout << "--------------------------Welcome to the Programs menu--------------------------\n\n";
	int number;
	cout << "1. See all Programs" << endl;
	cout << "2. Name change" << endl;
	cout << "3. Type change" << endl;
	cout << "4. Date change" << endl;
	cout << "5. Duration change" << endl;
	cout << "6. Remove Program" << endl;
	cout << "7. Return to main menu\n\n";
	cout << "Choose a number: ";
	cin >> number;

	if (number == 1)
	{

		system("cls");

		cout << "The Programs list:\n\n";
		//chamar lista de progrmas
		prog.open_programs_file();
		prog.readProgramsVector();
	}

	// falta a parte de mudar o nome dos programas

	if (number == 2)
	{

		system("cls");

		string nameProgram;

		cout << "Which name Program you want to change?:\n\n";
		cin >> nameProgram;

		// falta comparar se existe o programa no vector

		/*if (nameProgram == cenas_do_vetor)
		{
		string namenew;
		cout << "New name: " << endl;
		cin >> namenew;
		//alterar o nome
		cout << "Name changed you success!" << endl;
		}
		else
		{
		cout << " Any Channel with this name! try again later" << endl;
		}*/
	}


	// falta a parte de mudar o tipo de programa

	if (number == 3)
	{

		system("cls");

		string nameProgram;
		string newType;

		cout << "Please type the name of the Program to change type:\n\n";
		cin >> nameProgram;
		/*if (nameProgram == programa_no_vetor)
		{
		cout << "choose other type please or the same type:" << endl;
		//mfazer set do type daquele programa
		*/
	}
	//falta a parte de mudar a data

	if (number == 4)
	{

		system("cls");

		string day, channel, program;
		int hour, minutes;
		char carater;

		cout << "Please type the name of the Program to change date: " << endl;
		getline(cin, program);
		cout << "wich Channel have this program?: " << endl;
		getline(cin, channel);
		system("cls");

		cout << "New day is: " << endl;
		getline(cin, day);
		cout << "New time of exibition(HOURS:MINUTES): " << endl;
		cin >> hour >> carater >> minutes;

		//falta por a alterar

		/*Date data = { day, (unsigned int)hour, (unsigned int)minutes };

		for (unsigned int i = 0; i < channels.size(); i++)//vector de canais
		{
		if (channels[i].getName() == channel)
		{
		for (unsigned int h = 0; h < channels[i].getPrograms1().size(); h++)
		{
		if (channels[i].getPrograms1()[h].getName() == program)
		{
		channels[i].getPrograms1()[h].changeDate(data);
		cout << "Date changed with success!" << endl;
		return;
		}
		}
		}

		}
		cout << "Date do not change! try later" << endl;
		return;*/

	}

	// alterar a duracao do programa
	if (number == 5)
	{

		system("cls");

		string oldname, newname, channel;
		int duracao;

		cout << "Please type the name of the Program to change duration:\n\n";
		getline(cin, oldname);

		cout << "Which Channel have this Program? : " << endl;
		getline(cin, channel);


		cout << "New duration: " << endl;
		cin >> duracao;

		/*for (unsigned int i = 0; i < channels.size(); i++)// vector de canais
		{
		if (channels[i].getName() == channel)
		{
		for (unsigned int h = 0; h < channels[i].getPrograms1().size(); h++)
		{
		if (channels[i].getPrograms1()[h].getName() == oldname)
		{
		channels[i].getPrograms1()[h].changeDuration(duracao);
		cout << "Changed with success!" << endl;
		return;

		}
		}
		}
		}
		cout << "Not changed! try later " << endl;
		*/
	}

	if (number == 6)//remove
	{

		system("cls");

		string Program, channel;



		cout << "Please type the name of the Program to remove " << endl;
		getline(cin, Program);

		cout << "Which Channel have this Program? " << endl;
		getline(cin, channel);

		/*for (unsigned int i = 0; i < channels.size(); i++)
		{
		if (channels[i].getName() == channel)
		{
		for (unsigned int h = 0; h < channels[i].getPrograms1().size(); h++)
		{
		if (channels[i].getPrograms1()[h].getName() == Program)
		{
		channels[i].getPrograms1().erase(channels[i].getPrograms1().begin() + h);
		cout << "Removed with success!";
		return;
		}
		}
		}
		}
		cout << "Not removed! try later";
		return;
		*/
	}


	if (number == 7)// exit
	{

		system("cls");

		menu_inicial();
	}

	system("pause");

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
	}


	// falta a parte de mudar o preco do filme

	if (number == 3)
	{
		box.submenuNameMovies();
		system("pause");

	}

	//falta a parte de remover o filme
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
			cin.ignore(1000); /****************************ver aqui*******************/
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


