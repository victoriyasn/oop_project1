#include "Storage.h"
#include<iostream>
#include<fstream>
using namespace std;
//defining just example capacities for the storage
#define shelfCapacity 20
#define sectionCapacity 10


void Storage::resize() {
	capacity *= 2;
	Product* newArr = new Product[capacity];
	for (size_t i = 0; i < size; i++) {
		newArr[i] = storedProducts[i];
	}
	delete[]storedProducts;
	storedProducts = newArr;
}
void Storage::copyFrom(const Storage& other) {
	size = other.size;
	capacity = other.capacity;
	storedProducts = new Product[capacity];
	for (size_t i = 0; i < size; i++) {
		storedProducts[i] = other.storedProducts[i];
	}
}
void Storage::freeMemory() {
	delete[] storedProducts;
	size = 0;
}

Storage::Storage() {
	capacity = 10;
	storedProducts = new Product[capacity];
	size = 0;
	modifSize = 0;
	modifications[0].setProduct("None");
	Date defModifDate;
	defModifDate.setYear(2000);
	defModifDate.setMonth(1);
	defModifDate.setYear(1);
	modifications[0].setModifDate(defModifDate);
	modifications[0].setQuantity(0);
	modifications[0].setInOrOut(1);
}
Storage::Storage(const Storage& other) {
	copyFrom(other);
}
Storage& Storage::operator=(const Storage& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
Storage::~Storage() {
	freeMemory();
}


void Storage::putInFile(const char* fileName) {
	ofstream file(fileName);
	for (size_t i = 0; i < size; i++) {
		storedProducts[i].putInFile(fileName);
	}
	file.close();
}
void Storage::readFromFile(const char* fileName) {
	ifstream file(fileName);
	for (size_t i = 0; i < size; i++) {
		storedProducts[i].readFromFile(fileName);
	}
	file.close();
}

//functions for the interface

void Storage::printStorage() {
	cout << endl;
	for (size_t i = 0; i < size; i++) {
		cout << storedProducts[i];
	}
}
void Storage::addProduct() {
	
	if (size == capacity) resize();
	Product addProduct;

	char* temp = new char[128];
	cout << "Enter product name: " << endl;
	cin.getline(temp, 128) ;
	addProduct.setProductName(temp);
	
	modifications[modifSize].setProduct(temp);

	Date tempDate;
	cout << "Enter expire date: " << endl;
	cin >> tempDate;
	addProduct.setExpireDate(tempDate);

	cout << "Enter entry date: " << endl;
	cin >> tempDate;
	addProduct.setEntryDate(tempDate);
	modifications[modifSize].setModifDate(tempDate);

	cout << "Made by: " << endl;
	cin.ignore();
	cin.getline(temp, 128);
	addProduct.setMadeBy(temp);

	size_t tempQuantity;
	cout << "Enter quantity: " << endl;
	cin >> tempQuantity;
	addProduct.setQuantity(tempQuantity);
	modifications[modifSize].setQuantity(tempQuantity);

	Placement tempPlace;
	cout << "Enter placement: " << endl;
	cin >> tempPlace;
	addProduct.setPlaceinShop(tempPlace);

	cout << "Enter comment: " << endl;
	cin.ignore();
	cin.getline(temp, 128);
	addProduct.setComment(temp);

	modifications[modifSize].setInOrOut(1);

	storedProducts[size] = addProduct;
	modifSize++;
	size++;
	
	
	delete[]temp;
}
void Storage::removeProduct() {

}
void Storage::checkStock() {
	Date start;
	Date end;
	cout << "Enter start of period: " << endl;
	cin >> start;
	cout << "Enter end of period:" << endl;
	cin >> end;

	for (size_t i = 0; i < modifSize; i++) {
		//fix the check
		if (!(modifications[i].getModifDate() < start && modifications[i].getModifDate() > end)) {
			cout << "Product: " << modifications[i].getProduct() << endl;
			cout << "Modification date: " << modifications[i].getModifDate() << endl;
			cout << "Change: ";
			if (modifications[i].getInOrOut()) cout << "+";
			else cout << "-";
			cout << modifications[i].getQuantity() << endl;
		}
		else continue;
	}
}
void Storage::cleanUp() {
	Date cleanDate;
	Storage newStore;
	newStore.capacity = capacity;

	size_t newSize = size;
	cout << "Please enter clean up date: " << endl;
	cin >> cleanDate;
	size_t get = 0;
	for (size_t i = 0; i < size; i++) {
		if (storedProducts[i].getExpireDate() > cleanDate) {
			newStore.storedProducts[i] = storedProducts[get];
			++get;
		}
		else {
			newStore.storedProducts[i] = storedProducts[++get];
		}
		
	}
	delete[]storedProducts;
	storedProducts = newStore.storedProducts;
	newStore.storedProducts = nullptr;
	size--;

	//gotta make the date into a char*
	this->putInFile("DateCleanUp");

}
