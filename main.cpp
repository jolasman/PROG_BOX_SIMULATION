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

string dateToString(Date date)
{
	string s;
	ostringstream ss;
	ss << date.getDay() << ' ';
	ss << setfill('0') << setw(2) << date.getHour() << ':' << setfill('0') << setw(2) << date.getMinutes();
	s = ss.str();
	return s;
}

/*funcao que esconde password enquanto esta a ser digitada*/
string typePassw()
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

/*converte uma string em maiusculas*/
string toUpper(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

Box box = Box(getPassword(), currentDate());
string displayDate = dateToString(box.getDate());

/*Apresenta o ecra de entrada na aplicacao*/
void screen_begin()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                        WELCOME TO THE CABLE TV BOX\n\n\n\n\n\n\n\n\n";
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
}

/*Exibir um ecra de loading no caso da importa��o de ficheiros for demorada */
void screen_loading()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n                        Loading BOX information...\n\n\n\n\n\n\n\n\n";
}

/*Exibir o ecra para introducao de password para acesso a area restricta */
void screen_password()
{
	system("CLS");
	cout << "------------------ You are trying to access a Protected Area -------------------" << endl;
	cout << "Type your PASSWORD please:" << endl;

	string passw = typePassw();
	if (box.checkPassword(passw) == true)
	{
		menu_box();
	}
	else
	{
		cout << "\nWrong PASSWORD! You have just ONE more chance." << endl;
		cout << "Type your PASSWORD again please:" << endl;

		passw = typePassw();
		if (box.checkPassword(passw) == true)
		{
			menu_box();
		}
		else{
			cout << "\nWrong PASSWORD again. Returning to Main Menu." << endl;
			cout << "\n                        (press any key to continue)\n\n";
			_getch();
		}
	}
}

/*Exibir uma lista de Canais passada por vector*/
void screen_list_channels(vector<Channel> channels)
{
	system("CLS");
	cout << "----------------------------------CHANNELS--------------------------------------";
	cout.width(80);
	cout << right << displayDate;
	cout << left << "CHANNEL" << endl << endl;
	for (unsigned int i = 0; i < channels.size(); i++)
		cout << channels[i].getChannelName() << endl;
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
	cout << endl;
}

/*Exibir uma lista de Programas passada por vector*/
void screen_list_programs(vector<Program> programas)
{
	system("CLS");
	cout << "----------------------------------PROGRAMS--------------------------------------";
	cout.width(80);
	cout << right << displayDate << endl;
	cout << left << setw(30) << "NAME" << setw(15) << "TYPE" << setw(20) << "EXHIBITION DATE" << "DURATION" << endl;
	for (unsigned int j = 0; j < programas.size(); j++)
		cout << setw(30) << programas[j].getName() << setw(15) << programas[j].getType() << setw(20) << dateToString(programas[j].getDate()) << programas[j].getDuration() << " min" << endl;
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
	cout << endl;
}

/*Exibir uma lista de filmes passada por vector*/
void screen_list_movies(vector<Movie> movies)
{
	system("CLS");
	cout << "------------------------------------MOVIES--------------------------------------";
	cout.width(80);
	cout << right << displayDate << endl;
	cout << left << setw(57) << "TITLE" << setw(10) << "COST" << "TIMES SEEN" << endl;
	for (unsigned int j = 0; j < movies.size(); j++)
		cout << setw(55) << movies[j].getTitle() << setprecision(2) << fixed << movies[j].getCost() << setw(10) << " EUR" << movies[j].getRented() << endl;
	cout << "\n                        (press any key to continue)\n\n";
	_getch();
	cout << endl;
}

/*Apresenta o ecra de saida da aplicacao*/
void screen_exit(){

	system("CLS");
	cout << "\n\n\n-----------------------------Thank You For Watching-----------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       program by:";
	cout << "\n                                                               Joel Carneiro";
	cout << "\n                                                               Filipe Cordeiro\n\n";
}

/*apresenta no ecra o menu de op��es entre os outros submenus para a possivel navegacao do utilizador*/
void menu_inicial()
{
	system("CLS");
	cout << "-------------------------------------BOX----------------------------------------\n\n";
	cout << "1. Channels" << endl;
	cout << "2. Movies" << endl;
	cout << "3. Programs" << endl;
	cout << "0. Exit\n\n";
	cout << "Choose a number: ";
}
/*apresenta no ecra o submenu com a interacao do utilizador/canais*/

void menu_channels_admin()
{
	int n;
	bool loop1 = 1, loop2;
	char choice;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "------------------------------MANAGE CHANNELS-----------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. See all Channels" << endl;
		cout << "2. Change channel name" << endl;
		cout << "3. Add Channel" << endl;
		cout << "4. Remove Channel" << endl;
		cout << "5. Add program" << endl;
		cout << "0. Return to main menu\n\n";
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_list_channels(box.readChannelsVector());	//chamar lista de canais
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuNameChannel();				//chama a funcao que muda o nome do canal
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuNewChannel();				//chama a funcao que adiciona um canal novo
				system("pause");
				loop2 = 0;
				break;
			case 4:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuRemoveChannel();				//chama a funcao que remove um novo canal
				system("pause");
				loop2 = 0;
			case 5:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuAddProgramChannel();
				loop2 = 0;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
			}
		}
	}
}

