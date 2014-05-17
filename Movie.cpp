#include "Movie.h"
#include "fstream"
#include <string>
#include <iostream>
using namespace std;

Movie::Movie()
{

}
Movie::Movie(string title, string type, float cost){
	this->title = title;
	this->type = type;
	this->cost = cost;
}

string Movie::getTitle(){
	return title;
}


string Movie::getType(){
	return type;
}

float Movie::getCost(){
	return cost;
}


void Movie::open_movies_file(){

	string line;
	
	ifstream fs("Movies.txt");

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