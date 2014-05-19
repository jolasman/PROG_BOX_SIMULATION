#include "Program.h"
#include "fstream"
#include <string>
#include <iostream>
using namespace std;

Program::Program()
{
}

Program::Program(string name, int duration, string day, int hour, int minutes):exhibitionDate(day, hour, minutes){
	this->name = name;
	this->duration = duration;
	
}

int Program::getDuration()
{
	return duration;
}

string Program::getName()
{
	return name;
}

Date Program::getDate()
{
	return exhibitionDate;
}

