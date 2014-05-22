#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>

#include "Program.h"

using namespace std;

class Channel{
  string name;
  vector<Program> programs;
 public:
	 Channel();
	 Channel(string name);
	/*retorna o nome do canal*/
	 string getChannelName();
	 /*altera o nome do canal*/
	 void setChannelName(string nome);
	 	
	 /*adiciona um programa no vector de programas de um canal*/
	 void addProgram(Program p);
	 /*vector que nos da os programas de um canal*/
	 vector<Program> &getPrograms();
	 /*muda o nome de um programa de um canal*/
	 void changeNamePrograms(string oldname, string newname);

};

#endif
