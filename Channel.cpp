#include "Channel.h"
#include <string>
#include "fstream"
#include <vector>

#include <time.h>
#include "Box.h"
#include <iostream>
using namespace std;

Channel::Channel()
{
}

Channel::Channel(string name){
	this->name = name;
}

string Channel::getChannelName(){
	return name;
}

void Channel::setChannelName(string nome)
{
	name = nome;
}

