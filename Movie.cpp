#include "Movie.h"
#include <string>
#include <iostream>
using namespace std;


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