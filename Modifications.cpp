#include<iostream>
#include<cstring>
#include "Modifications.h"
using namespace std;

void Modification::copyFrom(const Modification& other) {

	modifDate = other.modifDate;

	product = new char[strlen(other.product) + 1];
	strcpy_s(product, strlen(other.product) + 1, other.product);

	quantity = other.quantity;

	inOrOut = other.inOrOut;
	
}
void Modification::freeMemory() {
	delete[]product;
}

Modification::Modification() {
	modifDate.setDay(1);
	modifDate.setMonth(1);
	modifDate.setYear(2000);

	product = new char[strlen("Unknown") + 1];
	strcpy_s(product, strlen("Unknown") + 1, "Unknown");
	quantity = 0;
	inOrOut = true;
}
Modification::Modification(const Modification& other) {
	copyFrom(other);
}
Modification& Modification::operator=(const Modification& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
Modification::~Modification() {
	freeMemory();
}