#ifndef _MOVIE
 #define _MOVIE

#include<iostream>

using namespace std;

class Movie{
  string title;
  float cost;
  unsigned int timesRented;
 public:
	 Movie(); 
	 Movie(string title, float cost);
	 Movie(string title, float cost, unsigned int timesRented);
	 /*retorna o titulo do filme*/
	 string getTitle() const;
	 /*retorna o preco do filme*/
	 float getCost() const;
	 /*muda o titulo de um filme*/
	 void setTitle(string newname);
	 /*muda o preco do filme*/
	 void setCost(float custo);
	 unsigned int getRented() const;
	 void Rent();
};

#endif
