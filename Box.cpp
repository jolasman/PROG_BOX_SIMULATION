#include "Box.h"
#include "Channel.h"
#include "Movie.h"
#include "fstream"
#include "menu.h"

#include <vector>
#include <string>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;

Box::Box(){}

Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}

bool Box::seeTime(int hour, int minute, int duration, int newHour, int newMinute, int newDuration)
{
	int timeInicial, timeFinal, timeInicialNew,timeFinalNew;

	timeInicial = hour * 60 + minute; //da o time em minutos para facilitar a soma

	timeFinal = timeInicial + duration;// a hora final do programa e a hora inicial mais a sua duracao

	timeInicialNew = newHour * 60 + newMinute;// do novo programa a adicionar

	timeFinalNew = timeInicialNew + newDuration;// do novo programa a adicionar

	if (timeFinalNew < timeInicial)
	{
		return true;
	}
	if (timeInicialNew > timeFinal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************password **********************************************************/
bool Box::checkPassword(string passw) const
{
	if (passw == password)
		return true;
	else
		return false;
}

bool Box::changePassword()
{
	string oldpass, newpass;

	cout << "Type your old PASSWORD please:" << endl;
	cin >> oldpass;
	system("cls");

	if (oldpass == password)
	{
		cout << "Type your new PASSWORD (at least five characters): " << endl;
		cin >> newpass;
		if (newpass.size() > 5)
		{
			password = newpass;
			return true;
		}
		cout << "PASSWORD to short. Not changed." << endl;
		return false;
	}
	else
	{
		cout << "INCORRECT PASSWORD." << endl;
		return false;
	}
}
/********************************************************************************************************************/

/***************************************************abrir e ler ficheiros********************************************/
bool Box::importChannels(string file_path)
{
	ifstream file(file_path);
	string line, temp, channelName, progName, progType, progWeekDay;
	int pos1, pos2, duration, hour, minutes;
	bool channel_exists;
	Channel channel;
	Program program;

	if (file.is_open())
	{
		while (!file.eof())
		{
			channel_exists = false;

			/*Procura nome do canal*/
			getline(file, line);
			pos1 = line.find(';');
			if (pos1 == string::npos)
				break;
			channelName = line.substr(0, pos1);
			
			/*Procura nome do programa*/
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			progName = line.substr(pos1, pos2 - pos1);

			/*Procura tipo do programa*/
			pos1 = pos2;
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			progType = line.substr(pos1, pos2 - pos1);
			
			/*Procura duracao do programa*/
			pos1 = pos2;
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			temp = line.substr(pos1, pos2 - pos1);
			duration = atoi(temp.c_str());

			/*Procura dia do programa*/
			pos1 = pos2;
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			progWeekDay = line.substr(pos1, pos2 - pos1);

			/*Procura hora do programa*/
			pos1 = pos2;
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			temp = line.substr(pos1, pos2 - pos1);
			hour = atoi(temp.c_str());

			/*Procura minuto do programa*/
			temp = line.substr(pos2 + 1);
			minutes = atoi(temp.c_str());
			
			program = Program(progName, progType, duration, progWeekDay, hour, minutes);
			//cout << program.getName() << endl;

			/*verifica se ja existe o canal*/
			for (unsigned int i = 0; i < channels.size(); i++)
			{
				if (channels[i].getChannelName() == channelName)
				{
					channels[i].addProgram(program);
					channel_exists = true;
					break;
				}
			}
			if (channel_exists == false)
			{
				Channel channel = Channel(channelName);
				channel.addProgram(program);
				channels.push_back(channel);
			}
		}
		return true;
	}
	return false;
}

bool Box::importRecorded(string file_path)
{
	ifstream file(file_path);
	string progName;
	vector<Program> programs;

	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, progName);
			for (unsigned int i = 0; i < channels.size(); i++)
			{
				programs = channels[i].getPrograms();
				for (unsigned int j = 0; j < programs.size(); j++)
				{
					//cout << programs[j].getName() << endl; //////////////////DEBUG
					if (programs[j].getName() == progName)
					{
						if (programs[j].getDate() < currentDate)
							channels[i].setRecorded(programs[j].getName());			//set flag recorded to true!!!! Preciso criar nova função na classe Channel?!
						recorded.push_back(programs[j]);
						break;
					}
				}
			}			
		}
		return true;
	}
	cout << "ficheiro nao abre" << endl;
	return false;
}

