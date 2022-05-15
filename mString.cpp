#include<iostream>
#include<cstring>
#include "mString.h"
using namespace std;

void MyString::freeMem() {
	delete[]string;
}
void MyString::copyFrom(const MyString& other) {
	size = other.size;
	string = new char[strlen(other.string) + 1];
	strcpy_s(string,strlen(other.string)+1, other.string);
}

MyString::MyString() {
	size = 0;
	string = new char[1];
	string[0] = '\0';
}
MyString::MyString(const char* other) {
	setString(other);

}
MyString::MyString(const MyString& other) {
	copyFrom(other);
}
MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		freeMem();
		copyFrom(other);
	}
	return *this;
}
MyString::~MyString() {
	freeMem();
}

char* MyString::getString() const {
	return string;
}
size_t MyString::getSize() const {
	return size;
}
void MyString::setString(const char* other) {
	size = strlen(other) + 1;
	string = new char[size];
	strcpy_s(string,size, other);
}


bool MyString::operator==(const MyString& other) {
	return strcmp(string, other.string) == 0;
}

ostream& operator<<(ostream& out, const MyString& write) {
	out << write.string;
	return out;
}
istream& operator>>(istream& in, MyString& read) {
	char fromFile[240];
	in >> fromFile;

	read.string = new char[strlen(fromFile) + 1];
	strcpy_s(read.string, strlen(fromFile) + 1, fromFile);
	read.size = strlen(fromFile);

	return in;
}

void MyString::putInFile(ofstream& out) {
	out << strlen(string);
	out << ",";
	out << string;
	out << ",";
}
void MyString::readFromFile(ifstream& in) {
	size_t readSize;
	in >> readSize;
	delete[] string;
	string = new char[readSize + 1];
	char c = in.get();
	in.getline(string, readSize + 1, ',');

}