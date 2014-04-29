#include <iostream>
#include <cstdlib>

#include "Date.h"
#include "Box.h"

// Randomly generates a valid day, hour and minute
/*Date currentDate(){
  // to be implemented by the students
}
*/

using namespace std;

int main(){
  //Box box = Box("naotem", currentDate());

	int loop = 1;
	int choice;
	int pressed_key = 0;
	//falta fazer a verificação da password

	/*
	*
	[*] aqui está a ser feito o menu da box. tem a opcao de ver os canais, os filmes, os programas e de sair. ainda so esta estruturado. ja entra nas opcoes mas
	[*] ainda nao sai com a tecla esc. sai com qualquer uma. excepto no 1 que estou a ver se ponho ja a dar. mas esta a dar mal xD
	[*] tambem ainda não esta a sair bem, ou melhor esta a sair bem do loop mas pede duas vezes para carregar numa tecla para sair. 
	*
	*/
	while (loop = 1)
	{

		system("CLS");
		cout << "-------------------------------------BOX----------------------------------------\n\n";
		cout << "1. Channels" << endl;
		cout << "2. Movies" << endl;
		cout << "3. Programs" << endl;
		cout << "4. Exit\n\n";
		cout << "Choose a number: ";
		cin >> choice;
		
			switch (choice)
			{
			case 1:
				system("CLS");
				cout << "--------------------------Welcome to the Channels menu--------------------------\n\n";
				cout << "Please choose one Channel to see the programs:\n\n";

				//chamar a lista de canais

				cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n\n\n\n";
				// qualquer tecla esta a fazer com que retorne ao menu devido ao break
				if (pressed_key == 0x81)
				{
					//fazer aqui a opcao do que faz a tecla. acho que o 0x81 e o da tecla esc. contudo nao se da para fazer assim
				}
				system("pause");
				break;
				
			case 2:
				system("CLS");
				cout << "--------------------------Welcome to the Movies menu----------------------------\n\n";
				cout << "Please choose your favorite movie:\n\n";

				//chamar lista de filmes
				cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n";
				// qualquer tecla esta a fazer com que retorne ao menu devido ao break
				system("pause");
				break;
			case 3:
				system("CLS");
				cout << "--------------------------Welcome to the Programs menu--------------------------\n\n";
				cout << "Please choose your favorite Program:\n\n";

				//chamar lista de progrmas
				cout << "\n\n\n\n\n\n\n\n\tPress esc to main menu\n";
				// qualquer tecla esta a fazer com que retorne ao menu devido ao break
				system("pause");
				break;
			case 4:
				system("CLS");
				cout << " \n\n\n----------------------------Thank You For Watching------------------------------\n\n\n\n\n\n\n\n\n\n\n";
				cout << "\n                                                       program by:";
				cout << "\n                                                                 Joel Carneiro";
				cout << "\n                                                               Filipe Cordeiro\n\n";
				system("pause");
				loop = 0;
				break;
			}
			exit(0);
	}

	




  //exit(0);

	
}