bool Box::importMovies(string file_path)
{
	ifstream file(file_path);
	string line, movieName, temp;
	//temp, channelName, progName, progType, progWeekDay;
	unsigned int pos1, pos2, timesRented;
	float cost;

	if (file.is_open())
	{
		while (!file.eof())
		{
			/*Procura nome do filme*/
			getline(file, line);
			pos1 = line.find(';');
			if (pos1 == string::npos)
				break;
			movieName = line.substr(0, pos1);

			/*Procura preco do filme*/
			pos2 = line.find(';', pos1 + 1);
			if (pos2 == string::npos)
				break;
			pos1++;
			temp = line.substr(pos1, pos2 - pos1);
			cost = atof(temp.c_str());

			/*Procura numero de visualizacoes do filme*/
			temp = line.substr(pos2 + 1);
			timesRented = atoi(temp.c_str());

			if (timesRented > 0)
			{
				Movie movie(movieName, cost, timesRented);
				seenMovies.push_back(movie);
				//cout << movie.getTitle() << " " << movie.getCost() << " " << movie.getRented() << endl;
			}
			else
			{
				Movie movie(movieName, cost);
				movieClub.push_back(movie);
				//cout << movie.getTitle() << " " << movie.getCost() << " " << movie.getRented() << endl;
			}			
		}
		return true;
	}
	return false;
}

bool Box::exportChannels(string file_path)
{
	ofstream file(file_path, ofstream::out);
	vector<Program> p;

	if (file.is_open())
	{
		for (unsigned int i = 0; i < channels.size(); i++)
		{
			p = channels[i].getPrograms();
			for (unsigned int j = 0; j < p.size(); j++)
			{
				file << channels[i].getChannelName() << ";" << p[j].getName() << ";" << p[j].getType() << ";" << p[j].getDuration() << ";";
				file << p[j].getDate().getDay() << ";" << p[j].getDate().getHour() << ";" << p[j].getDate().getMinutes() << endl;
			}
		}
		return true;
	}
	return false;
}

bool Box::exportRecorded(string file_path)
{
	ofstream file(file_path, ofstream::out);

	if (file.is_open())
	{
		for (unsigned int i = 0; i < recorded.size(); i++)
		{
			file << recorded[i].getName() << endl;
		}
		return true;
	}
	return false;
}

bool Box::exportMovies(string file_path)
{
	ofstream file(file_path, ofstream::out);

	if (file.is_open())
	{
		for (unsigned int i = 0; i < movieClub.size(); i++)
		{
			file << movieClub[i].getTitle() << ";" << movieClub[i].getCost() << ";0" << endl;
		}
		for (unsigned int i = 0; i < seenMovies.size(); i++)
		{
			file << seenMovies[i].getTitle() << ";" << seenMovies[i].getCost() << ";" << seenMovies[i].getRented()<< endl;
		}
		return true;
	}
	return false;
}
/*********************************************************************************************************************/

/********************************************************submenus Channels********************************************/
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
/*********************************************************************************************************************/

/*******************falta acabar este submenu de adicionar programas**************************************************/
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
	cout << "Please type the type of the new Program:\n\n";
	getline(cin, newtype);
	cout << "Please type the name of the channel to create a new Program:\n\n";
	getline(cin, newchannel);
	cout << "Please type the day of the new Program:\n\n";
	getline(cin, newday);
	system("cls");
	cout << "Please type the hour when the new Program starts(only the hour, not the minutes):\n\n";
	cin >> hour;
	cout << "Please type the minutes when the new Program starts:\n\n";
	cin >> minute;
	cout << "Please type the duration of the new Program starts:\n\n";
	cin >> duration;

	Program prog = { newProgram, newtype, duration, newday, hour, minute };//declaracao do programa
	prog.setType(newtype);// muda o tipo do programa

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
					if (channels[i].getPrograms()[j].getDate().getDay() == newday)//verificar o dia 
					{
						bool timesee;
						//convem depois verificar a data a ver se e depois da currentDate()

						timesee = seeTime(channels[i].getPrograms()[j].getDate().getHour(), channels[i].getPrograms()[j].getDate().getMinutes(),
							channels[i].getPrograms()[j].getDuration(), hour, minute, duration);
						if (timesee == false)
							{
							cout << "Already exists a program at this time! " << endl;
						}
					}
				}
				channels[i].addProgram(prog);
				cout << "Program reated!" << endl;
				existe = 1;
			}
		}
	}
	if (existe == 0)
		cout << "Program not created! try again later" << endl;
}
/*********************************************************************************************************************/

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
		cout << "\nNot changed! Try again later" << endl;
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
		cout << "Movie does not exists! try later" << endl;
}

/*********************************************************************************************************************/

