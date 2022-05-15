#ifndef __PRODUCT_H
#define __PRODUCT_H
#include "Placement.h"
#include "Date.h"
#include "mString.h"
#include<iostream>
using namespace std;

class Product {
private:
	MyString productName;
	Date expireDate;
	Date entryDate;
	MyString madeBy;
	size_t quantity;
	Placement placeInShop;
	MyString comment;

public:
	Product();
	MyString getProductName() const;
	Date getExpireDate() const;
	Date getEntryDate() const;
	MyString getMadeBy() const;
	size_t getQuantity() const;
	Placement getPlacement() const;
	MyString getComment() const;
	void setProductName(const MyString&);
	void setExpireDate(const Date&);
	void setEntryDate(const Date&);
	void setMadeBy(const MyString&);
	void setQuantity(const size_t&);
	void setPlaceinShop(const Placement&);
	void setComment(const MyString&);
	friend ostream& operator<<(ostream&, const Product&);

	void putInFile(ofstream&);
	void readFromFile(ifstream&);
};

#endif