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
  Program(string name, int duration, string day, int hour, int minutes);
};

#endif