/*apresenta no ecra o submenu com a interacao utilizador/programas*/
void menu_programs_admin()
{
	int number;
	bool loop1 = 1, loop2;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "--------------------------Welcome to the Programs menu--------------------------\n\n";

		cout << "1. See all Programs" << endl;
		cout << "2. Create a new Program" << endl;
		cout << "3. Name change" << endl;
		cout << "4. Type change" << endl;
		cout << "5. Date change" << endl;
		cout << "6. Duration change" << endl;
		cout << "7. Remove Program" << endl;
		cout << "0. Return to main menu\n\n";
		cout << "Choose a number: ";


		loop2 = 1;
		while (loop2 == 1)
		{
			cin >> number;

			if (number == 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "The Programs list:\n\n";
				//chamar lista de progrmas
				box.readProgramsVector();
				loop2 = 0;
			}

			if (number == 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuAddProgramChannel();
				loop2 = 0;
			}

			if (number == 3)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuNamePrograms();
				loop2 = 0;
			}

			if (number == 4)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuChangeTypePrograms();
				loop2 = 0;
			}

			if (number == 5)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuChangeDatePrograms();
				loop2 = 0;
			}

			if (number == 6)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuChangeDurationPrograms();
				loop2 = 0;
			}

			if (number == 7)//remove
			{
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuRemovePrograms();
				loop2 = 0;
			}

			if (number == 0)// exit
			{
				loop1 = 0;
				loop2 = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
}

/*menu de opcoes para o admin utilizar com os filmes*/
void menu_movies_admin()
{
	bool loop1 = 1, loop2;
	int n;
	char choice;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "--------------------------Welcome to the Movies menu----------------------------\n\n";

		cout << "1. See Movieclub" << endl;
		cout << "2. Title change" << endl;
		cout << "3. Cost change" << endl;
		cout << "4. Remove Movie" << endl;
		cout << "0. Return to main menu\n\n";
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
				system("cls");
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "The movies list:\n\n";
				//chamar lista de filmes
				box.readMoviesVector();
				system("pause");
				loop2 = 0;
				break;

			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuNameMovies();
				system("pause");
				loop2 = 0;
				break;

			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuChangeCostMovies();
				system("pause");
				loop2 = 0;
				break;

			case 4:
				cin.clear();
				cin.ignore(1000, '\n');
				box.submenuRemoveMovies();
				system("pause");
				loop2 = 0;
				break;

			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			}
		}

	}
}

