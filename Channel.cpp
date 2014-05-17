#include "Channel.h"
#include <string>
#include "fstream"
#include <iostream>
#include <time.h>
using namespace std;

Channel::Channel()
{

}
Channel::Channel(string name){
	this->name = name;
}

string Channel::getChannelName(){
	return name;
}


void Channel::open_channels_file()
{
	string line;
	
	ifstream fs("Channels.txt");

	if (fs.is_open())
	{
		//tenta abrir ficheiro 
		while (!fs.eof()){

			getline(fs, line);											
			cout << line << endl;

		}
		fs.close();														//fecha ficheiro 
	}
	else{
		cout << "ficheiro nao abre" << endl;
	}
	
}