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

void Program::open_programs_file(){
	string line;

	ifstream fs("Programs.txt");

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