#include <iostream>
#include <cstdlib>
#include "fstream"
#include <sstream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <conio.h>

#include "Channel.h"
#include "Date.h"
#include "Box.h"
#include "menu.h"

using namespace std;

// Randomly generates a valid day, hour and minute
Date currentDate(){
	
	srand((unsigned)time(NULL));
	string vdays[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" }; //alterei de vector para array
	int aleat = rand() % 7; //indice do array: numero aleatorio de 0-6
	string day1;
	day1 = vdays[aleat];
	unsigned int hour1 = rand() % 24;		//numero aleatorio de 0-23
	unsigned int minutes = rand() % 60;		//numero aleatorio de 0-59
	Date dat = {day1, hour1, minutes};
	return dat;
}

string displayDate;

string dateToString(Date date)
{
	string s;
	ostringstream ss;
	ss << date.getDay() << ' ';
	ss << setfill('0') << setw(2) << date.getHour() << ':' << setfill('0') << setw(2) << date.getMinutes();
	s = ss.str();
	return s;
}

string typePassw() //depois mover para o main.cpp
{
	string passw;
	char ch;
	const char ENTER = 13;
	const char BACKSPACE = 8;
	ch = _getch();
	while (ch != ENTER){
		if (ch == BACKSPACE) //se a tecla premida for backspace
		{
			if (passw.size() > 0)
			{
				passw = passw.substr(0, passw.size() - 1);
				cout << '\b';	//Cursor move-se 1 posicao para tras
				cout << " ";	//Cursor sobrepoe letra escrita
				cout << '\b';	//Cursor move-se novamente 1 posicao para tras
			}
		}
		else
		{
			passw += ch;
			cout << '*';
		}
		ch = _getch();
	}
	cout << endl;
	return passw;
}

/*funcao que vai buscar a password do utilizador ao ficheiro password.txt*/
string getPassword()
{
	ifstream password_file;
	string passw = "default"; //no caso de nao encontrar o ficheiro a password fica "default"

	password_file.open("PASSWORD.txt");
	if (password_file.is_open()){
		getline(password_file, passw);
		password_file.close();
	}
	return passw;
}

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
/*apresenta no ecra o submenu com a interacao do utilizador/canais*/

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









/*Apresenta o ecra de entrada na aplicacao*/
void screen_begin()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                        WELCOME TO THE CABLE TV BOX\n\n\n\n\n\n\n\n\n";
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
}

/*Exibir um ecra de loading no caso da importação de ficheiros for demorada */
void screen_loading()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n                        Loading BOX information...\n\n\n\n\n\n\n\n\n";
}

/*Exibir programas gravados*/
void screen_recorded()
{
	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------";
	cout.width(80);
	cout << right << displayDate << endl << endl;
	vector<Program> programas = box.listRecorded();
	for (unsigned int j = 0; j < programas.size(); j++)
		cout << programas[j].getName() << " " << programas[j].getDuration() << " " << programas[j].getType() << " " << programas[j].getDate().getDay() << " " << programas[j].getDate().getHour() << ":" << programas[j].getDate().getMinutes() << endl;
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
	cout << endl;
}

/*Exibir gravacoes agendadas*/
void screen_toRecord()
{
	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------";
	cout.width(80);
	cout << right << displayDate << endl << endl;
	vector<Program> programas = box.listToRecord();
	for (unsigned int j = 0; j < programas.size(); j++)
		cout << programas[j].getName() << " " << programas[j].getDuration() << " " << programas[j].getType() << " " << programas[j].getDate().getDay() << " " << programas[j].getDate().getHour() << ":" << programas[j].getDate().getMinutes() << endl;
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
	cout << endl;
}

/*Apresenta o ecra de saida da aplicacao*/
void screen_exit(){

	system("CLS");
	cout << "\n\n\n-----------------------------Thank You For Watching-----------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       program by:";
	cout << "\n                                                                 Joel Carneiro";
	cout << "\n                                                               Filipe Cordeiro\n\n";
	_getch();
}

/*Prototipos dos menus*/
void main_menu();
void menu_tv();
void menu_movies();
void menu_admin();
void menu_programs();
void menu_recordings();

void main_menu(){

	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------";
	cout.width(80);
	cout << right << displayDate;
	cout << "1. TV" << endl;
	cout << "2. Movies" << endl;
	cout << "3. Manage BOX (password protected)" << endl;
	cout << "4. Exit\n\n";
	cout << "(Press a valid number)" << endl;

	int loop = 1, n;
	char choice;

	while (loop == 1)
	{
		choice = _getch();
		n = choice - '0';
		switch (n)
		{
		case 1:
			menu_tv();
			pressed_key_channels();
			break;
		case 2:
			menu_movies();
			pressed_key_movies();
			break;
		case 3:
			menu_admin(); //ALTERAR!
			pressed_key_programs();
			break;
		case 4:
			screen_exit();
			loop = 0;
			break;
		}
	}
	exit(0);
}

void menu_tv(){

	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------";
	cout.width(80);
	cout << right << displayDate << endl << endl;
	cout << "1. View Tv Program Guide" << endl;
	cout << "2. Manage Recordings" << endl;
	cout << "3. Return to main menu\n\n";
	cout << "(Press a valid number)" << endl;

	int loop = 1, n;
	char choice;

	while (loop == 1)
	{
		choice = _getch();
		n = choice - '0';
		switch (n)
		{
		case 1:
			menu_programs();
			pressed_key_channels();
			break;
		case 2:
			//menu_recordings();
			pressed_key_movies();
			break;
		case 3:
			main_menu();
			pressed_key_programs();
			break;
		}
	}
	exit(0);
}

void menu_admin()
{
	system("CLS");
	cout << "------------------ You are trying to access a Protected Area -------------------\n" << endl;
	cout << "Type your PASSWORD please:" << endl;

	string passw = typePassw();
	if (box.checkPassword(passw) == true)
	{
		menu_box();
	}

	cout << "\nWrong PASSWORD! You have just ONE more chance." << endl;
	cout << "Type your PASSWORD again please:" << endl;

	passw = typePassw();
	if (box.checkPassword(passw) == true)
	{
		menu_box();
	}
	cout << "\nWrong PASSWORD again. Returning to Main Menu." << endl;
	cout << "\n(press any key to continue)";
	_getch();
	main_menu();
}


/****************************************ainda por acabar as tres funcoes de verificacao de teclas carregadas******************************/
void pressed_key_channels()
{
	char x = getchar();
	if (x == 'esc')
		menu_inicial();
	else
		menu_channels();
}

void pressed_key_movies()
{
	char x = getchar();
	if (x == 'esc')
		menu_inicial();
	else
		menu_movies();
}

void pressed_key_programs()
{
	char x = getchar();
	if (x == 'esc')
		menu_inicial();
	else
		menu_programs();
}

/*****************************************************************************************************************************************/



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
			screen_exit();
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




int main()
{
	screen_begin();
	/***************************coloca em cada vector os programas, canais e filmes lidos dos respectivos ficheiros.txt*******************************/
	screen_loading();
	box.importChannels("Channels&Programs.txt");
	box.importRecorded("Recorded.txt");
	//box.importMovies("Movies.txt");	
	/************************************************************************************************************************************************/

	//box.openBox();//alterar esta funcao para menu Admin

	displayDate = dateToString(box.getDate());

	main_menu();
	//screen_recorded();
	//screen_toRecord();

  //exit(0);
	
}


