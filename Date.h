#include<iostream>
using namespace std;
#ifndef __DATE_H
#define __DATE_H


class Date {
private:
	size_t day;
	size_t month;
	size_t year;
public:
	Date();
	Date(const size_t, const size_t, const size_t);
	void setDay(const size_t);
	void setMonth(const size_t);
	void setYear(const size_t);
	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;
	bool operator==(const Date&);
	bool operator>(const Date&);
	bool operator<(const Date&);
	bool operator>=(const Date&);
	bool operator<=(const Date&);
	void printDate();

	void putInFile(ofstream& );
	void readFromFile(ifstream& );

	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);




};
#endif