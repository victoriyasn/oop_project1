#ifndef __PRODUCT_H
#define __PRODUCT_H
#include "Placement.h"
#include "Date.h"

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
};

#endif