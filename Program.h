#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program /*: public Date*/ {
  string name;
  int duration;  // in minutes
  //Date exhibitionDate;

 public:
	 Program();
	 Program(string name, int duration, string day, int hour, int minutes);
	     /*abre o ficheiro dos programas*/
	 void Program::open_programs_file();
};

#endif
