#ifndef __MSTRING_H
#define __MSTRING_H
#include<iostream>
#include<fstream>
using namespace std;

class MyString {
private:
	char* string;
	size_t size;
	void freeMem();
	void copyFrom(const MyString&);
public:
	MyString();
	MyString(const MyString&);
	MyString(const char*);
	MyString& operator=(const MyString&);
	~MyString();

	char* getString() const;
	size_t getSize() const;
	void setString(const char*);

	bool operator==(const MyString&);

	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);

	void putInFile(ofstream&);
	void readFromFile(ifstream&);
	

};

#endif
