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

Date Modification::getModifDate() const {
	return modifDate;
}
char* Modification::getProduct() const {
	return product;
}
size_t Modification::getQuantity() const {
	return quantity;
}
bool Modification::getInOrOut() const {
	return inOrOut;
}

void Modification::setModifDate(const Date& newDate) {
	modifDate.setYear(newDate.getYear());
	modifDate.setMonth(newDate.getMonth());
	modifDate.setDay(newDate.getDay());
}
void Modification::setProduct(const char* newProduct) {
	product = new char[strlen(newProduct) + 1];
	strcpy_s(product, strlen(newProduct) + 1, newProduct);
}
void Modification::setQuantity(const size_t newQuantity) {
	quantity = newQuantity;
}
void Modification::setInOrOut(const bool newBool) {
	inOrOut = newBool;
}