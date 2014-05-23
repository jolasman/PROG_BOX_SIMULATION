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
  vector<Program> recorded;

 public:
	 Box();
	 Box(string passwd, Date currentDate);
	 bool seeTime(int hour, int minute, int duration, int newHour, int newMinute, int newDuration);
	 
	 /*chama as funcoes necessarias para que se abra os menus*/
	 void openBox();

	 /************************************************funcoes de abrir, ler ficheiros e colocar em vectores o seu conteudo******************************/
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
	 /*************************************************************************************************************************************************/
	 
 	 /*********************************************************************menus de canais*************************************************************/
	 /*imprime na consola o submenu que faz a operacao de mudar o nome a um canal*/
	 void submenuNameChannels();
	 /*imprime na consola o submenu que faz a operacao de criar um novo canal*/
	 void submenuNewChannel();
	 /*imprime na consola o submenu que faz a operacao de remover um canal*/
	 void submenuRemoveChannel();
	 /*imprime na consola o submenu que faz a operacao de adicionar um programa a um canal*/
	 void submenuAddProgramChannel();
	 /****************************************************************************************************************************************************/
	  
	 /*********************************************************************menus de movies*************************************************************/
	 /*imprime na consola o submenu que faz a operacao de mudar o nome a um filme*/
	 void submenuNameMovies();
	 /*imprime na consola o submenu que faz a operacao de remover um filme*/
	 void submenuRemoveMovies();
	 /*imprime na consola o submenu que faz a operacao de mudar o preco de um filme*/
	 void submenuChangeCostMovies();
	 /****************************************************************************************************************************************************/
	 
	 /*********************************************************************menus de programs*************************************************************/
	 /*imprime na consola o submenu que faz a operacao de mudar o nome a um programa*/
	 void submenuNamePrograms();
	 /*imprime na consola o submenu que faz a operacao de remover um programa*/
	 void submenuRemovePrograms();
	 /*imprime na consola o submenu que faz a operacao de mudar o tipo de um programa*/
	 void submenuChangeTypePrograms();
	 /*imprime na consola o submenu que faz a operacao de mudar a data de um programa*/
	 void submenuChangeDatePrograms();
	 /*imprime na consola o submenu que faz a operacao de mudar a duracao de um programa*/
	 void submenuChangeDurationPrograms();
	 /****************************************************************************************************************************************************/
	 
	 vector<Program> listByDay() const;
	 vector<Program> listByDay(string day) const;
	 vector<Program> listByChannel(string  channel) const;
	 vector<Program> listByChannel(string  channel, string day) const;
	 vector<Program> listByType(string type) const;
	 vector<Program> listByType(string type, string day) const;

	 vector<Program> listRecorded() const;
	 vector<Program> listToRecord() const;
	 
	 bool rentMovies(string title);
	 float moneySpent() const;
	 int timesWhatched(string title) const;
	 bool checkPassword(string passw) const;
	 bool changePassword();          // ask, verify and change the password
	 Date getDate() const;
	 bool importChannels(string file_path);
	 bool importMovies(string file_path);
	 bool importRecorded(string file_path);

	 // Channel CRUD
	 bool createChanel();
	 bool removeChanel();
	 bool updateChanel();
	 // Program CRUD
	 bool createProgram(string chanel);
	 bool removeProgram();
	 bool updateProgram();
	 // Movie CRUD
	 bool createMovie();
	 bool removeMovie();
	 bool updateMovie(); 
};

#endif