/*apresenta o menu inicial com as opcoes se ir para admin ou nao*/
void main_menu()
{
	int n;
	bool loop1 = 1, loop2;
	char choice;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "-------------------------------------BOX----------------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. TV" << endl;
		cout << "2. Movies" << endl;
		cout << "3. Manage BOX (password protected)" << endl;
		cout << "0. Exit\n\n";
		//cout << "(Press a valid number)" << endl;
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			//choice=_getch();
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_tv();
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_movies();
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_password();
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

/*menu se escolher a opcao tv*/
void menu_tv()
{
	int n;
	bool loop1 = 1, loop2;
	char choice;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "-----------------------------------TV MENU--------------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. View Tv Program Guide" << endl;
		cout << "2. Manage Recordings" << endl;
		cout << "0. Return to main menu\n\n";
		//cout << "(Press a valid number)" << endl;
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			//choice = _getch();
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_programs();
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_recordings();
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

/*para ver progracoes dos canais*/
void menu_programs()
{
	int n;
	bool loop1 = 1, loop2;
	char choice;
	string day, channel, type;
	string weekdays[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" };
	bool exists;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "----------------------------------PROGRAMS--------------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. Search Programming by day" << endl;
		cout << "2. Search Programming by Channel" << endl;
		cout << "3. Search Programming by Type" << endl;
		cout << "0. Return to main menu\n\n";
		//cout << "(Press a valid number)" << endl;
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			//choice = _getch();
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "----------------------------------PROGRAMS--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << endl << "Enter day of week (empty for today): ";
				getline(cin, day);
				day = toUpper(day);
				exists = 0;				
				for (unsigned int i = 0; i < 7; i++)
				{
					if (day == weekdays[i])
						exists = 1;
				}
				if (exists)
					screen_list_programs(box.listByDay(day));
				else
					screen_list_programs(box.listByDay());
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "----------------------------------PROGRAMS--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << endl << "Enter channel: ";
				getline(cin, channel);
				channel = toUpper(channel);
				cout << endl << "Enter day of week (empty for the whole week): ";
				getline(cin, day);
				day = toUpper(day);
				exists = 0;
				for (unsigned int i = 0; i < 7; i++)
				{
					if (day == weekdays[i])
						exists = 1;
				}
				if (exists)
					screen_list_programs(box.listByChannel(channel, day));
				else
					screen_list_programs(box.listByChannel(channel));
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "----------------------------------PROGRAMS--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << endl << "Enter type of program: ";
				getline(cin, type);
				type = toUpper(type);
				cout << endl << "Enter day of week (empty for the whole week): ";
				getline(cin, day);
				day = toUpper(day);
				exists = 0;
				for (unsigned int i = 0; i < 7; i++)
				{
					if (day == weekdays[i])
						exists = 1;
				}
				if (exists)
					screen_list_programs(box.listByType(type, day));
				else
					screen_list_programs(box.listByType(type));
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

/*para ver gravacoes*/
void menu_recordings()
{
	int n;
	bool loop1 = 1, loop2;
	char choice;
	string programName;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "-------------------------------RECORDINGS MENU----------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. View Recorded Programs" << endl;
		cout << "2. View Scheduled Recordings" << endl;
		cout << "3. Set/unset program to record" << endl;
		cout << "0. Return to main menu\n\n";
		//cout << "(Press a valid number)" << endl;
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			//choice = _getch();
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_list_programs(box.listRecorded());
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_list_programs(box.listToRecord());
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "-------------------------------RECORDINGS MENU----------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << "\nEnter program name to set/unset to record: ";
				getline(cin, programName);
				programName = toUpper(programName);
				system("CLS");
				cout << "-------------------------------RECORDINGS MENU----------------------------------";
				cout.width(80);
				cout << right << displayDate;
				switch (box.setRecorded(programName))
				{
				case -2:
					cout << "\n" << programName << " is already recorded.";
					break;
				case -1:
					cout << "\n" << programName << " is canceled to be recorded!";
					break;
				case 0:
					cout << "\nProgram not found.";
					break;
				case 1:
					cout << "\n" << programName << " is scheduled to be recorded!";;
					break;
				case 2:
					cout << "\n" << programName << " can not be scheduled to be recorded because it has already aired.";
					break;
				}
				cout << "\n\n\n                        (press any key to continue)\n\n";
				_getch();
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

/*apresenta no ecra o submenu com a interacao utilizador/filmes*/
void menu_movies(){
	int n;
	bool loop1 = 1, loop2;
	char choice;
	string movieTitle;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "---------------------------------MOVIES MENU------------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. See Movieclub" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Already seen list" << endl;
		cout << "4. Money Spent" << endl;
		cout << "0. Return to main menu\n\n";
		//cout << "(Press a valid number)" << endl;
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			//choice = _getch();
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_list_movies(box.listMovies());
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "------------------------------------MOVIES--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << "\nEnter movie title to rent: ";
				getline(cin, movieTitle);
				movieTitle = toUpper(movieTitle);
				system("CLS");
				cout << "------------------------------------MOVIES--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				if (box.rentMovies(movieTitle))
					cout << "\n" << movieTitle << " rented!";
				else
					cout << "\nMovie could not be rented.";
				cout << "\n\n\n                        (press any key to continue)\n\n";
				_getch();
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				screen_list_movies(box.listSeen());
				loop2 = 0;
				break;
			case 4:
				cin.clear();
				cin.ignore(1000, '\n');
				system("CLS");
				cout << "------------------------------------MOVIES--------------------------------------";
				cout.width(80);
				cout << right << displayDate;
				cout << endl << "You have spent " << setprecision(2) << std::fixed << box.moneySpent() << " EUR on the videoclub";
				cout << "\n\n\n                        (press any key to continue)\n\n";
				_getch();
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

/*onde � gerado o codigo para interagir com o utilizador para a escolha do que pretende no menu inicial*/
void menu_box(){

	int n;
	bool loop1 = 1, loop2;
	char choice;

	while (loop1 == 1)
	{
		system("CLS");
		cout << "---------------------------------MANAGE BOX-------------------------------------";
		cout.width(80);
		cout << right << displayDate;
		cout << "1. Channels" << endl;
		cout << "2. Movies" << endl;
		cout << "3. Programs" << endl;
		cout << "0. Return\n\n";
		cout << "Choose a number: ";

		loop2 = 1;
		while (loop2 == 1)
		{
			cin >> choice;
			n = choice - '0';
			switch (n)
			{
			case 1:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_channels_admin();
				loop2 = 0;
				break;
			case 2:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_movies_admin();
				loop2 = 0;
				break;
			case 3:
				cin.clear();
				cin.ignore(1000, '\n');
				menu_programs_admin();
				loop2 = 0;
				break;
			case 0:
				cin.clear();
				cin.ignore(1000, '\n');
				loop1 = 0;
				loop2 = 0;
				break;
			default:
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
	}
}

int main()
{
	screen_begin();

	/***********************************************importa dados de ficheiros.txt*******************************************************************/
	screen_loading();
	box.importChannels("Channels&Programs.txt");
	box.importRecorded("Recorded.txt");
	box.importMovies("movies.txt");
	/************************************************************************************************************************************************/

	main_menu();
	screen_exit();

	/***********************************************exporta dados para ficheiros.txt*****************************************************************/
	box.exportChannels("Channels&Programs.txt");
	box.exportRecorded("Recorded.txt");
	box.exportMovies("Movies.txt");
	/************************************************************************************************************************************************/
	_getch();

	return 0;
}


