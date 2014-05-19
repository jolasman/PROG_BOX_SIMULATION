#include "Box.h"
#include "menu.h"
#include "Channel.h"
#include "Movie.h"
#include "fstream"

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

bool Box::checkPassword()
{
	string passw;
	
	cout << "----------------------- You are trying to access the Box -----------------------\n" << endl;
	cout << "type your PASSWORD please:\n " << endl;
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
	string day = "Monday";
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
				toBeRecorded.push_back(Program(line, duration, day, hour, minutes)); //poe no vector
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
	for (unsigned int i = 0; i < toBeRecorded.size(); i++)
	{
		cout << toBeRecorded[i].getName() << endl;
	}
}

string Box::compare2(string name)
{
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (name == channels[i].getChannelName())
		{
			return name;
		}
		else
		{
			return false;
		}

	}

}