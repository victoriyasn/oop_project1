#ifndef __MODIFICATIONS_H
#define __MODIFICATIONS_H
#include "Date.h"

class Modification {
private:
	Date modifDate;
	char* product;
	size_t quantity;
	bool inOrOut; // true if we add, false if we remove
	void copyFrom(const Modification&);
	void freeMemory();
public:
	Modification();
	Modification(const Modification&);
	Modification& operator=(const Modification&);
	~Modification();
};
#endif
