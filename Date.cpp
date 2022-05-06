#include "Date.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

Date::Date() {
	//we will put a random time as default, but it can be set to be the date the storage has started working later on
	day = 1;
	month = 1;
	year = 2000;
}
void Date::setYear(const size_t newYear) {
	year = newYear;
}

void Date::setMonth(const size_t newMonth) {
	if (newMonth > 1 && newMonth < 12) month = newMonth;
	else month = 1;
}

void Date::setDay(const size_t newDay) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (newDay < 31 && newDay>1) day = newDay;
		else day = 1;
	}
	else if (month == 2) {
		if (newDay < 28 && newDay>1) day = newDay;
		else day = 1;
	}
	else {
		if (newDay < 30 && newDay>1) day = newDay;
		else day = 1;
	}
	
}

Date::Date(const size_t newDay, const size_t newMonth, const size_t newYear) {
	setYear(newYear);
	setMonth(newMonth);
	setDay(newDay);
}

size_t Date::getDay() const {
	return day;
}
size_t Date::getMonth() const {
	return month;
}
size_t Date::getYear() const {
	return year;
}

bool Date::operator==(const Date& other) {
	return year == other.year && month == other.month && day == other.day;
}
bool Date::operator>(const Date& other) {
	if (year < other.year) return false;
	else if (month < other.month) return false;
	else if (day > other.day) return true;
	else return false;
}
bool Date::operator<(const Date& other) {
	if (year > other.year) return false;
	else if (month > other.month) return false;
	else if (day < other.day) return true;
	else return false;
}


//gotta fix those
bool Date::operator>=(const Date& other) {
	if (!(year > other.year)) return false;
	else if (!(month > other.month)) return false;
	else if (!(day < other.day)) return true;
	else return false;
	
}
bool Date::operator<=(const Date& other) {
	if (!(year < other.year)) return false;
	else if (!(month < other.month)) return false;
	else if (!(day > other.day)) return true;
	else return false;
}


void Date::printDate() {
	cout << day << "-" << month << "-" << year;
}

void Date::putInFile(const char* fileName) {
	ofstream file(fileName);
	file.write((const char*)&day, sizeof(size_t));
	file.write((const char*)&month, sizeof(size_t));
	file.write((const char*)&year, sizeof(size_t));
	file.close();
}
void Date::readFromFile(const char* fileName) {
	Date temp;
	ifstream file(fileName);
	file.read((char*)&temp.day, sizeof(size_t));
	file.read((char*)&temp.month, sizeof(size_t));
	file.read((char*)&temp.year, sizeof(size_t));
	setYear(temp.getYear());
	setMonth(temp.getMonth());
	setDay(temp.getDay());
	
	file.close();
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
	return out;
}

istream& operator>>(istream& in, Date& date) {
	Date temp;
	in >> temp.day;
	in >> temp.month;
	in >> temp.year;

	
	date.setYear(temp.getYear());
	date.setMonth(temp.getMonth());
	date.setDay(temp.getDay());

	return in;
}

