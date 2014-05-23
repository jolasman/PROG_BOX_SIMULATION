#include "Date.h"
#include <iostream>

using namespace std;

#include <string>

Date::Date(){}

Date::Date(string weekDay, unsigned hour, unsigned minutes){
	this->weekDay = weekDay;
	this->hour = hour;
	this->minutes = minutes;
}

string Date::getDay() const{
	return weekDay;
}

unsigned int Date::getHour() const{
	return hour;
}

unsigned int Date::getMinutes() const{
	return minutes;
}

bool Date::operator<(const Date& d){
	unsigned int day1, day2;
	if (weekDay == "MONDAY") day1 = 1;
	else if (weekDay == "TUESDAY") day1 = 2;
	else if (weekDay == "WEDNESDAY") day1 = 3;
	else if (weekDay == "THURSDAY") day1 = 4;
	else if (weekDay == "FRIDAY") day1 = 5;
	else if (weekDay == "SATURDAY") day1 = 6;
	else if (weekDay == "SUNDAY") day1 = 7;

	if (weekDay == "MONDAY") day2 = 1;
	else if (d.getDay() == "TUESDAY") day2 = 2;
	else if (d.getDay() == "WEDNESDAY") day2 = 3;
	else if (d.getDay() == "THURSDAY") day2 = 4;
	else if (d.getDay() == "FRIDAY") day2 = 5;
	else if (d.getDay() == "SATURDAY") day2 = 6;
	else if (d.getDay() == "SUNDAY") day2 = 7;

	if (day1 == day2){
		if (hour == d.getHour()){
			return minutes < d.getMinutes();
		}
		return hour < d.getHour();
	}
	return day1 < day2;
}