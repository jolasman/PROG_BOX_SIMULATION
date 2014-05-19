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
	 Movie(string title, string type, float cost);
	 /*retorna o titulo do filme*/
	 string getTitle();
	 /*retorna o tipo do filme*/
	 string getType();
	 /*retorna o preco do filme*/
	 float getCost();


	/*abre o ficheiro dos filmes*/
	 void Movie::open_movies_file();
};

#endif
