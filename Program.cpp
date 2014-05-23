#include "Program.h"

#include "fstream"
#include <string>
#include <iostream>

using namespace std;

Program::Program()
{
}

Program::Program(string name, string type, int duration, string day, int hour, int minutes) :exhibitionDate(day, hour, minutes){
	this->name = name;
	this->type = type;
	this->duration = duration;
}

int Program::getDuration() const
{
	return duration;
}

string Program::getType() const
{
	return type;
}

string Program::getName() const
{
	return name;
}

Date Program::getDate() const
{
	return exhibitionDate;
}

void Program::setName(string nome)
{
	this->name = nome;
}

void Program::setType(string tipo)
{
	this->type = tipo;
}

void Program::changeDate(Date data)
{
	this->exhibitionDate = data;
}

void Program::setDuration(int duration)
{
	this->duration = duration;

}

bool Program::isRecorded()
{
	return recorded;
}

void Program::setRecorded()
{
	if (recorded == true)
		recorded = false;
	else
		recorded = true;
}