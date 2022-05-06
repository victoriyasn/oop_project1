#include "Placement.h"
#include<iostream>
#include<fstream>
using namespace std;

Placement::Placement() {
	sectionNum = 0;
	shelfNum = 0;
	productNum = 0;
}
void Placement::setSectionNum(const size_t newSect) {
	sectionNum = newSect;
}
void Placement::setShelfNum(const size_t newShelf) {
	shelfNum = newShelf;
}

void Placement::setProductNum(const size_t newProd) {
	productNum = newProd;
}
size_t Placement::getSectionNum() const {
	return sectionNum;
}
size_t Placement::getShelfNum() const {
	return shelfNum;
}

size_t Placement::getProductNum() const {
	return productNum;
}

bool Placement::operator==(const Placement& other) const {
	return sectionNum == other.sectionNum && shelfNum == other.shelfNum && productNum == other.productNum;
}
bool Placement::operator!=(const Placement& other) const {
	return !(this == &other);
}

ostream& operator<<(ostream& out, const Placement& place) {
	out << "Section Num." << place.getSectionNum() << endl;
	out << "Shelf Num." << place.getShelfNum() << endl;

	out << "Product Num." << place.getProductNum() << endl;
	return out;
}

istream& operator>>(istream& in, Placement& place) {
	in >> place.sectionNum;
	in >> place.shelfNum;
	in >> place.productNum;
	return in;
}

void Placement::putInFile(const char* fileName) {
	ofstream file(fileName);
	file.write((const char*)&shelfNum, sizeof(size_t));
	file.write((const char*)&sectionNum, sizeof(size_t));
	file.write((const char*)&productNum, sizeof(size_t));
	file.close();
}
void Placement::readFromFile(const char* fileName) {
	Placement temp;
	ifstream file(fileName);
	file.read((char*)&temp.shelfNum, sizeof(size_t));
	file.read((char*)&temp.sectionNum, sizeof(size_t));
	file.read((char*)&temp.productNum, sizeof(size_t));
	shelfNum = temp.getShelfNum();
	sectionNum = temp.getSectionNum();
	productNum = temp.getProductNum();
	file.close();
}