#include "Box.h"
#include "Channel.h"
#include "Movie.h"
#include "fstream"
#include "menu.h"
#include <vector>
#include <string>
#include <time.h>

#include <iostream>
using namespace std;


Box::Box()
{
}

Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}

/*************************************************password *******************************************/
bool Box::checkPassword()
{
	string passw;
	
	cout << "----------------------- You are trying to access the Box -----------------------\n" << endl;
	cout << "type your PASSWORD please:\n " << endl;
	getline(cin,passw);

	if (passw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Box::checkPasswordAgain()
{
	string passw;

	cout << "\n\n Wrong PASSWORD! Is your LASTE chance now!" << endl;
	cout << "\n Type your PASSWORD again please:\n\n " << endl;
	cin >> passw;

	if (passw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Box::changePassword()
{
	string oldpass, newpass;

	cout << "type your old PASSWORD please:" << endl;
	cin >> oldpass;
	system("cls");

	if (oldpass == password)
	{
		cout << "type your new PASSWORD: " << endl;
		cin >> newpass;
		cout << "Success!" << endl;
	}
	else
	{
		cout << "INCORRECT PASSWORD! try again! " << endl;
	}
}
/*******************************************************load box***************************************/

void Box::openBox()
{


	if (checkPassword() == true)
	{
		menu_box();
	}
	if (checkPasswordAgain() == true)
	{
		menu_box();
	}
	else
	{
		
		checkPasswordAgain();
			
	}

}

/************************************************************abrir e ler ficheiros**********************************/
void Box::open_channels_file()
{
	string line;
	

	ifstream fs("Channels.txt");

	if (fs.is_open())
	{
		//tenta abrir ficheiro 
		while (!fs.eof()){

			getline(fs, line);
			if (line == "")
			{
			}
			else
			{
				channels.push_back(line); //poe no vector
			}

		}
		fs.close();	//fecha ficheiro 
	}
	else{
		cout << "ficheiro nao abre" << endl;
	}
}

void Box::readChannelsVector()
{
	for(unsigned int i = 0; i < channels.size(); i++)
	{
		cout << channels[i].getChannelName() << endl;
	}
}

void Box::open_movies_file(){

	
	string line;
	float cost = 5.00;
	Movie nome = { line, cost };

	ifstream fs("Movies.txt");

	if (fs.is_open())
	{
		//tenta abrir ficheiro 
		while (!fs.eof()){

			getline(fs, line);
			if (line == "")
			{
			}
			else
			{
				movieClub.push_back(Movie(line,cost)); //poe no vector
			}
		}
		fs.close();														//fecha ficheiro 
	}
	else{
		cout << "ficheiro nao abre" << endl;
	}

}

void Box::readMoviesVector()
{
	for (unsigned int i = 0; i < movieClub.size(); i++)
	{
		cout << movieClub[i].getTitle() << endl;
	}
}

void Box::open_programs_file(){
	

	string line;
	int duration = 10;
	string day = "Monday"; ///////********************tem de ser alterado****************///////
	int hour = 20;
	int minutes = 15;
	Program nome = { line, duration, day, hour, minutes };

	ifstream fs("Programs.txt");

	if (fs.is_open())
	{
		//tenta abrir ficheiro 
		while (!fs.eof()){

			getline(fs, line);
			if (line == "")
			{
			}
			else
			{
				recorded.push_back(Program(line, duration, day, hour, minutes)); //poe no vector
			}

		}
		fs.close();														//fecha ficheiro 
	}
	else{
		cout << "ficheiro nao abre" << endl;
	}
}

void Box::readProgramsVector()
{
	for (unsigned int i = 0; i < recorded.size(); i++)
	{
		cout << recorded[i].getName() << endl;
	}
}

/********************************************************submenus Channels**********************************************/
void Box::submenuNameChannels()
{

	int mudar = 0;
	system("cls");

	string nameChannel;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which  name Channel you want to change?:\n\n";
	getline(cin, nameChannel);

	for (unsigned int i = 0; i < channels.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (nameChannel == channels[i].getChannelName())
		{
			string namenew;
			cout << "New name: \n" << endl;

			//alterar o nome
			getline(cin, namenew);
			if (namenew == "")
			{
				cout << "Invalid name! try again later" << endl;
			}
			else
			{
				channels[i].setChannelName(namenew);

				cout << "\nName changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}
		
	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}
	
}

void Box::submenuNewChannel(){
	system("cls");

	string newChannel;
	bool existe = 0;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Please type the name of the new Channel:\n\n";
	getline(cin,newChannel);

	for (unsigned int i = 0; i < channels.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (newChannel == channels[i].getChannelName())
		{
			existe = 1;
			cout << "This Channel already exists!" << endl;
		}
	}
	if (existe == 0)
	{
		if (newChannel == "")
		{
			cout << "Channel nedds a real name please..." << endl;
		}
		else
			{
			channels.push_back(newChannel);
			cout << "Channel added with success!" << endl;
		}

	}
}

void Box::submenuRemoveChannel(){

	system("cls");
	bool existe = 0;
	string oldChannel;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Please type the name of the Channel to remove:\n\n";
	getline(cin,oldChannel);


	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (oldChannel == channels[i].getChannelName())//compara se o nome introduzido e igual a algum do vector de canais
		{
			existe = 1;

			channels.erase(channels.begin() + i);//apaga o canal no vector

			cout << "This Channel has been removed with success!" << endl;
		}
	}
	if (existe == 0)
	{

		cout << "Channel does not exists! try later" << endl;
	}
}


/*******************falta acabar este submenu de addiconar programas***********************/
void Box::submenuAddProgramChannel()
{
	system("cls");
	bool existe = 0;
	string newProgram, newday, newtype, newchannel;
	int hour, minute,duration;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Please type the name of the new Program:\n\n";
	getline(cin,newProgram);
	cout << "Please type the hour when the new Program starts(only the hour, not the minutes):\n\n";
	cin >> hour;
	cout << "Please type the minutes when the new Program starts:\n\n";
	cin >> minute;
	cout << "Please type the duration of the new Program starts:\n\n";
	cin >> duration;
	cout << "Please type the type of the new Program:\n\n";
	getline(cin, newtype);
	cout << "Please type the name of the channel to create a new Program:\n\n";
	getline(cin, newchannel);

	Program prog = { newProgram, duration, newday, hour, minute };//declaracao do programa
	prog.setTypeName(newtype);

	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == newchannel)//ve se tem o canal no vector
		{

			if (channels[i].getPrograms().size() == 0)//se o vector dos programas estiver vazio
			{
				channels[i].addProgram(prog);
				cout << "Program created!" << endl;
				
			}
			else
			{
				for (unsigned int j = 0; j < channels[i].getPrograms().size(); j++)
				{
					if (channels[i].getPrograms()[j].getDate().getDay() == newday)
					{

						//convem depois verificar as horas do dia para saber se nao se sobrepoe a nenhum programa ja existente

					}

				}
				channels[i].addProgram(prog);
				cout << "Program reated!" << endl;
				existe = 1;
			}
		}
	}
	if (existe == 0)
	{
		cout << "Program not created! try again later" << endl;
	}
}

/***********************************************************************************/


/********************************************************submenus Movies**********************************************/
void Box::submenuNameMovies()
{

	bool mudar = 0;
	system("cls");

	string nameMovie;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Movie name you want to change?:\n\n";
	getline(cin, nameMovie);

	for (unsigned int i = 0; i < movieClub.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (nameMovie == movieClub[i].getTitle())
		{
			string namenew;
			cout << "New name: \n" << endl;

			//alterar o nome
			getline(cin, namenew);
			if (namenew == "")
			{
				cout << "Invalid name! try again later" << endl;
			}
			else
			{
				movieClub[i].setTitle(namenew);

				cout << "\nName changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}

}

void Box::submenuChangeCostMovies()
{

	bool mudar = 0;
	system("cls");

	string nameMovie;
	float cost;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Movie name you want to change the cost?:\n\n";
	getline(cin, nameMovie);

	for (unsigned int i = 0; i < movieClub.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (nameMovie == movieClub[i].getTitle())
		{
			
			cout << "New cost: \n" << endl;
			cin >> cost;
			
			if (cost == 0.0)
			{
				cout << "cost nedd to be more than 0.0" << endl;
			}
			else
			{
				movieClub[i].setCost(cost);

				cout << "\nCost changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}

}

void Box::submenuRemoveMovies()
{
	system("cls");
	bool existe = 0;
	string oldMovie;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Please type the name of the Movie to remove:\n\n";
	getline(cin, oldMovie);


	for (unsigned int i = 0; i < movieClub.size(); i++)
	{
		if (oldMovie == movieClub[i].getTitle())//compara se o nome introduzido e igual a algum do vector de canais
		{
			existe = 1;

			movieClub.erase(movieClub.begin() + i);//apaga o canal no vector

			cout << "This Movie has been removed with success!" << endl;
		}
	}
	if (existe == 0)
	{

		cout << "Movie does not exists! try later" << endl;
	}
}

/********************************************************************************************************************/



/********************************************************submenus Programs**********************************************/
void Box::submenuNamePrograms()
{
	bool mudar = 0;
	system("cls");

	string nameProgram;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Program name you want to change?:\n\n";
	getline(cin, nameProgram);

	for (unsigned int i = 0; i < recorded.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (nameProgram == recorded[i].getName())
		{
			string namenew;
			cout << "New name: \n" << endl;

			//alterar o nome
			getline(cin, namenew);
			if (namenew == "")
			{
				cout << "Invalid name! try again later" << endl;
			}
			else
			{
				recorded[i].setProgramName(namenew);

				cout << "\nName changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}

}

void Box::submenuChangeTypePrograms()
{

	bool mudar = 0;
	system("cls");

	string nameType;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Movie name you want to change the type?:\n\n";
	getline(cin, nameType);

	for (unsigned int i = 0; i < recorded.size(); i++)//compara se o nome introduzido e igual a algum do vector de canais
	{
		if (nameType == recorded[i].getType())
		{
			string newnameType;

			cout << "New type: \n" << endl;
			getline(cin, newnameType);

			if (newnameType == "")
			{
				cout << "Invalid Type! try again" << endl;
			}
			else
			{
				recorded[i].setTypeName(newnameType);

				cout << "\nType changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}

}

void Box::submenuChangeDatePrograms()
{
	bool mudar = 0;
	system("cls");

	string program, channel,day;
	int hour, minutes;
	
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Program name you want to change the Date?:\n\n";
	getline(cin, program);

	cout << "Which Channel have this program?:\n\n";
	getline(cin, channel);

	cout << "Day?:\n\n";
	getline(cin, day);

	cout << "Hour?:\n\n";
	cin >> hour;

	cout << "Minutes?:\n\n";
	cin >> minutes;

	Date data = { day, (unsigned int)hour, (unsigned int)minutes };//declaracao da data

	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == channel)//procura o nome do canal no vector e ve se existe
		{
			for (unsigned int j = 0; j < channels[i].getPrograms().size(); j++)
			{
				if (channels[i].getPrograms()[j].getName() == program)//procura o nome do programa e ve se existe
				{
					channels[i].getPrograms()[j].changeDate(data);//muda para a data que foi declarada
					cout << "Date changed!" << endl;
					mudar = 1;
				}
			}
		}

	}

		if (mudar == 0)
		{
			cout << "\nNot changed! Try again later" << endl;
		}
	}

void Box::submenuChangeDurationPrograms()
{
	bool mudar = 0;
	system("cls");

	string program, channel;
	int duration;

	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Program name you want to change the Duration?:\n\n";
	getline(cin, program);

	cout << "Which Channel have this program?:\n\n";
	getline(cin, channel);

	cout << "Which duration you want?:\n\n";
	cin >> duration;

	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == channel)//procura o nome do canal no vector e ve se existe
		{
			for (unsigned int j = 0; j < channels[i].getPrograms().size(); j++)
			{
				if (channels[i].getPrograms()[j].getName() == program)//procura o nome do programa e ve se existe
				{
					channels[i].getPrograms()[j].setDuration(duration);//muda para a data que foi declarada
					cout << "Duration changed!" << endl;
					mudar = 1;
				}
			}
		}

	}

	if (mudar == 0)
	{
		cout << "\nNot changed! Try again later" << endl;
	}

}

void Box::submenuRemovePrograms(){
	bool mudar = 0;
	system("cls");

	string channel, program;
	
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Program name you want to remove?:\n\n";
	getline(cin, program);

	cout << "Which Channel have this program?:\n\n";
	getline(cin, channel);

	
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == channel)//procura o nome do canal no vector e ve se existe
		{
			for (unsigned int j = 0; j < channels[i].getPrograms().size(); j++)
			{
				if (channels[i].getPrograms()[j].getName() == program)//procura o nome do programa e ve se existe
				{
					channels[i].getPrograms().erase(channels[i].getPrograms().begin() + j);;//remove o programa do vector
					cout << "Program removed!" << endl;
					mudar = 1;
				}
			}
		}

	}

	if (mudar == 0)
	{
		cout << "\nNot removed! Try again later" << endl;
	}

}

/********************************************************************************************************************/