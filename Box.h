#ifndef _BOX
 #define _BOX

#include<iostream>
#include<vector>
#include<string>

#include "Date.h"
#include "Channel.h"
#include "Program.h"
#include "Movie.h"

using namespace std;


class Box{
  string password;
  Date currentDate;
  vector<Channel> channels;
  vector<Movie> movieClub;
  vector<Movie> seenMovies;
  vector<Program> toBeRecorded;
  vector<Program> recorded;

 public:
  Box(string passwd, Date currentDate);
  /*chama as funcoes necessarias para que se abra os menus*/
  void openBox();
  vector<Program> listByDay(string day);
  vector<Program> listByChannel(string  channel, string day);
  vector<Program> listByType(string  type, string day);
  bool rentMovies(string title);
  float moneySpent();
  int timesWhatched(string title);
  
  bool checkPassword();
  bool checkPasswordAgain();
  void changePassword();          // ask, verify and change the password
  // Channel CRUD
  bool createdChanel();
  bool removeChanel();
  bool updateChanel();
  // Program CRUD
  bool createdProgram(string chanel);
  bool removeProgram();
  bool updateProgram();
  // Movie CRUD
  bool createdMovie();
  bool removeMovie();
  bool updateMovie();

};

#endif
