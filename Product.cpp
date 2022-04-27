#include "Product.h"
#include<cstring>

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