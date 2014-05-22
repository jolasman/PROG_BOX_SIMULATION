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
	 bool operator<(const Date& d);
	 /*retorna o dia da data*/
	 string getDay() const;
	 /*retorna a hora da data*/
	 unsigned int getHour() const;
	 /*retorna os minutos da data*/
	 unsigned int getMinutes() const;
};

#endif
