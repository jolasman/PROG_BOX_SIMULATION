#include "Channel.h"
#include <string>
#include "fstream"
#include <vector>
#include <time.h>
#include "Box.h"
#include <iostream>

using namespace std;

Channel::Channel(){}

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

bool Channel::addProgram(Program program)
{
	if (checkOverlap(program))
	{
		programs.push_back(program);
		return true;
	}
	return false;
}

bool Channel::setRecorded(string name)
{
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		if (programs[i].getName() == name)
		{
			if (programs[i].isRecorded())
				return 0;	//programa ja esta gravado
			programs[i].setRecorded();
			return 1;		//programa marcado como gravado
		}
	}
	return 0;				//nao encontra o programa
}

vector<Program> Channel::getPrograms() const
{
	return programs;
}

bool Channel::changeNamePrograms(string name, string newname)
{
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		if (programs[i].getName() == name)
		{
			programs[i].setName(newname);
			return true;
		}
	}
	return false;
}

bool Channel::checkOverlap(Program p) const
{
	unsigned int begin_p1, begin_p2, end_p1, end_p2;

	begin_p1 = p.getDate().getHour() * 60 + p.getDate().getMinutes();
	end_p1 = begin_p1 + p.getDuration();
	
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		if (programs[i].getDate().getDay() == p.getDate().getDay())		//se forem no mesmo dia
		{
			begin_p2 = programs[i].getDate().getHour() * 60 + programs[i].getDate().getMinutes();
			end_p2 = begin_p2 + programs[i].getDuration();

			//(inicio_prog_existente < inicio_prog_novo)
			if (begin_p2 < begin_p1)
			{
				if (end_p2 > begin_p1)
					return false;
			}

			//(inicio_prog_existente >= inicio_prog_novo)
			else
			{
				if (end_p1 > begin_p2)
					return false;
			}
		}
	}
	return true;
}