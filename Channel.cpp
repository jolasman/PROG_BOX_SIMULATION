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

string Channel::getChannelName() const
{
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

vector<Program> Channel::getPrograms() const
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
	cout << "Invalid program! Try again later" << endl;
}

bool Channel::checkOverlap(Program p){
	unsigned int begin_p1, begin_p2, end_p1, end_p2;
	begin_p1 = p.getDate().getHour() * 60 + p.getDate().getMinutes();
	end_p1 = begin_p1 + p.getDuration();
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		if (programs[i].getDate().getDay() == p.getDate().getDay()){		//se forem no mesmo dia
			begin_p2 = programs[i].getDate().getHour() * 60 + programs[i].getDate().getMinutes();
			end_p2 = begin_p2 + programs[i].getDuration();
			//(inicio_existente < inicio_novo)
			if (begin_p2 < begin_p1){
				if (end_p2 > begin_p1)
					return false;
			}
			//(inicio_existente >= inicio_novo)
			else{
				if (end_p1 > begin_p2)
					return false;
			}
		}
	}
	return true;
}