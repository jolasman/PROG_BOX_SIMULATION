#include "Movie.h"

#include "fstream"
#include <string>
#include <iostream>

using namespace std;

Movie::Movie(){}

Movie::Movie(string title, float cost){
	this->title = title;
	this->cost = cost;
	this->timesRented = 0;
}

Movie::Movie(string title, float cost, unsigned int timesRented){
	this->title = title;
	this->cost = cost;
	this->timesRented = timesRented;
}

string Movie::getTitle() const
{
	return title;
}

float Movie::getCost() const
{
	return cost;
}

void Movie::setTitle(string newname)
{
	this->title = newname;
}

void Movie::setCost(float custo)
{
	this->cost = custo;
}

unsigned int Movie::getRented() const
{
	return timesRented;
}

void Movie::Rent()
{
	timesRented++;
}

