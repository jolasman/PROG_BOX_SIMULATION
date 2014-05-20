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
	 Box();
  Box(string passwd, Date currentDate);
 
  /*chama as funcoes necessarias para que se abra os menus*/
  void openBox();
  
  /*abre o ficheiro dos canais e poe os canais no vector dos canais da box*/
  void open_channels_file();
  /*imprime na consola o vector do canais*/
    void readChannelsVector();
  
/*abre o ficheiro dos filmes e poe os filmes no vector dos filmes da box*/
  void open_movies_file();
  /*imprime na consola o vector dos filmes*/
  
  void readMoviesVector();
  /*abre o ficheiro dos programas e poe os programas no vector dos programas da box*/
  void open_programs_file();
  /*imprime na consola o vector dos programas*/
  void readProgramsVector();


  string compare2(string name);

  void submenuNameChannels();

  void submenuNewChannel();


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
