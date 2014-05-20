#include "Channel.h"
#include <string>
#include "fstream"
#include <vector>

#include <time.h>
#include "Box.h"
#include <iostream>
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

void Channel::setChannelName(string nome)
{
	name = nome;
}

void Channel::addProgram(Program program)
{
	programs.push_back(program);

}

vector<Program>& Channel::getPrograms()
{
	return programs;
}

void Channel::changeNamePrograms(string name, string newname)
{
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		if (programs[i].getName() == name)
		{
			programs[i].setProgramName(newname);
			cout << "Name changed!" << endl;
			return;
		}


	}
	cout << "Invalid program! try again later" << endl;
}