/********************************************************submenus Programs********************************************/
void Box::submenuNamePrograms()
{
	bool mudar = 0;
	system("cls");

	string nameProgram;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Which Program name you want to change?:\n\n";
	getline(cin, nameProgram);

	for (unsigned int i = 0; i < recorded.size(); i++)	//compara se o nome introduzido e igual a algum do vector de canais
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
				recorded[i].setName(namenew);

				cout << "\nName changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
		cout << "\nNot changed! Try again later" << endl;
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
				recorded[i].setType(newnameType);

				cout << "\nType changed you success!\n" << endl;
				mudar = 1;
			}
		}
	}

	if (mudar == 0)
		cout << "\nNot changed! Try again later" << endl;
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
			cout << "\nNot changed! Try again later" << endl;
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
/*********************************************************************************************************************/

/********************************************************Listar Programas*********************************************/
vector<Program> Box::listByDay() const
{
	vector<Program> progsDay;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		vector<Program> progsChannel = channels[i].getPrograms();
		for (unsigned int j = 0; j < progsChannel.size(); j++)
		{
			if (progsChannel[j].getDate().getDay() == currentDate.getDay())
				progsDay.push_back(progsChannel[j]);
		}
	}
	return progsDay;
}

vector<Program> Box::listByDay(string day) const
{
	vector<Program> progsDay;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		vector<Program> progsChannel = channels[i].getPrograms();
		for (unsigned int j = 0; j < progsChannel.size(); j++)
		{
			if (progsChannel[j].getDate().getDay() == day)
				progsDay.push_back(progsChannel[j]);
		}
	}
	return progsDay;
}

vector<Program> Box::listByChannel(string channel) const
{
	vector<Program> progsChannel;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == channel)
		{
			progsChannel = channels[i].getPrograms();
			break;
		}
	}
	return progsChannel;
}

vector<Program> Box::listByChannel(string channel, string day) const
{
	vector<Program> progsDay;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getChannelName() == channel)
		{
			vector<Program> progsChannel = channels[i].getPrograms();
			for (unsigned int j = 0; j < progsChannel.size(); j++)
			{
				if (progsChannel[j].getDate().getDay() == day)
					progsDay.push_back(progsChannel[j]);
			}
			break;
		}
	}
	return progsDay;
}

vector<Program> Box::listByType(string type) const
{
	vector<Program> progsType;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		vector<Program> progsChannel = channels[i].getPrograms();
		for (unsigned int j = 0; j < progsChannel.size(); j++)
		{
			if (progsChannel[j].getType() == type)
				progsType.push_back(progsChannel[j]);
		}
	}
	return progsType;
}

vector<Program> Box::listByType(string type, string day) const
{
	vector<Program> progsType;
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		vector<Program> progsChannel = channels[i].getPrograms();
		for (unsigned int j = 0; j < progsChannel.size(); j++)
		{
			if ((progsChannel[j].getType() == type) && (progsChannel[j].getDate().getDay() == day))
				progsType.push_back(progsChannel[j]);
		}
	}
	return progsType;
}

vector<Program> Box::listRecorded() const
{
	vector<Program> rec;
	for (unsigned int i = 0; i < recorded.size(); i++)
	{
		if (recorded[i].getDate() < currentDate)
			rec.push_back(recorded[i]);
	}
	return rec;
}

vector<Program> Box::listToRecord() const
{
	vector<Program> rec;
	for (unsigned int i = 0; i < recorded.size(); i++)
	{
		if (!(recorded[i].getDate() < currentDate))
			rec.push_back(recorded[i]);
	}
	return rec;
}

vector<Movie> Box::listMovies() const
{
	vector<Movie> mov = movieClub;
	return mov;
}

vector<Movie> Box::listSeen() const
{
	vector<Movie> mov = seenMovies;
	return mov;
}

/*********************************************************************************************************************/

/********************************************************Movies*******************************************************/
bool Box::rentMovies(string title)
{
	for (unsigned int i = 0; i < movieClub.size(); i++)
	{
		if (movieClub[i].getTitle() == title)
		{
			movieClub[i].Rent();
			seenMovies.push_back(movieClub[i]);
			movieClub.erase(movieClub.begin() + i);
			return true;
		}
	}
	for (unsigned int i = 0; i < seenMovies.size(); i++)
	{
		if (seenMovies[i].getTitle() == title)
		{
			seenMovies[i].Rent();
			return true;
		}
	}
	return false;
}

float Box::moneySpent() const
{
	float totalCost = 0;
	for (unsigned int i = 0; i < seenMovies.size(); i++)
	{
		totalCost += seenMovies[i].getCost()*seenMovies[i].getRented();
	}
	return totalCost;
}

int Box::timesWhatched(string title) const
{
	for (unsigned int i = 0; i < seenMovies.size(); i++)
	{
		if (seenMovies[i].getTitle() == title)
			return seenMovies[i].getRented();
	}
	return 0;
}
/*********************************************************************************************************************/

/********************************************************Date*********************************************************/
Date Box::getDate() const
{
	return currentDate;
}
/*********************************************************************************************************************/