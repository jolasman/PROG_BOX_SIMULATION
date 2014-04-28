#include "Channel.h"
#include <string>
#include <iostream>
using namespace std;

Channel::Channel(string name){
	this->name = name;
}

string Channel::getChannelName(){
	return name;
}
