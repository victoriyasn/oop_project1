#include "Product.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

Product::Product() {
	productName.setString("Unknown");

	expireDate.setYear(2001);
	expireDate.setMonth(1);
	expireDate.setDay(1);

	entryDate.setYear(2000);
	entryDate.setMonth(1);
	entryDate.setDay(1);

	madeBy.setString("Unknown");
	

	quantity = 1;

	placeInShop.setSectionNum(0);
	placeInShop.setShelfNum(0);
	placeInShop.setProductNum(0);

	comment.setString("None");

}

MyString Product::getProductName() const {
	return productName;
}
Date Product::getExpireDate() const {
	return expireDate;
}
Date Product::getEntryDate() const {
	return entryDate;
}
MyString Product::getMadeBy() const {
	return madeBy;
}
size_t Product::getQuantity() const {
	return quantity;
}
Placement Product::getPlacement() const {
	return placeInShop;
}
MyString Product::getComment() const {
	return comment;
}

void Product::setProductName(const MyString& otherName) {
	productName.setString(otherName.getString());
}
void Product::setExpireDate(const Date& otherExpDate) {
	expireDate.setYear(otherExpDate.getYear());
	expireDate.setMonth(otherExpDate.getMonth());
	expireDate.setDay(otherExpDate.getDay());
}
void Product::setEntryDate(const Date& otherEntDate){
	entryDate.setYear(otherEntDate.getYear());
	entryDate.setMonth(otherEntDate.getMonth());
	entryDate.setDay(otherEntDate.getDay());
}
void Product::setMadeBy(const MyString&  otherMadeBy) {
	madeBy.setString(otherMadeBy.getString());
}
void Product::setQuantity(const size_t& otherQuantity) {
	quantity = otherQuantity;
}
void Product::setPlaceinShop(const Placement& otherPlacement) {
	placeInShop.setShelfNum(otherPlacement.getShelfNum());
	placeInShop.setSectionNum(otherPlacement.getSectionNum());
	placeInShop.setProductNum(otherPlacement.getProductNum());
}
void Product::setComment(const MyString& otherComment) {
	comment.setString(otherComment.getString());
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
	out << "Comment: ";
	out << product.getComment();
	out << endl;

	return out;
}


void Product::putInFile(ofstream& out) {


	productName.putInFile(out);

	expireDate.putInFile(out);
	entryDate.putInFile(out);

	madeBy.putInFile(out);

	out << quantity;
	out << " ";

	placeInShop.putInFile(out);

	comment.putInFile(out);

	
}
//gotta fix the read
void Product::readFromFile(ifstream& in) {
	Product temp;

//	size_t readSize;
//	in.read((char*)&readSize, sizeof(size_t));
//	in.read((char*)&temp.productName, readSize);

	temp.productName.readFromFile(in);
	temp.expireDate.readFromFile(in);
	temp.entryDate.readFromFile(in);
	temp.madeBy.readFromFile(in);
	in >> quantity;
	temp.placeInShop.readFromFile(in);
	temp.comment.readFromFile(in);



	setProductName(temp.getProductName());
	setExpireDate(temp.expireDate);
	setEntryDate(temp.entryDate);
	setMadeBy(temp.getMadeBy());

	quantity = temp.quantity;
	
	setPlaceinShop(temp.placeInShop);
	setComment(temp.getComment());


}

