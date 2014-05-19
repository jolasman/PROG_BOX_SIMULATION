#ifndef _DATE
#define _DATE

#include <string> 
#include <iostream>
using namespace std;


class Date{
  string weekDay;
  unsigned hour;
  unsigned minutes;
 public:
	 Date();
	 Date(string day, unsigned int hour, unsigned int minutes);
	 
	 /*retorna o dia da data*/
	 string getDay();
	 /*retorna a hora da data*/
	 int getHour();
	 /*retorna os minutos da data*/
	 int getMinutes();
};

#endif
