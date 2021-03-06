#include "Product.h"
#include "Modifications.h"
#include<fstream>
#ifndef __STORAGE_H
#define __STORAGE_H

class Storage {
private:
	Product* storedProducts;
	size_t size;
	size_t capacity;
	Modification modifications[240];
	size_t modifSize;
	void resize();
	void copyFrom(const Storage&);
	void freeMemory();
public:
	Storage();
	Storage(const Storage&);
	Storage& operator=(const Storage&);
	~Storage();

	void printStorage();
	void addProduct();
	void removeProduct();
	void checkStock();
	void cleanUp();
	
	void putInFile(ofstream&);
	void readFromFile(ifstream&);
};

#endif