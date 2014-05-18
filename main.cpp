#include <iostream>
using namespace std;
#include <cstdlib>
#include "fstream"
#include <time.h>
#include <vector>
#include "menu.h"
#include "Channel.h"
#include "Date.h"
#include "Box.h"

// Randomly generates a valid day, hour and minute
Date currentDate(){
	
	srand((unsigned)time(NULL));

	vector<string> vdays = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" };
	
	int aleat = rand() % 7 + 1;
	string day1;
	
	for (int j = 0; j < aleat; j++)
		day1 = vdays[j];
	
	unsigned int hour1 = rand() % 24 + 1;
	unsigned int minutes = rand() % 60 + 1;
	
	Date dat = { day1, hour1, minutes };
	return dat;
}








/*
[*]
[*]foi criado o ficheiro channels com aproximadamente 69 canais 
[*]foi criado o ficheiro movies com aproximadamente 51 FILMES
[*]foi criado o ficheiro programs com aproximadamente 60 programas de televisao com: nome,canal,horaDeExibicao,duracao 
[*]


[*]e preciso depois no codigo criar um ficheiro que guarde os filmes ja vistos do video club
[*]e outro para guardae os programas ja gravados pelo utilizador
[*]
*/
//CHANNEL ~69 
//MOVIES ~51
//PROGRAMS ~60








int main(){
	Date date = currentDate();
	Box box = Box("naotem", date);
	
	menu_box();
	

	
	
  //exit(0);

	
}
