#ifndef __STORAGE_H
#define __STORAGE_H

#include "Product.h"

class Storage {
private:
	Product* storedProducts;
	size_t size;
	size_t capacity;
	void resize();
	void copyFrom(const Storage&);
	void freeMemory();
public:
	Storage();
	Storage(const Storage&);
	Storage& operator=(const Storage&);
	~Storage();

	
};

#endif