#include "Box.h"
#include "menu.h"



Box::Box(string passwd, Date date):currentDate(date){
  password = passwd;
}

bool Box::checkPassword()
{
	string passw;
	
	cout << "----------------------- You are trying to access the Box -----------------------\n" << endl;
	cout << "type your PASSWORD please:\n " << endl;
	cin >> passw;

	if (passw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Box::checkPasswordAgain()
{
	string passw;

	cout << "\n\n Wrong PASSWORD! Is your LASTE chance now!" << endl;
	cout << "\n Type your PASSWORD again please: " << endl;
	cin >> passw;

	if (passw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Box::changePassword()
{
	string oldpass, newpass;

	cout << "type your old PASSWORD please:" << endl;
	cin >> oldpass;
	system("cls");

	if (oldpass == password)
	{
		cout << "type your new PASSWORD: " << endl;
		cin >> newpass;
		cout << "Success!" << endl;
	}
	else
	{
		cout << "INCORRECT PASSWORD! try again! " << endl;
	}
}

void Box::openBox()
{

	
	if (checkPassword() == true)
	{
		menu_box();
	}
	if (checkPasswordAgain() == true)
	{
		menu_box();
	}
	else
	{
		
		checkPasswordAgain();
			
	}

}