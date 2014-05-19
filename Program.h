#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program{
  string name;
  int duration;  // in minutes
  Date exhibitionDate;

 public:
	 Program();
	 Program(string name, int duration, string day, int hour, int minutes);

	 /*retorna o valor inteiro da duracao*/
	 int getDuration();
	 /*retorna o nome do programa*/
	 string getName();
	 /*retorna a data do programa*/
	 Date getDate();
};

#endif
