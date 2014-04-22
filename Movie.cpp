#include "Movie.h"
#include <iostream>
#include "string"
using namespace std;


string Movie::getTitle(){
	return title;
}

string Movie::getType(){
	return type;
}

double Movie::getCost(){
	return cost;
}

int Movie::getNum_times(){
	return num_times;
}