#include "Date.h"

#include <iostream>
using namespace std;

#include <string>

Date::Date()
{
}

Date::Date(string weekDay, unsigned hour, unsigned minutes){
	this->weekDay = weekDay;
	this->hour = hour;
	this->minutes = minutes;

}

string Date::getDay(){
	return weekDay;
}

int Date::getHour(){
	return hour;
}

int Date::getMinutes(){
	return minutes;
}