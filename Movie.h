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
  Movie(string title, string type, float cost);
  string getTitle();
  string getType();
  float getCost();
};

#endif
