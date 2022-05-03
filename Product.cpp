#include "Product.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

void Product::copyFrom(const Product& other) {
	productName = new char[strlen(other.productName) + 1];
	strcpy_s(productName, strlen(other.productName) + 1, other.productName);

	expireDate.setYear(other.expireDate.getYear());
	expireDate.setMonth(other.expireDate.getMonth());
	expireDate.setDay(other.expireDate.getDay());

	entryDate.setYear(other.entryDate.getYear());
	entryDate.setMonth(other.entryDate.getMonth());
	entryDate.setDay(other.entryDate.getDay());

	madeBy = new char[strlen(other.madeBy) + 1];
	strcpy_s(madeBy, strlen(other.madeBy) + 1, other.madeBy);

	quantity = other.quantity;

	placeInShop.setSectionNum(other.placeInShop.getSectionNum());
	placeInShop.setShelfNum(other.placeInShop.getShelfNum());
	placeInShop.setProductNum(other.placeInShop.getProductNum());

	comment = new char[strlen(other.comment) + 1];
	strcpy_s(comment, strlen(other.comment) + 1, other.comment);

}

void Product::freeMemory() {
	delete[]productName;
	delete[]madeBy;
	delete[]comment;
}

Product::Product() {
	productName = new char[strlen("Unknown") + 1];
	strcpy_s(productName, strlen("Unknown") + 1, "Unkown");

	expireDate.setYear(2001);
	expireDate.setMonth(1);
	expireDate.setDay(1);

	entryDate.setYear(2000);
	entryDate.setMonth(1);
	entryDate.setDay(1);

	madeBy = new char[strlen("Unknown") + 1];
	strcpy_s(madeBy, strlen("Unknown") + 1, "Unknown");

	quantity = 1;

	placeInShop.setSectionNum(0);
	placeInShop.setShelfNum(0);
	placeInShop.setProductNum(0);

	comment = new char[strlen("None") + 1];
	strcpy_s(comment, strlen("None") + 1, "None");
}

Product::Product(const Product& other) {
	copyFrom(other);
}
Product& Product::operator=(const Product& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
Product::~Product() {
	freeMemory();
}

char* Product::getProductName() const {
	return productName;
}
Date Product::getExpireDate() const {
	return expireDate;
}
Date Product::getEntryDate() const {
	return entryDate;
}
char* Product::getMadeBy() const {
	return madeBy;
}
size_t Product::getQuantity() const {
	return quantity;
}
Placement Product::getPlacement() const {
	return placeInShop;
}
char* Product::getComment() const {
	return comment;
}

void Product::setProductName(const char* otherName) {
	productName = new char[strlen(otherName) + 1];
	strcpy_s(productName, strlen(otherName) + 1, otherName);
}
void Product::setExpireDate(const Date otherExpDate) {
	expireDate.setYear(otherExpDate.getYear());
	expireDate.setMonth(otherExpDate.getMonth());
	expireDate.setDay(otherExpDate.getDay());
}
void Product::setEntryDate(const Date otherEntDate){
	entryDate.setYear(otherEntDate.getYear());
	entryDate.setMonth(otherEntDate.getMonth());
	entryDate.setDay(otherEntDate.getDay());
}
void Product::setMadeBy(const char* otherMadeBy) {
	madeBy = new char[strlen(otherMadeBy) + 1];
	strcpy_s(madeBy, strlen(otherMadeBy) + 1, otherMadeBy);
}
void Product::setQuantity(const size_t otherQuantity) {
	quantity = otherQuantity;
}
void Product::setPlaceinShop(const Placement otherPlacement) {
	placeInShop.setShelfNum(otherPlacement.getShelfNum());
	placeInShop.setSectionNum(otherPlacement.getSectionNum());
	placeInShop.setProductNum(otherPlacement.getProductNum());
}
void Product::setComment(const char* otherComment) {
	comment = new char[strlen(otherComment) + 1];
	strcpy_s(comment, strlen(otherComment) + 1, otherComment);
}

ostream& operator<<(ostream& out, const Product& product) {
	out << "Name of product: ";
	out << product.getProductName();
	out << endl;
	out << "Expire date: ";
	out << product.getExpireDate();
	out << endl;
	out << "Entry date: ";
	out << product.getEntryDate();
	out << endl;
	out<<"Made by: ";
	out << product.getMadeBy();
	out << endl;
	out << "Quantity: ";
	out << product.getQuantity();
	out << endl;
	out << "Placement: ";
	out << product.getPlacement();
	out << endl;
	out << "Comment: ";
	out << product.getComment();
	out << endl;

	return out;
}

void Product::putInFile(const char* fileName) {
	ofstream file(fileName);
	size_t writeSize;
	writeSize = strlen(productName) + 1;
	file.write((const char*)&writeSize, sizeof(size_t));
	file.write((const char*)&productName, writeSize);

	expireDate.putInFile(fileName);
	entryDate.putInFile(fileName);

	writeSize = strlen(madeBy) + 1;
	file.write((const char*)&writeSize, sizeof(size_t));
	file.write((const char*)&madeBy, writeSize);

	file.write((const char*)&quantity, sizeof(quantity));

	placeInShop.putInFile(fileName);

	writeSize = strlen(comment) + 1;
	file.write((const char*)&writeSize, sizeof(size_t));
	file.write((const char*)&comment, writeSize );

	file.close();
}
void Product::readFromFile(const char* fileName) {
	ifstream file(fileName);
	Product temp;

	size_t readSize;
	file.read((char*)&readSize, sizeof(size_t));
	file.read((char*)&temp.productName, readSize);

	temp.expireDate.readFromFile(fileName);
	temp.entryDate.readFromFile(fileName);
	
	file.read((char*)&readSize, sizeof(size_t));
	file.read((char*)&temp.madeBy, readSize);
	
	file.read((char*)&temp.quantity, sizeof(size_t));

	temp.placeInShop.readFromFile(fileName);

	file.read((char*)&readSize, sizeof(size_t));
	file.read((char*)&temp.comment, readSize);

	file.close();

	productName = new char[strlen(temp.productName) + 1];
	strcpy_s(productName, strlen(temp.productName) + 1, temp.productName);
	
	setExpireDate(temp.expireDate);
	setEntryDate(temp.entryDate);

	madeBy = new char[strlen(temp.madeBy) + 1];
	strcpy_s(madeBy, strlen(temp.madeBy) + 1, temp.madeBy);

	quantity = temp.quantity;
	
	setPlaceinShop(temp.placeInShop);

	comment = new char[strlen(temp.comment) + 1];
	strcpy_s(comment, strlen(temp.comment) + 1, temp.comment);


}

