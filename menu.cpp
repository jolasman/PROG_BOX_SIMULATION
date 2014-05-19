#include "menu.h"
#include "Channel.h"
#include "Movie.h"
#include "Program.h"
#include "Box.h"

#include "fstream"
#include <cstdlib>
#include <vector>
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
	Box ch;

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
		ch.open_channels_file();
		ch.readChannelsVector();
	}

	// falta a parte de mudar o nome dos canais
	/***********************************************************************ainda esta a dar erro aqui ao mudar o nome*************************/
	if (number == 2)
	{
		Box b;
		Channel c;
		system("cls");

		string nameChannel;
		
		cout << "Which  name Channel you want to change?:\n\n";
		cin >> nameChannel;

		// falta comparar se existe o canal no vector
		
		if (nameChannel == b.compare2(nameChannel))
		{
			string namenew;
			cout << "New name: " << endl;
			//alterar o nome
			cin >> namenew;
			c.setChannelName(namenew);
			
			cout << "Name changed you success!" << endl;
		}
		else
		{
			cout << " any Channel with this name! try again later" << endl;
		}
	}


	// falta a parte de adicionar um canal

	if (number == 3)
	{

		system("cls");

		string newChannel;

		cout << "Please type the name of the new Channel:\n\n";
		cin >> newChannel;

		/*if (newChannel == algumcanaldoquejaexistenovetor)
		{
		cout << "This Channel already exists!" << endl;
		}
		else
		{
		//colocar o canal no vetor
		cout << "Channel added with success!" << endl;
		}*/
	}
	//falta a parte de remover um canal
	
	if (number == 4)
	{

		system("cls");

		string oldChannel;

		cout << "Please type the name of the Channel to remove:\n\n";
		cin >> oldChannel;


		/*	if (oldChannel == algumcanaldoquejaexistenovetor)
			{
			//remover o canal do vector
			cout << "This Channel has been removed with success!" << endl;
			}
			else
			{

			cout << "Channel does not exists! try later" << endl;
			}*/
	}

	if (number == 5)
	{

		system("cls");

		string newProgram, newday;
		int hour, minute;

		cout << "Please type the name of the new Program:\n\n";
		cin >> newProgram;
		cout << "Please type the hour when the new Program starts(only the hour, not the minutes):\n\n";
		cin >> hour;
		cout << "Please type the minutes when the new Program starts:\n\n";
		cin >> minute;

		/*if (newProgram == algumcanaldoquejaexistenovetor)
		{
		
		cout << "This Program already exists! try later" << endl;
		}
		else
		{
			//adicionar o programa ao vector

		cout << "Channel added with success!" << endl;
		}*/
	}

	if (number == 6)
	{

		system("cls");

		menu_inicial();
	}

	system("pause");
}

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

void menu_movies(){
	Box mov;

	system("CLS");
	cout << "--------------------------Welcome to the Movies menu----------------------------\n\n";
	
	int number;
	cout << "1. See Movieclub" << endl;
	cout << "2. Tyitle change" << endl;
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
		mov.open_movies_file();
		mov.readMoviesVector();
	}

	// falta a parte de mudar o nome dos filmes

	if (number == 2)
	{
		Box b;
		Movie m;

		system("cls");

		string nameMovie;

		cout << "Which Movie name you want to change?:\n\n";
		cin >> nameMovie;

		// falta comparar se existe o programa no vector

		/*if (nameMovie == b.compare2(nameMovie)
		{
		string namenew;
		cout << "New name: " << endl;
		//colocar o novo nome
		cin >> namenew;
		m.setTitle(namenew);
		
		cout << "Name changed you success!" << endl;
		}
		else
		{
		cout << " Any Movie with this name! try again later" << endl;
		}*/
	}


	// falta a parte de mudar o preco do filme

	if (number == 3)
	{

		system("cls");

		string nameMovie;
		float movieCost;

		cout << "Please type the name of the Movie to change cost:\n\n";
		cin >> nameMovie;
		
		/*if (nameMovie == programa_no_vetor)
		{
			cout << "new cost:" << endl;
			cin >> movieCost;
			//colocar o preco no filme
		}
		else
		{
			cout << "choose other Movie please:" << endl;
			
		}
		*/
	}

	//falta a parte de remover o filme
	if (number == 4)
	{

		system("cls");

		string nameMovie;
		
		/*if (nameMovie == alguma_filme_no_vetor)
		{
			cout << "Movie removed with success!" << endl;
		}

		else
		{
			cout << "not removed! try again later" << endl;
		}

		*/
	}

	if (number == 5)// exit
	{

		system("cls");

		menu_inicial();
	}

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

string getPassword()
{
	ifstream password;
	string pass;

	password.open("PASSWORD.txt");
	getline(password, pass);
	password.close();
	return pass;

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

			break;
		}

	}
exit(0);
}
