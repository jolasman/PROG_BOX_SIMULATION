#include "Program.h"
#include "fstream"
#include <string>
#include <iostream>
using namespace std;


/*Program::Program(string name, int duration, string day, int hour, int minutes){
	this->name = name;
	this->duration = duration;
	this->getDay = day;
	this->getHour = hour;
	this->getMinutes = minutes;
	//nao sei se é asism aqui
}*/
/*ver este erro aqui*/

Program::Program()
{

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