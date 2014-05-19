#ifndef _MOVIE
 #define _MOVIE

#include<iostream>

using namespace std;


class Movie{
  string title;
  string type;
  float cost;
  unsigned timesRented;
 public:
	 Movie(); 
	 Movie(string title, float cost);
	 /*retorna o titulo do filme*/
	 string getTitle();
	 /*retorna o preco do filme*/
	 float getCost();
	 /*muda o titulo de um filme*/
	 void setTitle(string newname);
};

#endif
