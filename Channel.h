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



	/*acede ao ficheiro dos canais*/
	 void open_channels_file();
  
};

#endif
