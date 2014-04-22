#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;

class Movie{

	string title;
	string type;
	double cost;
	int num_times;

public:
	string getTitle();
	string getType();
	double getCost();
	int getNum_times();
};



#endif
