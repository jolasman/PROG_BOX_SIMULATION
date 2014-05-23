#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream> 
#include "Date.h"

using namespace std;

class Program{
  string name;
  string type;
  bool recorded;
  int duration;   // in minutes
  Date exhibitionDate;

 public:
	 Program();
	 Program(string name, string type, int duration, string day, int hour, int minutes);
	 string getType() const;
	 /*retorna o valor inteiro da duracao do programa*/
	 int getDuration() const;
	 /*retorna o nome do programa*/
	 string getName() const;
	 /*muda o nome do programa*/
	 void setName(string nome);
	 /*muda o tipo do programa*/
	 void setType(string nome);
	 /*muda a data do programa*/
	 void changeDate(Date data);
	 /*muda a duracao do programa*/
	 void setDuration(int duration);
	 /*verifica a flag recorded*/
	 bool isRecorded();
	 /*altera a flag recorded*/
	 void setRecorded();

	 /*retorna a data do programa*/
	 Date getDate() const;

};

#endif
