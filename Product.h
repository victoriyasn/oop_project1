#ifndef __PRODUCT_H
#define __PRODUCT_H
#include "Placement.h"
#include "Date.h"
#include<iostream>
using namespace std;

class Product {
private:
	char* productName;
	Date expireDate;
	Date entryDate;
	char* madeBy;
	size_t quantity;
	Placement placeInShop;
	char* comment;
	void copyFrom(const Product&);
	void freeMemory();
public:
	Product();
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();
	char* getProductName() const;
	Date getExpireDate() const;
	Date getEntryDate() const;
	char* getMadeBy() const;
	size_t getQuantity() const;
	Placement getPlacement() const;
	char* getComment() const;
	void setProductName(const char*);
	void setExpireDate(const Date);
	void setEntryDate(const Date);
	void setMadeBy(const char*);
	void setQuantity(const size_t);
	void setPlaceinShop(const Placement);
	void setComment(const char*);
	friend ostream& operator<<(ostream&, const Product&);

	void putInFile(const char*);
	void readFromFile(const char*);
};

#endif