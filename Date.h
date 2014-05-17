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
  Date(string day, unsigned hour, unsigned minutes);
  void currentDate();// adicionei
  string getDay();
  int getHour();
  int getMinutes();
};

#endif
