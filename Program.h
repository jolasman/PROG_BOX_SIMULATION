#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program{
  string name;
  string type;    // introduced in the final version of the work text
  bool recorded;  // introduced in the final version of the work text
  int duration;  // in minutes
  Date exhibitionDate;

 public:
	 Program();
	 Program(string name, int duration, string day, int hour, int minutes);
	 string getType();
	 /*retorna o valor inteiro da duracao*/
	 int getDuration();
	 /*retorna o nome do programa*/
	 string getName();
	 /*muda o nome do programa*/
	 void setProgramName(string nome);
	 /*muda o tipo do programa*/
	 void setTypeName(string nome);
	 /*muda a data do programa*/
	 void changeDate(Date data);
	 /*muda a duracao do programa*/
	 void setDuration(int duration);

	 /*retorna a data do programa*/
	 Date getDate();

};

#endif
